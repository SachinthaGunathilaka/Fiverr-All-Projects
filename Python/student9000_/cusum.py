#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ENGG1811 21T3 Assignment 1 

Template file for cusum()

@author: 
"""


def cusum(conc_lpr):
    conc_cusum = []
    # calculate first value in conc_cusum
    if conc_lpr[0] < 0:
        conc_cusum.append(0)
    else:
        conc_cusum.append(conc_lpr[0])

    # calculate other values in conc_cusum
    for i in range(1, len(conc_lpr)):
        # if the calculated value is negative replace it by 0
        if conc_cusum[i - 1] + conc_lpr[i] < 0:
            conc_cusum.append(0)
        else:
            conc_cusum.append(conc_cusum[i - 1] + conc_lpr[i])

    return conc_cusum
