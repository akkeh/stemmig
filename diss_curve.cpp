#include <fstream>
#include <cmath>
#include "audio_proc/audioproc.h"
#include "audio_proc/ztrans.h"
#include "audio_proc/simpleproc.h"
/*
struct sig {                // struct sig to contain 2 data arrays 
    double* rdata;
    double* idata;   //  real and imag data
    unsigned long length;   //  length of arrays
}; 
*/

double* get_mag(struct sig* X) {                // get magnitude of 
                                                //  complex signal
    unsigned long length = (*X).length;            //  get length
    double* mX = new double[length];            //  create mX array
    for(unsigned long int k=0; k<length; k++) {     //  iterate trough signals
        mX[k] = c_abs((*X).rdata[k], (*X).idata[k]);  //  use c_abs() for mag
    }
    return mX;                                  //  return array
}   // get_mag()

struct sig find_peaks(struct sig* X) {          // find peaks in mag.spect
    unsigned long length = (*X).length;            //  get length
    double* peak_f = new double[length];        //  init. array for peak 
                                                //  frequencies
    double* mX = get_mag(X);                    //  get mag.spect.
    unsigned long peak_c = 0;                   //  counter for peaks
    for(int k=1; k<length-1; k++) {             //  iterate trough mag.spect
        if((mX[k] > mX[k-1]) && (mX[k] > mX[k+1])) {    //  is there a peak?
            peak_f[peak_c] = k;                 //  add peak to peak_f[]
            peak_c++;                           //  increment peak counter
        }
    }
    double* peak_a = new double[peak_c];        // init array for peak ampl 
    for(int i=0; i<peak_c; i++) {               //  add ampl. of peaks
        peak_a[i] = mX[(int)peak_f[i]]; 
    }

    sig peaks;                                  //  init output signal
    peaks.rdata = peak_f;                       //  rdata = peak frequencies
    peaks.idata = peak_a;                       //  idata = peak ampl.
    peaks.length = peak_c;                      //  count of peaks
    
    return peaks; //rdata = peak freqs; idata = peak ampl
}   //  find_peaks()



int main() {
    unsigned long N = 8;
    double x[N];
    
    for(int i=0; i<N; i++) {
        x[i] = 0;
    }    
    x[4] = 1;
    x[7] = 1;
        
    sig in;
    in.rdata = x;
    in.length = N;
    sig X = dft(in);    

    sig yolo = find_peaks(&X);
    for(int i=0; i<yolo.length; i++) {
        printf("prt: %i,\tfreq:\t%f,\tampl: %f\n", i, yolo.rdata[i], yolo.idata[i]);
    }    
    
    return 0;
} 
