//
//  wavelet.c
//  sleep-processing
//
//  Created by David Haber and Florian Gardin on 4/15/15.
//  Copyright (c) 2015 David Haber and Florian Gardin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "wavelet.h"
#include "math.h"


int two_pow(int exp)
{
    assert(exp >= 0);
    
    if (exp == 0)
    {
        return 1;
    }
    return 2 << (exp-1);
}


void transform(double* signal, int n_input, double** c, double** w)
{   
    int n = n_input;
    int m = (int)log2(n);
    
    // Normalized Haar wavelet filter
    const double h[2] = {1.0/sqrt(2.0) * 1.0, 1.0/sqrt(2.0) * 1.0};
    const double g[2] = {1.0/sqrt(2.0) * 1.0, - 1.0/sqrt(2.0) * 1.0};
    
    // compute c_0
    for (int i = 0; i < n; i++) {
        c[0][i] = signal[i];
        w[0][i] = 0.0;
    }
    
    // compute c_1..log_2(n) and w_1..log_2(n) using "a trous algorithm"
    for (int j = 0; j <  m; j++)
    {
        for (int l = 0; l < n; l++)
        {
            c[j+1][l] = 0.0;
            w[j+1][l] = 0.0;
            for (int k = 0; k < 2; k++)
            {
                int index = (l + two_pow(j) * k) % n;
                c[j+1][l] += h[k] * c[j][index];
                w[j+1][l] += g[k] * c[j][index];
            }
        }
    }
}