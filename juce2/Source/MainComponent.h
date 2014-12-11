/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioCallback.h"
#include "loadfile.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class note {
public:
	note(float* n_buf, long n_len);
private:
	float* buffer;
	long len;
	long read_p;
};

class MainContentComponent   : public Component, public ButtonListener, private AudioCallback
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
	
    void paint (Graphics&);
    void resized();

    void buttonClicked(Button* button);
	void load_button();

	float* file_buf;	
	long file_len;
	int file_chn;

private:
    //==============================================================================
    void audioCallback(float** buffer, int channels, int frames);
    TextButton* load_but;
    TextButton* note_but;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
