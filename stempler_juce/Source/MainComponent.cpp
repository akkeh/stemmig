/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "AudioCallback.h"


//==============================================================================

void MainContentComponent::buttonClicked(Button* button) {
    
}
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
    button1 = new TextButton(("play"));
    (*button1).setBounds(10, 10, 50, 20);
    addAndMakeVisible(button1);
    (*button1).addListener(this);
    this->startAudioCallback();
    fs = getSampleRate();
    std::cout<<fs<<std::endl;
}

MainContentComponent::~MainContentComponent()
{
    deleteAllChildren();
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::audioCallback(float** buffer, int channels, int frames) {
    for(int chn = 0; chn<channels; chn++) {
        for(int frms=0; frms<frames; frms++) {
            buffer[chn][frms] = (float)(random() % 200 - 100)/100;
        }
    } 
}
void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
