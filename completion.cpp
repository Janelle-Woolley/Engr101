#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){ 
   int sample_rate = 44100; // samples per second, select value which provides good quality sound 
   double dt = 1.0/sample_rate; // time between samples 
   double duration = 10; // how long [seconds] it will sound 
   int n_samples = duration/dt; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
                        // - how many samples are there altogether? What type should this variable be? 
   int* waveform = new int[n_samples]; // creates the array 
   int frequency1 = 1000; // pitch of the sound 
   int frequency2 = 1500; // pitch of the sound
   int volume = 6000; // 6000 is loud enough 
   
   for(int i_sample = 0; i_sample < n_samples ; i_sample++){
	   int frequency;  
	   if(i_sample % 15000 == 0){
		   if(frequency == frequency1){
			  frequency = frequency2;
		   }else{
			  frequency = frequency1;
		   }	
		}
		// if using array 
		waveform[i_sample] = volume*sin(2*M_PI*frequency*i_sample*dt);
   } 
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
   delete[] (waveform); //if using array 
   return 0; 
} 
