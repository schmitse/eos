import os
import eos
import json
import numpy as np
import yaml
import itertools


def convert_eos_ffs_to_flavio(fname_eos: str, fname_flavio: str, outname: str, overwrite: bool = True) -> None:
    if any([not os.path.exists(ff) for ff in [fname_eos, fname_flavio]]):
        raise FileNotFoundError(f"One of the files {fname_eos} or {fname_flavio} does not exist.")
    with open(fname_flavio, 'r') as fr:
        info_flavio = json.load(fr)
    with open(fname_eos, 'r') as fr:
        info_eos = yaml.load(fr, Loader=yaml.FullLoader)

    parameters_eos = [dd['name'] for dd in info_eos['parameters']]
    means_eos = info_eos['proposal']['components'][0]['mu']
    cov_eos = info_eos['proposal']['components'][0]['sigma']

    pars = ['A0', 'A1', 'A12', 'V', 'T1', 'T2', 'T23']
    coeffs = ['0', '1', '2']
    missing_coeffs = {'A12': '0', 'T2': '0'}

    means = info_flavio['central']
    uncertainties = info_flavio['uncertainty']
    correlations = info_flavio['correlation']
    covariances = info_flavio['covariance']
    for par in pars:
        for coeff in coeffs:
            if par in missing_coeffs:
                if coeff == missing_coeffs[par]:
                    continue
            par_eos = 'B_s->phi::alpha^' + par + f'_{coeff}@BSZ2015'
            index = parameters_eos.index(par_eos)
            means[par]['a'+coeff] = means_eos[index]
            uncertainties[par]['a'+coeff] = cov_eos[index][index]**0.5

    for parx, pary in itertools.product(pars, pars):
        for coeffx, coeffy in itertools.product(coeffs, coeffs):
            if parx in missing_coeffs and coeffx == missing_coeffs[parx]:
                continue
            if pary in missing_coeffs and coeffy == missing_coeffs[pary]:
                continue
            indx = parameters_eos.index('B_s->phi::alpha^' + parx + f'_{coeffx}@BSZ2015')
            indy = parameters_eos.index('B_s->phi::alpha^' + pary + f'_{coeffy}@BSZ2015')
            correlations[parx+pary]['a'+coeffx+'a'+coeffy] = (cov_eos[indx][indy]
                                                      / uncertainties[parx]['a'+coeffx] / uncertainties[pary]['a'+coeffy])
            covariances[parx+pary]['a'+coeffx+'a'+coeffy] = cov_eos[indx][indy]
    result = {
        'central': means, 'uncertainty': uncertainties, 'correlation': correlations, 'covariance': covariances
    }
    if os.path.exists(outname) and not overwrite:
        raise FileExistsError(f"File {outname} already exists.")
    with open(outname, 'w') as fw:
        json.dump(result, fw, indent=4)
    print(f"Converted EOS form factors from {fname_eos} to flavio format in {outname}.")
    return None


def load_flavio_ffs(fname: str, fname_eos: str, outname: str, overwrite: bool = True) -> None:
    if not os.path.exists(fname):
        raise FileNotFoundError(f"File {fname} does not exist.")
    with open(fname, 'r') as fr:
        ff_data = json.load(fr)
    if not os.path.exists(fname_eos):
        raise FileNotFoundError(f"File {fname_eos} does not exist.")
    with open(fname_eos, 'r') as fr:
        ff_data_eos = yaml.load(fr, Loader=yaml.FullLoader)

    # T1 and A12 do not have a parameter index 0 in eos but they do in flavio. 
    # i suppose that this just does not exist in eos and that there is no misalignment between the two. 

    parameter_order_eos = [dd['name'] for dd in ff_data_eos['parameters']]
    parameter_order_flavio = []
    means_flavio = []
    covariance_flavio = []
    for parameter_name, pdict in ff_data['central'].items():
        parameter_order_flavio += ['B_s->phi::alpha^' + parameter_name + f'_{sub_parameter[-1]}@BSZ2015' for sub_parameter in pdict.keys()]
        means_flavio += [val for _, val in pdict.items()]
        if parameter_name in ['A12', 'T1']:
            means_flavio.pop(parameter_order_flavio.index('B_s->phi::alpha^' + parameter_name + '_0@BSZ2015'))
            parameter_order_flavio.pop(parameter_order_flavio.index('B_s->phi::alpha^' + parameter_name + '_0@BSZ2015'))

    covariance_flavio = np.zeros((len(parameter_order_flavio), len(parameter_order_flavio)))
    for xx, parameter_x in enumerate(parameter_order_eos):
        for yy, parameter_y in enumerate(parameter_order_eos): 
            par_x = parameter_x.split('^')[-1].split('_')[0]
            par_y = parameter_y.split('^')[-1].split('_')[0]
            sub_par_x = 'a' + str(parameter_x.split('^')[-1].split('_')[-1].split('@')[0])
            sub_par_y = 'a' + str(parameter_y.split('^')[-1].split('_')[-1].split('@')[0])
            covariance_flavio[xx, yy] = ff_data['covariance'][par_x + par_y][sub_par_x + sub_par_y]

    ff_data_eos['proposal']['components'][0]['mu'] = means_flavio
    ff_data_eos['proposal']['components'][0]['sigma'] = covariance_flavio.tolist()

    if os.path.exists(outname) and not overwrite:
        raise FileExistsError(f"File {outname} already exists.")
    with open(outname, 'w') as fw:
        yaml.dump(ff_data_eos, fw, default_flow_style=False)

    return None


