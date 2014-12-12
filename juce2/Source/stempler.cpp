#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include "stempler.h"

tuning::tuning(float* mX, long N, int n_keys, bool mirror, float tresh, int f_fs) {	// calculate tuning:
	float* peaks = get_peaks(mX, N, true, tresh);		//	1: find peaks in spectrum
	for(long k=0; k<N; k++) {
		if(peaks[k] > 0) {
			//std::cout<<"bin: "<<k<<" val: "<<peaks[k]<<std::endl;
		}
	}
										//	2: calculate dissonance-curve
										//	3: sort intervals on amount of dissonance
										//	4: 
}// tuning()

int tuning::calc_ERB(long bin, int fs, long N) {
	float freq = (float)bin * ((float)fs/(float)N);
	return (int)(24.7 * (4.37 * freq/1000 + 1));
}

float* tuning::dissonance_curve(float* peaks, long N, int f_fs) {
	//calculate dissonance of critical band around peaks:
	float* band_diss = new float[N+calc_ERB(N, f_fs, N)];			
	//diss_curve = [0, 0.7, 1, 0.9, 0.8, 0.6, 0.4, 0.2, 0.1, 0, 0, 0]
	float dis_curve[] = {0, 0.7, 1, 0.9, 0.8, 0.6, 0.4, 0.2, 0.1, 0, 0, 0};
	
	//calculate dissonance curve:
	float* diss_curve = new float[(N+calc_ERB(N, f_fs, N))*2];


}

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
