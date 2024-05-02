#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float power = 0;
    int i;
    for(i=0;i<N;i++){
        power += (x[i]*x[i]);
    }
    return log10(power/N)*10;
}

float compute_autocorrelacion(const float *x, float *r, unsigned int N){
    for (int i = 0; i < N; i++){
        r[i] = 0;
        for(int j=0; j < N - i; j++){
            r[i] += x[j]+x[j+i];
        }
    }

}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int zcr = 0;
    int i;
    for(i=1;i<N;i++){
        if(x[i]*x[i-1]<0){
            zcr ++;
        }
    }
    return (fm/2*(N-1))*zcr;
}