def main() -> None:

    # adjust to your favourite flavio installation if you want to play with the form-factors. 
    # flavio_ffs = '/Users/schmitse/Templates/flavio/flavio/physics/data/arXiv-1503-05534v2/Bsphi_LCSR-Lattice.json'
    # load_flavio_ffs(flavio_ffs, 'BsToPhi-local.yaml', 'BsToPhi-local-flavio.yaml')
    # convert_eos_ffs_to_flavio('BsToPhi-local.yaml', flavio_ffs, flavio_ffs.replace('arXiv-1503-05534v2', 'arXiv-2206-03797'))

    analysis_file = 'phimumu_predictions.yaml'
    form_factor_files = {
        'B_s->phi::BsToPhi-Nonlocal-FFs': 'BsToPhi-nonlocal-data.yaml', # - they actually dont exist? 
    }
    form_factor_parameter_files = {
        'B_s->phi::BsToPhi-Local-FFs': 'BsToPhi-local.yaml', 
        # 'B_s->phi::BsToPhi-Local-FFs': 'BsToPhi-local-flavio.yaml',         
        'B_s->phi::BsToPhi-hatH': 'BsToPhi-hatH.yaml', # had to modify the names a lot to make that work. 
    }
    # form_factor_files = {'None': 'BsToPhi_FormFactors_LCSRs.yaml'}
    for _name, _file in form_factor_files.items():
        insert_constraint(_file, constraint_name=_name)
    for _name, _file in form_factor_parameter_files.items():
        insert_parameters(_file, constraint_name=_name)
    
    EOS_BASE_DIRECTORY = './predictions-data/'
    posterior_name = 'BsToPhi-Posterior'
    observable_names = ['BsToPhi-Norm', 'BsToPhi-Si', 'BsToPhi-Ai', 'BsToPhi-Ki', 'BsToPhi-Wi', 'BsToPhi-Hi', 'BsToPhi-Zi']
    eos.tasks.sample_prior(analysis_file, posterior_name, base_directory=EOS_BASE_DIRECTORY, N=100, seed=42)
    for observable_name in observable_names:
        eos.tasks.predict_observables(analysis_file, posterior_name, observable_name, base_directory=EOS_BASE_DIRECTORY)
    return None


def insert_parameters(filename: str, constraint_name: str | None = None) -> None:
    if constraint_name == 'None':
        constraint_name = None
    if not os.path.exists(filename):
        raise FileNotFoundError(f"File {filename} does not exist.")
    with open(filename, 'r') as fr:
        ff_data = yaml.load(fr, Loader=yaml.FullLoader)        
    if constraint_name is None:
        constraint_name = list(ff_data.keys())[0]
    print(f'Adding parameters with name: {constraint_name}')
    means = ff_data['proposal']['components'][0]['mu']
    covariance = ff_data['proposal']['components'][0]['sigma']
    parameters = []
    for i, par_dict in enumerate(ff_data['parameters']):
        par_name = par_dict['name']
        print(f'Setting parameter: {par_name} to {means[i]:.6f}')
        eos.Parameters()[par_name].set(means[i])
        parameters.append(par_name)
    constraint_data = {
        'type': 'MultivariateGaussian(Covariance)',
        'kinematics': [{} for _ in range(len(means))],
        'options': [{} for _ in range(len(means))],
        'means': means,
        'observables': parameters,
        'covariance': covariance, 
    }
    eos.Constraints().insert(constraint_name, yaml.dump(constraint_data, stream=None))
    print(f'Added constraint with name: {constraint_name}')
    return None


def insert_constraint(filename: str, constraint_name: str | None = None) -> None:
    if constraint_name == 'None':
        constraint_name = None
    if not os.path.exists(filename):
        raise FileNotFoundError(f"File {filename} does not exist.")
    with open(filename, 'r') as fr:
        ff_data = yaml.load(fr, Loader=yaml.FullLoader)
    if constraint_name is None:
        constraint_name = list(ff_data.keys())[0]
        eos.Constraints().insert(constraint_name, yaml.dump(ff_data[constraint_name], stream=None))
    else:
        eos.Constraints().insert(constraint_name, yaml.dump(ff_data, stream=None))
    print(f'Added constraint with name: {constraint_name}')
    return None


if __name__ == "__main__":
    main()