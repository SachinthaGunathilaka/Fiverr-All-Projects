#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ENGG1811 21T3 Assignment 1 

Template file for detect_fault_main

@author: 
"""


def detect_fault_main(conc_signal, conc_range, conc_var, conc_cusum_limit,
                      flow_signal, flow_range, flow_control_window):
    import classify_fault as classify

    # check for validity of the conc_range and flow_range
    if len(conc_range) != 2 or conc_range[1] <= conc_range[0] or len(flow_range) != 2 or flow_range[1] <= flow_range[0]:
        return "invalid parameters"

    # check for validity of the conc_avr and conc_cusum_limit
    elif conc_var <= 0 or conc_cusum_limit <= 0:
        return "invalid parameters"

    # check validity of the flow_control_window
    elif type(flow_control_window) != type(1) or flow_control_window <= 0:
        return "invalid parameters"

    # call classify_fault function and return the result
    return classify.classify_fault(conc_signal, conc_range, conc_var, conc_cusum_limit,
                                   flow_signal, flow_range, flow_control_window)
