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

    return None


if __name__ == "__main__":
    main()
