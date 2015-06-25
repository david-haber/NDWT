//
//  wavelet.h
//  sleep-processing
//
//  Created by David Haber and Florian Gardin on 4/15/15.
//  Copyright (c) 2015 David Haber and Florian Gardin. All rights reserved.
//

#ifndef __sleep_processing__wavelet__
#define __sleep_processing__wavelet__

#include <stdio.h>

#if defined __cplusplus
extern "C" {
#endif

//
// The non-decimated DWT (NDWT) contains all possible shifted versions of the DWT.
//
//  signal: array (1xn) of doubles where n is a power of 2
//
//  uses Haar wavelet (filter.number=1, family="DaubExPhase")
//  uses non-decimated wavelet transform (type="station")	
//  assumes signal is periodic on the defined interval
//

// INPUT:   signal:     array (1xn) of doubles where n is a power of 2
// OUTPUT:  c:          log(n) x n matrix of double data coefficients
//          w:          log(n) x n matrix of double wavelet coefficients
void transform(double* signal, int n_input, double** c, double** w);
    
#if defined __cplusplus
};
#endif

#endif /* defined(__sleep_processing__wavelet__) */
