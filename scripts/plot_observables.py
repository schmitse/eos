import os
import yaml
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
from numpy.typing import NDArray


def load_eos(posterior_name: str) -> dict[str, NDArray | dict[tuple[float], tuple[float]]]:
    result = {}
    observable_groups = [f'BsToPhi-{obs}i' for obs in ['K', 'S', 'W', 'A', 'H', 'Z']] + ['BsToPhi-Norm']
    path = os.path.join('predictions-data/', posterior_name)
    for group in observable_groups:
        yaml_name = os.path.join(path, f'pred-{group}', 'description.yaml')
        samples_name = os.path.join(path, f'pred-{group}', 'samples.npy')
        with open(yaml_name, 'r') as fr:
            desc = yaml.load(fr, Loader=yaml.FullLoader)['observables']
        samples = np.load(samples_name)
        for i, obs_dict in enumerate(desc):
            # i would have loved to match the structure of the kinematics dictionary... but added in 3.10...
            if '(q2)' not in obs_dict['name']:
                observable = '<' + obs_dict['name'].replace('B_s->phill::', '').replace('(q2)', '').replace('@LHCb', '').replace('_', '') + '>'
                q2_range = (obs_dict['kinematics']['q2_min'], obs_dict['kinematics']['q2_max'])
                if observable not in result:
                    result[observable] = {q2_range: (samples[:,i].mean(), samples[:,i].std())}
                else:
                    result[observable][q2_range] = (samples[:,i].mean(), samples[:,i].std())
            else:
                observable = obs_dict['name'].replace('B_s->phill::', '').replace('(q2)', '').replace('@LHCb', '').replace('_', '')
                if observable not in result:
                    result[observable] = [samples[:,i].mean()]
                    result[f's_{observable}'] = [samples[:,i].std()]
                else:
                    result[observable].append(samples[:,i].mean())
                    result[f's_{observable}'].append(samples[:,i].std())
                if 'qsq_array' not in result:
                    if 'q2' in obs_dict['kinematics']:
                        result['qsq_array'] = [obs_dict['kinematics']['q2']]
                else:
                    if 'q2' in obs_dict['kinematics']:
                        result['qsq_array'].append(obs_dict['kinematics']['q2'])
    result['qsq_array'] = list(dict.fromkeys(result['qsq_array']))
    result.update({key: np.asarray(value) for key, value in result.items() if isinstance(value, list)})
    return result


def read_eos_obs(dict: dict[tuple[float], tuple[float]]) -> tuple[NDArray]:
    x, y, = [], []
    xerr, yerr = [], []
    for q2_range, (mean, std) in dict.items():
        x.append((q2_range[0] + q2_range[1]) / 2)
        xerr.append((q2_range[1] - q2_range[0]) / 2)
        y.append(mean)
        yerr.append(std)
    return tuple(map(np.asarray, (x, xerr, y, yerr)))


def main() -> None:
    mpl.rc_file('schmitse-rc.rc')

    results = {}
    posterior_names = [f'BsToPhi-Posterior{name}' for name in ['', '-rc9m1', '-ic9m1']]

    results['SM'] = load_eos(posterior_names[0])
    results['ReC9m1'] = load_eos(posterior_names[1])
    results['ImC9m1'] = load_eos(posterior_names[2])

    observables = list(results['SM'].keys())

    colors = {'SM': 'blue', 'ReC9m1': 'orange', 'ImC9m1': 'green'}
    linestyles = {'SM': '-', 'ReC9m1': '--', 'ImC9m1': '-.'}
    markers = {'SM': 'o', 'ReC9m1': '*', 'ImC9m1': 's'}
    labels = {'SM': 'SM', 'ReC9m1': r'$\Delta\mathcal{R}\{C_9\} = -1$', 'ImC9m1': r'$\Delta\mathcal{I}\{C_9\} = -1$'}

    for obs in observables:
        if obs == 'qsq_array':
            continue
        if '<' in obs:
            continue
        if obs.startswith('s_'):
            continue
        fig, ax = plt.subplots()
        for scenario in colors:
            ax.plot(results[scenario]['qsq_array'], results[scenario][obs], label=labels[scenario], color=colors[scenario], linestyle=linestyles[scenario])
            ax.fill_between(results[scenario]['qsq_array'], results[scenario][obs]-results[scenario][f's_{obs}'], 
                            results[scenario][obs]+results[scenario][f's_{obs}'], 
                            color=colors[scenario], alpha=0.25, linestyle=linestyles[scenario])
            x, xerr, y, yerr = read_eos_obs(results[scenario][f'<{obs}>'])
            norm = np.ones_like(y) if obs != 'Gamma' else xerr * 2
            ax.errorbar(x, y/norm, xerr=xerr, yerr=yerr/norm, fmt=markers[scenario], color=colors[scenario], alpha=0.75)
        ax.legend()
        ax.set_xlabel(r'$q^2$ [GeV$^2/c^4$]')
        ax.set_ylabel('$'+ obs[0] + '_{' + obs[1:] + '}$')
        fig.savefig(f'plots/{obs}.pdf', bbox_inches='tight', transparent=True)
        print(f'saved plots/{obs}.pdf')
        plt.close(fig)
    return 


if __name__ == "__main__":
    main()