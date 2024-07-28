#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "Define.h"
#include "OLED.h"
#include "execute.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Serial begin success");

    samplingPeriod = round(1000000 * (1.0 / SAMPLING_FREQUENCY));

    /* oled屏 */
    OLED_Init();                                // A4,A5 为I2C接口

    /* 按钮 */
    pinMode(Button_One, INPUT_PULLDOWN);        // 设置上拉电阻
    pinMode(Button_Two, INPUT_PULLDOWN);        // 设置上拉电阻
    pinMode(Button_Three, INPUT_PULLDOWN);      // 设置上拉电阻
    pinMode(Button_Four, INPUT_PULLDOWN);       // 设置上拉电阻
    pinMode(Button_Exit, INPUT_PULLDOWN);       // 设置上拉电阻
    pinMode(Button_Five, INPUT_PULLDOWN);    // 设置上拉电阻

    cap_number[0] = 1000.00;
}

void loop()
{
    if(digitalRead(Button_One) == HIGH) {
        ModeOne_BuzzerMusic(1);
    }else if(digitalRead(Button_Two) == HIGH) {
        ModeTwo_OddCapLearning();
    }else if(digitalRead(Button_Three) == HIGH) {
        ModeThree_EvenCapLearning_Water();
    }else if(digitalRead(Button_Four) == HIGH) {
        ModeFour_FiveCapWaterLearning();
    }else if(digitalRead(Button_Five) == HIGH) {
        ModeFive_EigthCapWaterLearning();
    }
    // } else if(digitalRead(Button_Musical) == HIGH && Music_Score_Vec.size() > 0){
    //     ModeFourMusicScoreOutPut();
    // }
}