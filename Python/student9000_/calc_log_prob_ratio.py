#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ENGG1811 21T3 Assignment 1 

Template file for calc_log_prob_ratio()

@author: 
"""

def calc_log_prob_ratio(measurement, conc_range, conc_var):
    # calculate log prob ratio and return it
    return (conc_range[1] - conc_range[0]) * (2 * measurement - sum(conc_range)) / (2 * conc_var);
