#include <sndfile.h>
#include <fstream>
#include <cmath>
#include "../JuceLibraryCode/JuceHeader.h"

int loadfile(const juce::String filepath, float* data, unsigned long int* N, int* ch, int* fs) {
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
    *fs = in_info.samplerate;
    unsigned long int num_frames = in_info.frames;
    int chn_num = in_info.channels;

    float buf[num_frames*chn_num];
    printf("\npoint!\n");
    unsigned long int frames_read = sf_readf_float(in_file, buf, num_frames);
    if(frames_read != num_frames) {
        printf("\nerror read: %li of %li\n", frames_read, num_frames);
    }    
    *N = num_frames;
    *ch = chn_num;
    printf("writing float\n");
    data = new float[num_frames*chn_num];
    for(unsigned long int n=0; n<num_frames*chn_num; n++) {
        data[n] = buf[n];
    }
    err = 0;
    exit:
    return err;
} 
