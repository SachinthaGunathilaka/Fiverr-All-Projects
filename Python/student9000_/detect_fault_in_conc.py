#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ENGG1811 21T3 Assignment 1 

Template file for detect_fault_in_conc

@author: 
"""
import math

def detect_fault_in_conc(conc_cusum, conc_cusum_limit):
    time = math.inf # Initially set time to infinity
    entries = 0

    # Iterate through each value in conc_cusum
    for i in range(len(conc_cusum) - 1, -1, -1):
        # If the value exceeds the conc_cusum_limit increment number of entries by 1 and update time
        if conc_cusum[i] >= conc_cusum_limit:
            entries += 1
            time = i

    # return time and number of entries
    return time, entries
