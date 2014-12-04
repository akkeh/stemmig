#include <sndfile.h>
#include <fstream>
#include <cmath>
#include "../JuceLibraryCode/JuceHeader.h"

int loadfile(const juce::String filepath, double* data, unsigned long int N) {
    int err = -1;

    SF_INFO in_info;
    SNDFILE* in_file;
    int i=0;
    while(filepath[i] != '\0') {
        printf("outp: %c\n", filepath[i]);
        i++;
    }
    char* fp; 
    i = 0;
    while(filepath[i] != '\0') {
        fp[i] = (const char) filepath[i];
        i++;
    }
    in_file = sf_open(fp, SFM_READ, &in_info);

    err = 0;
    exit:
    return err;
} 
