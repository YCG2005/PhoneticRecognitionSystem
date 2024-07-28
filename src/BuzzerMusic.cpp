#include "BuzzerMusic.h"

std::vector<double> Music_Score_Vec; 

void buzzer_init()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void two_tigers(int type)
{
    byte count = 0;
    switch(type)
    {
        case 0:
        {
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, MID_1);
            delay(500);
            tone(BUZZER_PIN, MID_2);
            delay(500);
            tone(BUZZER_PIN, MID_3);
            delay(500);
            tone(BUZZER_PIN, MID_1);
            delay(500);
            
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, MID_3);
            delay(500);
            tone(BUZZER_PIN, MID_4);
            delay(500);
            tone(BUZZER_PIN, MID_5);
            delay(1000);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, MID_5);
            delay(350);
            tone(BUZZER_PIN, MID_6);
            delay(150); 
            tone(BUZZER_PIN, MID_5);
            delay(350);
            tone(BUZZER_PIN, MID_4);
            delay(150); 
            tone(BUZZER_PIN, MID_3);
            delay(500);
            tone(BUZZER_PIN, MID_1);
            delay(500);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, MID_1);
            delay(500);
            tone(BUZZER_PIN, MID_5);
            delay(500);
            tone(BUZZER_PIN, MID_1);
            delay(1000);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        break;
        }  
        case 1:
        {
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, HIG_1);
            delay(500);
            tone(BUZZER_PIN, HIG_2);
            delay(500);
            tone(BUZZER_PIN, HIG_3);
            delay(500);
            tone(BUZZER_PIN, HIG_1);
            delay(500);
            
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, HIG_3);
            delay(500);
            tone(BUZZER_PIN, HIG_4);
            delay(500);
            tone(BUZZER_PIN, HIG_5);
            delay(1000);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, HIG_5);
            delay(350);
            tone(BUZZER_PIN, HIG_6);
            delay(150); 
            tone(BUZZER_PIN, HIG_5);
            delay(350);
            tone(BUZZER_PIN, HIG_4);
            delay(150); 
            tone(BUZZER_PIN, HIG_3);
            delay(500);
            tone(BUZZER_PIN, HIG_1);
            delay(500);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, HIG_1);
            delay(500);
            tone(BUZZER_PIN, HIG_5);
            delay(500);
            tone(BUZZER_PIN, HIG_1);
            delay(1000);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        break; 
        } 
        case 2:
        {
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, LOW_1);
            delay(500);
            tone(BUZZER_PIN, LOW_2);
            delay(500);
            tone(BUZZER_PIN, LOW_3);
            delay(500);
            tone(BUZZER_PIN, LOW_1);
            delay(500);
            
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, LOW_3);
            delay(500);
            tone(BUZZER_PIN, LOW_4);
            delay(500);
            tone(BUZZER_PIN, LOW_5);
            delay(1000);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, LOW_5);
            delay(350);
            tone(BUZZER_PIN, LOW_6);
            delay(150); 
            tone(BUZZER_PIN, LOW_5);
            delay(350);
            tone(BUZZER_PIN, LOW_4);
            delay(150); 
            tone(BUZZER_PIN, LOW_3);
            delay(500);
            tone(BUZZER_PIN, LOW_1);
            delay(500);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        
        for (count = 0; count < 2; count++)
        {
            tone(BUZZER_PIN, LOW_1);
            delay(500);
            tone(BUZZER_PIN, LOW_5);
            delay(500);
            tone(BUZZER_PIN, LOW_1);
            delay(1000);
        
            noTone(BUZZER_PIN);
            delay(500);
        }
        break;      
        } 
    }
}

void ModeFourMusicScoreOutPut()
{
    for(auto i : Music_Score_Vec){
        tone(BUZZER_PIN, i);
        delay(500);
    }
    noTone(BUZZER_PIN);
}
