#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ENGG1811 21T3 Assignment 1 

Template file for classify_fault()

@author: 
"""
import math


def classify_fault(conc_signal, conc_range, conc_var, conc_cusum_limit,
                   flow_signal, flow_range, flow_control_window):
    import calc_signal_log_prob_ratio as cslpr
    import cusum as cs
    import detect_fault_in_conc as detect

    # call previously defined functions
    conc_lpr = cslpr.calc_signal_log_prob_ratio(conc_signal, conc_range, conc_var)
    conc_cusum = cs.cusum(conc_lpr)
    time, _ = detect.detect_fault_in_conc(conc_cusum, conc_cusum_limit)

    # check whether concentration signal indicates a fault
    conc_fault = time != math.inf

    # check whether flow control has a fault
    flow_fault = False
    if conc_fault:
        # compute the average of a number of consecutive entries in flow_signal
        flow_sum = 0
        for i in range(time, time - flow_control_window, -1):
            flow_sum += flow_signal[i]
        flow_average = flow_sum / flow_control_window

        # check whether average value not in the flow range
        flow_fault = flow_average < flow_range[0] or flow_average > flow_range[1]

    # return message including the faults
    if conc_fault and flow_fault:
        return "flow and conc faults"
    elif conc_fault:
        return "conc fault only"
    else:
        return "no faults"
