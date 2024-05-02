#include <stdio.h>
#include "fic_wave.h"

FILE    *abre_wave(const char *ficWave, float *fm, int *numCan, int *bitsSample) {
    FILE    *fpWave;
    int frecuencia, numCanales, bitsPorSample;

    if ((fpWave = fopen(ficWave, "r")) == NULL) return NULL;

    fseek(fpWave, 24, SEEK_SET);
    fread(&frecuencia, 4, 1, fpWave);
    *fm = frecuencia;

    fseek(fpWave, 22, SEEK_SET);
    fread(&numCanales, 2, 1, fpWave);
    *numCan = numCanales;

    fseek(fpWave, 34, SEEK_SET);
    fread(&bitsPorSample, 2, 1, fpWave);
    *bitsSample = bitsPorSample;

    if (fseek(fpWave, 44, SEEK_SET) < 0) return NULL;
    fseek(fpWave, 44, SEEK_SET);
    return fpWave;
}

size_t   lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
    return fread(x, size, nmemb, fpWave);
}

void    cierra_wave(FILE *fpWave) {
    fclose(fpWave);
}


