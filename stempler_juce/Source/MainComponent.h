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
class MainContentComponent   : public Component, public ButtonListener, private AudioCallback
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
    void buttonClicked(Button* button);
    void paint (Graphics&);
    void resized();
private:
    //==============================================================================
    void audioCallback(float** buffer, int channels, int frames);
    int play_sound();
    void playSine();
    int open_file(const juce::String filepath);
    double phase;
    TextButton* button1;

    float* data;
    unsigned long int N;
    int ch;
    int fs;

    float* read_ptr;
    void update_ptr(); 
    float buf[512*2];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)

};


#endif  // MAINCOMPONENT_H_INCLUDED
