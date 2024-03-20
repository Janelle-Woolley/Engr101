#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){
   int linecount = 0;
   string line;
   ifstream myfile;
   myfile.open("odetojoy.txt");
   while(getline(myfile, line)){
		linecount++;
   }
   myfile.close();
	
   int sample_rate = 44100; // samples per second, select value which provides good quality sound 
   double dt = 1.0/sample_rate; // time between samples 
   double duration = (linecount/2) + 1; // how long [seconds] it will sound 
   int n_samples = duration/dt; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
                        // - how many samples are there altogether? What type should this variable be? 
   
   int* waveform = new int[n_samples]; // creates the array  
   int volume = 6000; // 6000 is loud enough
   double frequency;
   
   int note_duration = sample_rate/2;
   int note_number = 0;
   int note_sample = 0;
   myfile.open("odetojoy.txt");
   while(getline(myfile, line)){
	   while(note_number < note_duration && note_sample < n_samples){
			waveform[note_sample] = stod(line) * 2;
			note_sample++;
			note_number++;
	   }
	   note_number = 0;
   }
   myfile.close();
   
   for (int i_sample = 0; i_sample < n_samples ; i_sample++){
			frequency = waveform[i_sample]; 
			// if using array 
			waveform[i_sample] = volume*sin(2*M_PI*frequency*i_sample*dt);// 
   }
   
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   MakeWavFromInt("tone1.wav", sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
   delete[] (waveform); //if using array  
   return 0; 
} 
