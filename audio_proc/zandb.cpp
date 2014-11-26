#include <string.h>
#include <fstream>
#include <cmath>
#include "audioproc.h"
#include "ztrans.h"
#include <iostream>
#include "simpleproc.h"

int main() {
    sig in = read("audio/bendir2.wav");
//    sig in = read("dft_test.wav");
    sig dft_test = dft(in, 0);

    for(unsigned long int k=0; k<in.length; k++) {
        std::cout<<c_abs(in.rdata[k], in.idata[k])<<std::endl;
    }
//    printf("l: %li\n", dft_test.length);
/*
    sig output = idft(dft_test);
    for(unsigned long int i=0; i<output.length; i++) {
        printf("input: %f, output: %f, diff: %f\n", in.rdata[i], output.rdata[i], output.rdata[i]-in.rdata[i]);
    }
    write("dft_output.wav", output);
    
/*
    for(unsigned long int i=0; i<dft_test.length/2; i++) {
        double rdat = dft_test.rdata[i];
        double idat = dft_test.idata[i];
        std::cout<<std::sqrt((rdat*rdat)+(idat*idat))<<std::endl;

    }
    /*
    sig out;
    out.chn_num = 1;
    out.fs = 44100;
    double rdata[8];
    double idata[8];
    for(int i=0; i<8; i++) {
        rdata[i] = std::pow(-1, i % 2);
        idata[i] = 0;
    }
    out.rdata = rdata;
    out.idata = idata;
    out.length = 8;
	*/
    return 0;
}
