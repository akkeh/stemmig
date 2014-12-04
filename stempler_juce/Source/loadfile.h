#include <sndfile.h>
#include <fstream>
#include <cmath>
#include "../JuceLibraryCode/JuceHeader.h"

int loadfile(const juce::String filepath, float* data, unsigned long int* N, int* ch, int* fs);
 
