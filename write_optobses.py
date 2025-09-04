import itertools


obses = ['M', 'Q']
indices = ['1s', '1c', '2s', '2c', '3', '4', '5', '6s', '7', '8', '9']

opt_obs = ['SP', 'AP', 'KP', 'WP']
opt_ind = ['1', '2', '3', '4p', '5p', '6p', '8p']

our_prime = ['M', 'Q']
our_prime_ind = ['4p', '5p', '7p', '8p']

other = ['SS', 'KS', 'WS', 'AS', ]

def numerator(obs: str, index: str) -> str:
    numerators = {
        'M1c': '-1.0 * ',
        'M2c': '-1.0 * ',
        'M3': '0.5 * ',
        'M4': '-1.0 * ',
        'M6s': '0.5 * ',
        'M7': '-1.0 * ',
        'M9': '0.5 * ',
        'M5p': '0.5 * ',
        'M7p': '-0.5 * ',
        'SP1': '0.5 * ',
        'SP2': '0.125 * ',
        'SP3': '0.25 * ',
        'SP5p': '0.5 * ',
        'SP6p': '-0.5 * ',
        'KP1': '0.5 * ',
        'KP2': '0.125 * ',
        'KP3': '0.25 * ',
        'KP5p': '0.5 * ',
        'KP6p': '-0.5 * ',
    }
    numerators.update({
        key.replace('M', 'Q'): val for key, val in numerators.items() if key.startswith('M')
    })
    numerators.update({
        key.replace('SP', 'AP'): val for key, val in numerators.items() if key.startswith('SP')
    })
    numerators.update({
        key.replace('KP', 'WP'): val for key, val in numerators.items() if key.startswith('KP')
    })
    if f'{obs}{index}' in numerators:
        return numerators[f'{obs}{index}']
    return ''

def denominator(obs: str, index: str) -> str:
    denoms = {
        'M1c': '<<B_s->phill::K_2c@LHCb>>',
        'M2c': '<<B_s->phill::K_2c@LHCb>>',
        'M1s': '<<B_s->phill::K_2s@LHCb>>',
        'M2s': '<<B_s->phill::K_2s@LHCb>>',
        'M3': '<<B_s->phill::K_2s@LHCb>>',
        'M4': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5',
        'M5': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5',
        'M6s': '<<B_s->phill::K_2s@LHCb>>',
        'M7': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5',
        'M8': '(-2.0 * <<B_s->phill::K_2c@LHCb>> * (2.0 * <<B_s->phill::K_2s@LHCb>> - <<B_s->phill::K_3@LHCb>>) ) ^ 0.5',
        'M9': '<<B_s->phill::K_2s@LHCb>>',
        'M4p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'M5p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'M7p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'M8p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'SP1': '<<B_s->phill::S_2s@LHCb>>',
        'SP2': '<<B_s->phill::S_2s@LHCb>>',
        'SP3': '<<B_s->phill::S_2s@LHCb>>',
        'SS': '<<B_s->phill::S_2s@LHCb>>',
        'AS': '<<B_s->phill::S_2s@LHCb>>',
        'KS': '<<B_s->phill::K_2s@LHCb>>',
        'WS': '<<B_s->phill::K_2s@LHCb>>',
        'KP1': '<<B_s->phill::K_2s@LHCb>>',
        'KP2': '<<B_s->phill::K_2s@LHCb>>',
        'KP3': '<<B_s->phill::K_2s@LHCb>>',
        'SP4p': '(-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5',
        'SP5p': '(-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5',
        'SP6p': '(-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5',
        'SP8p': '(-1.0 * <<B_s->phill::S_2c@LHCb>> * <<B_s->phill::S_2s@LHCb>>) ^ 0.5',
        'KP4p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'KP5p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'KP6p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
        'KP8p': '(-1.0 * <<B_s->phill::K_2c@LHCb>> * <<B_s->phill::K_2s@LHCb>>) ^ 0.5',
    }
    denoms.update({
        key.replace('M', 'Q'): value for key, value in denoms.items() if key.startswith('M')
    })
    denoms.update({
        key.replace('SP', 'AP'): value for key, value in denoms.items() if key.startswith('SP')
    })
    denoms.update({
        key.replace('KP', 'WP'): value for key, value in denoms.items() if key.startswith('KP')
    })
    return denoms[f'{obs}{index}']


def orig_obs(obs: str) -> str:
    obs_conversion = {
        'M': 'H',
        'Q': 'Z',
        'SP': 'S',
        'AP': 'A',
        'KP': 'K',
        'WP': 'W',
        'SS': 'S',
        'AS': 'A',
        'KS': 'K',
        'WS': 'W',
    }
    return obs_conversion.get(obs, obs)


def orig_index(obs: str, index: str) -> str:
    if obs in ['M', 'Q'] and not index.endswith('p'):
        return index
    index_conversion = {
        'SP1': '3',
        'SP2': '6s',
        'SP3': '9',
        'SP4p': '4',
        'SP5p': '5',
        'SP6p': '7',
        'SP8p': '8',
        'M4p': '4',
        'M5p': '5',
        'M7p': '7',
        'M8p': '8',
    }
    index_conversion.update({
        key.replace('S', 'K'): value for key, value in index_conversion.items() if key.startswith('SP')
    })
    index_conversion.update({
        key.replace('S', 'A'): value for key, value in index_conversion.items() if key.startswith('SP')
    })
    index_conversion.update({
        key.replace('S', 'W'): value for key, value in index_conversion.items() if key.startswith('SP')
    })
    index_conversion.update({
        key.replace('M', 'Q'): value for key, value in index_conversion.items() if key.startswith('M')
    })
    index_conversion.update({
        'SS': '6c',
        'KS': '6c',
        'WS': '6c',
        'AS': '6c'
    })
    return index_conversion.get(f'{obs}{index}', index)


def observable_expression(obs: str, index: str) -> str:
    orig_obs_ = orig_obs(obs)
    orig_index_ = orig_index(obs, index)
    denom_ = denominator(obs, index)
    denom_q2 = denom_.replace('@LHCb', '(q2)@LHCb')
    num = numerator(obs, index)
    obs += '_' if obs not in ['SS', 'KS', 'WS', 'AS'] else ''
    text = fr"""
make_expression_observable("B_s->phill::{obs}{index}(q2)@LHCb", R"({obs}{{{index}}}(\bar{{B}}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "({num}<<B_s->phill::{orig_obs_}_{orig_index_}(q2)@LHCb>> / ({denom_q2}) )"),
make_expression_observable("B_s->phill::{obs}{index}@LHCb", R"({obs}{{{index}}}(\bar{{B}}_s\to \phi\ell^+\ell^-))",
                           Unit::None(),
                           "({num}<<B_s->phill::{orig_obs_}_{orig_index_}@LHCb>> / ({denom_}) )"),
"""
    return text


with open('obses_optimised.cxx', 'w') as fw:
    for obs, index in itertools.product(obses, indices):
        fw.write(observable_expression(obs, index))
        fw.write('\n')
    for obs, index in itertools.product(opt_obs, opt_ind):
        fw.write(observable_expression(obs, index))
        fw.write('\n')
    for obs, index in itertools.product(our_prime, our_prime_ind):
        fw.write(observable_expression(obs, index))
        fw.write('\n')
    for obs in other:
        fw.write(observable_expression(obs, ''))
        fw.write('\n')
