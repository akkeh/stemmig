#include <sndfile.h>
#include <fstream>
#include <cmath>
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#ifndef LOADF_H_
#define LOADF_H_

typedef struct {
	float* data;
	unsigned long int N;
	int chn;
} samp;


samp loadfile(const juce::String filepath);
 
#endif
