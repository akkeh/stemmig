/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "AudioCallback.h"
#include "loadfile.h"
#include <vector>

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);

 	load_but = new TextButton(("play"));
    (*load_but).setBounds(10, 10, 50, 20);
    addAndMakeVisible(load_but);
    (*load_but).addListener(this);
    
    note_but = new TextButton(("noot"));
    (*note_but).setBounds(100, 10, 50, 20);
    addAndMakeVisible(note_but);
    (*note_but).addListener(this);

	out_buf = new float[512];

}

MainContentComponent::~MainContentComponent()
{
    deleteAllChildren();
}

void MainContentComponent::buttonClicked(Button* button) {
    if(button == load_but) {
		load_button();
		fill_buffer();
		this->startAudioCallback();
	} else if (button == note_but) {
		notes.push_back(note(file_buf, file_len, file_chn));
		std::cout<<"notes: "<<notes.size()<<std::endl;
	}
}

void MainContentComponent::load_button() {
	FileChooser myChooser ("I pitty the file who doesn't choose a fool!", File::getSpecialLocation(File::userHomeDirectory), "*.wav");
        if(myChooser.browseForFileToOpen()) {
            File wavFile (myChooser.getResult());
			long length_of_file; int channels;
            float* data = load_file(wavFile.getFullPathName(), &length_of_file, &channels);
			file_buf = data;
			file_len = length_of_file;
			file_chn = channels;
        }

}

void MainContentComponent::fill_buffer() {
	for(int i=0; i<notes.size(); i++) if(notes[i].del_me) notes.erase(notes.begin()+i);
	for(long n=0; n<512; n++) {
		out_buf[n] = 0;
		for(int i=0; i<notes.size(); i++) {
			out_buf[n]+=notes[i].get_samp();
		}
	}
}


void MainContentComponent::audioCallback(float** buffer, int channels, int frames) {

	for(int c=0; c<channels; c++) {
		for(long n=0; n<512; n++) {
			buffer[c][n] = out_buf[n];
		}		
	}
	fill_buffer();
}


void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

note::note(float* n_buf, long n_len, int n_chn) {
	this->buffer = n_buf;
	this->len = n_len;
	this->chn = n_chn;
	this->read_p = 0;
	this->del_me = false;
	this->speed = 1.5;
}

float note::get_samp() {
	float sample = 0;
	if(read_p >= len) {
		del_me = true;		
	} else {
		sample = buffer[(int)read_p];
		read_p+=speed;
	}

	return sample;
}
