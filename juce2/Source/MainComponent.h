/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioCallback.h"
#include <vector>
#include "loadfile.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class note {
public:
	note(float* n_buf, long n_len, int n_chn);
	float get_samp();
	bool del_me;
private:
	float* buffer;
	long len;
	int chn;
	float read_p;
	float speed;
};

class MainContentComponent   : public Component, public ButtonListener, private AudioCallback, public KeyListener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
	
    void paint (Graphics&);
    void resized();

    void buttonClicked(Button* button);
	void load_button();
	void fill_buffer();

	float* out_buf;

	float* file_buf;	
	long file_len;
	int file_chn;

private:
    //==============================================================================
    void audioCallback(float** buffer, int channels, int frames);
	bool keyPressed(const KeyPress &key, Component* origin);
	std::vector<note> notes;

    TextButton* load_but;
    TextButton* note_but;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
