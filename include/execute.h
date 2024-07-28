#ifndef _EXECUTE_H_
#define _EXECUTE_H_

#include <Arduino.h>
#include "arduinoFFT.h"
#include "OLED.h"
#include "Define.h"
#include "execute.h"
#include "BuzzerMusic.h"
#include "vector"
#include "assert.h"

extern unsigned int samplingPeriod;
extern unsigned long microSeconds;
extern double vertice;
extern std::vector<double> Music_Score_Vec;

extern double vReal[SAMPLES];
extern double vImag[SAMPLES];
extern double cap_number[10];

void ModeOne_BuzzerMusic(int type);
void ModeTwo_OddCapLearning();
void ModeThree_EvenCapLearning_Water();
void ModeFour_FiveCapWaterLearning();
void ModeFour_RecognitionLearning();
void ModeFive_EigthCapWaterLearning();
void FFT_transform();

#endif
