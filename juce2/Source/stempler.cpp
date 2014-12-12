#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include "stempler.h"

tuning::tuning(float* mX, long N, int n_keys, bool mirror, float tresh) {	// calculate tuning:
	float* peaks = get_peaks(mX, N, true, tresh);		//	1: find peaks in spectrum
	for(long k=0; k<N; k++) {
		if(peaks[k] > 0) {
			//std::cout<<"bin: "<<k<<" val: "<<peaks[k]<<std::endl;
		}
	}
										//	2: 
										//	3: calculate dissonance-curve
										//	4: sort intervals on amount of dissonance
										//	5: 
}// tuning()

float* tuning::get_peaks(float* mX, long N, bool smooth, float tresh) {
	float* peaks = new float[N];						// init peak buffer

	if(smooth) {
		for(long k=1; k<N; k++) {
			mX[k] = (mX[k] + mX[k-1])/2;					// smooth spectrum
		}
	}
	int peak_count = 0;
	peaks[0] = 0; peaks[N] = 0;											// set bin 0 and N to 0.0
	for(long k=1; k<N-1; k++) {											// iterate trough spectrum
		peaks[k] = 0;													// init bin to 0
		if((mX[k-1] < (mX[k]-tresh)) && (mX[k+1] < (mX[k]-tresh))) {	// is bin peak?
			peaks[k] = mX[k];											// set magnitude of peak to bin
			peak_count++;
		}
	}
	std::cout<<"peaks found: "<<peak_count<<std::endl;
	return peaks;
}


float tuning::get_key(int nth_key) {

}// get_key()



key::key(float n_freq) {
	this->freq = n_freq;
}// key()

float key::get_freq() {
	return freq;
}// get_freq()


// common complex procedures:-----------------------------------------------|

float c_abs(float a, float b) {
	return std::sqrt(a*a+b*b);
}

float c_arg(float a, float b) {
	return std::atan2(a, b);
}

// -------------------------------------------------------------------------|
