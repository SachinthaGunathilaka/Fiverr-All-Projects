#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ENGG1811 21T3 Assignment 1 

Template file for calc_signal_log_prob_ratio()

@author: 
"""

def calc_signal_log_prob_ratio(conc_signal, conc_range, conc_var):
    import calc_log_prob_ratio as clpr
    log_prob_ratios = []
    # Calculate log prob ratio for each value in conc_signal
    for value in conc_signal:
        log_prob_ratios.append(clpr.calc_log_prob_ratio(value, conc_range, conc_var))

    return log_prob_ratios # return all log prob values
