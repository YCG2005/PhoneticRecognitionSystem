#ifndef _OLED_H_
#define _OLED_H_

#include <U8g2lib.h>
#include <Wire.h>

void OLED_Init();
void Print(const char* str);
void Print(String str);
void Print(double num);

#endif