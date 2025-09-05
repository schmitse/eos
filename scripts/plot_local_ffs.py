import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
import yaml
import re
from uncertainties import correlated_values


def latex_par_name(name: str) -> str:
    coeff, index = name.split('_')
    coeff, subdex = coeff[0], coeff[1:]
    return f'${coeff}_{{{subdex}}}^{{{index}}}$'


def latex_par_name_magic(name: str) -> str:
    return re.sub(r'([A-Z])(\d*)_(\d+)', r'$\1_{\2}^{\3}$', name)


def main() -> None:
    mpl.rc_file('schmitse-rc.rc')

    with open('GRvDV2022/BToKstar-local.yaml', 'r') as f:
        kst_ffs = yaml.safe_load(f)
    with open('GRvDV2022/BsToPhi-local.yaml', 'r') as f:
        phi_ffs = yaml.safe_load(f)

    par_names_kst = [p['name'].replace('B->K^*::alpha^', '').replace('@BSZ2015', '') 
                     for p in kst_ffs['parameters']]
    par_names_kst = list(map(latex_par_name, par_names_kst))
    par_values_kst = np.array(kst_ffs['proposal']['components'][0]['mu'])
    par_covs_kst = np.array(kst_ffs['proposal']['components'][0]['sigma'])
    par_names_phi = [p['name'].replace('B_s->phi::alpha^', '').replace('@BSZ2015', '') 
                     for p in phi_ffs['parameters']]
    par_names_phi = list(map(latex_par_name_magic, par_names_phi))
    par_values_phi = np.array(phi_ffs['proposal']['components'][0]['mu'])
    par_covs_phi = np.array(phi_ffs['proposal']['components'][0]['sigma'])
    corr_vals_phi = correlated_values(par_values_phi, par_covs_phi)
    corr_vals_kst = correlated_values(par_values_kst, par_covs_kst)

    kst_vals = {name: val for name, val in zip(par_names_kst, corr_vals_kst)}
    phi_vals = {name: val for name, val in zip(par_names_phi, corr_vals_phi)}
    factors = {name: v2.s/v1.s for name, v1, v2 in zip(par_names_kst, corr_vals_kst, corr_vals_phi)}

    print({k: f'{v}' for k, v in phi_vals.items()})
    print({k: f'{v}' for k, v in kst_vals.items()})
    print({k: f'{v2.s/v1.s:.3f}' for k, v1, v2 in zip(par_names_kst, corr_vals_kst, corr_vals_phi)})

    fig, ax = plt.subplots()

    ax.errorbar(np.array(range(len(par_names_kst))) - 0.2, [v.n for v in kst_vals.values()], 
                yerr=[v.s for v in kst_vals.values()],
                fmt='o', label=r'$B\to K^*$ form factors', color='blue')
    ax.errorbar(np.array(range(len(par_names_phi))) + 0.2, [v.n for v in phi_vals.values()], 
                yerr=[v.s for v in phi_vals.values()],
                fmt='o', label=r'$B_s\to \phi$ form factors', color='orange')
    ax.set_xticks(range(len(par_names_kst)))
    ax.set_xticklabels(par_names_kst)

    for j in range(len(par_names_kst)):
        if j % 2 == 1:
            ax.axvspan(j-0.5, j+0.5, color='gray', alpha=0.25)

    ax.legend(loc='best')
    fig.savefig('plots/local_ffs.pdf', bbox_inches='tight', transparent=True)
    print('saved plots/local_ffs.pdf')
    plt.close(fig)

    fig, ax = plt.subplots()

    ax.scatter(np.array(range(len(par_names_kst))), [v for v in factors.values()], 
               marker='o', color='blue')
    ax.set_xticks(range(len(par_names_kst)))
    ax.set_xticklabels(par_names_kst)
    ax.set_ylabel(r'$\sigma(B_s\rightarrow \phi) / \sigma(B\rightarrow K^{\ast 0}(892))$')

    for j in range(len(par_names_kst)):
        if j % 2 == 1:
            ax.axvspan(j-0.5, j+0.5, color='gray', alpha=0.25)

    fig.savefig('plots/local_ffs_uncratio.pdf', bbox_inches='tight', transparent=True)
    print('saved plots/local_ffs_uncratio.pdf')
    plt.close(fig)

    with open('GRvDV2023/BSZ-parameters-N2.yaml', 'r') as f:
        bsz_ffs = yaml.load(f, Loader=yaml.FullLoader)

    phi_pars = bsz_ffs['B_s->phi::FormFactors[parametric,BSZ]@GRvDV:2023A']
    kst_pars = bsz_ffs['B->K^*::FormFactors[parametric,BSZ]@GRvDV:2023A']

    phi_names = list(map(latex_par_name_magic, [
        p.replace('B_s->phi::alpha^', '').replace('@BSZ2015', '') for p in phi_pars['observables']]))
    kst_names = list(map(latex_par_name_magic, [
        p.replace('B->K^*::alpha^', '').replace('@BSZ2015', '') for p in kst_pars['observables']]))
    phi_vals = np.array(phi_pars['means'])
    kst_vals = np.array(kst_pars['means'])

    phi_cov = np.array(phi_pars['covariance'])
    kst_cov = np.array(kst_pars['covariance'])
    phi_corr = correlated_values(phi_vals, phi_cov)
    kst_corr = correlated_values(kst_vals, kst_cov)
    factors = {name: v2.s/v1.s for name, v1, v2 in zip(kst_names, kst_corr, phi_corr)}

    kst_vals = {name: val for name, val in zip(kst_names, kst_corr)}
    phi_vals = {name: val for name, val in zip(phi_names, phi_corr)}

    fig, ax = plt.subplots()
    ax.errorbar(np.array(range(len(par_names_kst))) - 0.2, [v.n for v in kst_vals.values()], 
                yerr=[v.s for v in kst_vals.values()],
                fmt='o', label=r'$B\to K^*$ form factors', color='blue')
    ax.errorbar(np.array(range(len(par_names_phi))) + 0.2, [v.n for v in phi_vals.values()], 
                yerr=[v.s for v in phi_vals.values()],
                fmt='o', label=r'$B_s\to \phi$ form factors', color='orange')
    ax.set_xticks(range(len(par_names_kst)))
    ax.set_xticklabels(par_names_kst)

    for j in range(len(par_names_kst)):
        if j % 2 == 1:
            ax.axvspan(j-0.5, j+0.5, color='gray', alpha=0.25)

    ax.legend(loc='best')
    fig.savefig('plots/local_ffs_2023.pdf', bbox_inches='tight', transparent=True)
    print('saved plots/local_ffs_2023.pdf')
    plt.close(fig)
    fig, ax = plt.subplots()

    ax.scatter(np.array(range(len(par_names_kst))), [v for v in factors.values()], 
               marker='o', color='blue')
    ax.set_xticks(range(len(par_names_kst)))
    ax.set_xticklabels(par_names_kst)
    ax.set_ylabel(r'$\sigma(B_s\rightarrow \phi) / \sigma(B\rightarrow K^{\ast 0}(892))$')

    for j in range(len(par_names_kst)):
        if j % 2 == 1:
            ax.axvspan(j-0.5, j+0.5, color='gray', alpha=0.25)

    fig.savefig('plots/local_ffs_uncratio_2023.pdf', bbox_inches='tight', transparent=True)
    print('saved plots/local_ffs_uncratio_2023.pdf')
    plt.close(fig)

    with open('GRvDV2023/GRvDV-parameters-N2.yaml', 'r') as f:
        bfw_ffs = yaml.load(f, Loader=yaml.FullLoader)

    phi_pars = bfw_ffs['B_s->phi::FormFactors[parametric,BFW]@GRvDV:2023A']
    kst_pars = bfw_ffs['B->K^*::FormFactors[parametric,BFW]@GRvDV:2023A']

    phi_names = list(map(latex_par_name_magic, [
        p.replace('B_s->phi::a^', '').replace('@BFW2010', '') for p in phi_pars['observables']]))
    kst_names = list(map(latex_par_name_magic, [
        p.replace('B->K^*::a^', '').replace('@BFW2010', '') for p in kst_pars['observables']]))
    phi_vals = np.array(phi_pars['means'])
    kst_vals = np.array(kst_pars['means'])

    phi_cov = np.array(phi_pars['covariance'])
    kst_cov = np.array(kst_pars['covariance'])
    phi_corr = correlated_values(phi_vals, phi_cov)
    kst_corr = correlated_values(kst_vals, kst_cov)
    factors = {name: v2.s/v1.s for name, v1, v2 in zip(kst_names, kst_corr, phi_corr)}

    kst_vals = {name: val for name, val in zip(kst_names, kst_corr)}
    phi_vals = {name: val for name, val in zip(phi_names, phi_corr)}

    fig, ax = plt.subplots()
    ax.errorbar(np.array(range(len(kst_names))) - 0.2, [v.n for v in kst_vals.values()], 
                yerr=[v.s for v in kst_vals.values()],
                fmt='o', label=r'$B\to K^*$ form factors', color='blue')
    ax.errorbar(np.array(range(len(phi_names))) + 0.2, [v.n for v in phi_vals.values()], 
                yerr=[v.s for v in phi_vals.values()],
                fmt='o', label=r'$B_s\to \phi$ form factors', color='orange')
    ax.set_xticks(range(len(kst_names)))
    ax.set_xticklabels(kst_names)

    for j in range(len(kst_names)):
        if j % 2 == 1:
            ax.axvspan(j-0.5, j+0.5, color='gray', alpha=0.25)

    ax.legend(loc='best')
    fig.savefig('plots/local_ffs_2023_BFW.pdf', bbox_inches='tight', transparent=True)
    print('saved plots/local_ffs_2023_BFW.pdf')
    plt.close(fig)
    fig, ax = plt.subplots()

    ax.scatter(np.array(range(len(kst_names))), [v for v in factors.values()], 
               marker='o', color='blue')
    ax.set_xticks(range(len(kst_names)))
    ax.set_xticklabels(kst_names)
    ax.set_ylabel(r'$\sigma(B_s\rightarrow \phi) / \sigma(B\rightarrow K^{\ast 0}(892))$')

    for j in range(len(kst_names)):
        if j % 2 == 1:
            ax.axvspan(j-0.5, j+0.5, color='gray', alpha=0.25)

    fig.savefig('plots/local_ffs_uncratio_2023_BFW.pdf', bbox_inches='tight', transparent=True)
    print('saved plots/local_ffs_uncratio_2023_BFW.pdf')
    plt.close(fig)



    return None


if __name__ == "__main__":
    main()
