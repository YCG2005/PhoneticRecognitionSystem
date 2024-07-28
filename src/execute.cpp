#include "execute.h"

ArduinoFFT<double> FFT = ArduinoFFT<double>();  // 初始化arduinoFFT对象

unsigned int samplingPeriod;
unsigned long microSeconds;
double vertice;

double vReal[SAMPLES];
double vImag[SAMPLES];
double cap_number[10];

void ModeOne_BuzzerMusic(int type)
{
	Print("go into mode one");
	two_tigers(1);
	Print("go out mode one");
}

void ModeTwo_OddCapLearning() {
    // 按下按钮1, 对 1，3，5 三个杯子进行识别训练
    Print("go into mode two");
    int count = 1;
    while (1) {
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if ((vertice > cap_number[0] + 5 || vertice < cap_number[0] - 5) && vertice > 1000.00 && vertice < 3000) {
            cap_number[count] = vertice;                    // 记录n号杯的值
            cap_number[0] = cap_number[count];              // 更新count号杯的值
            String str = String(count) + " number " + String(cap_number[count]);
            Print(str);
            count += 2;
        }
        if(digitalRead(Button_Exit) == HIGH) break;
        if (count > 5) {
            Print("learning success!");
            break;
        }
    }
	cap_number[0] = 0.00;
    double Temp[10]; // 临时数组，用于存储cap_number
    std::copy(cap_number, cap_number + 10, Temp);
    std::sort(Temp, Temp + 10, std::greater<double>()); // 从大到小排序

    while (1) {
		double diff1,diff3,diff5;
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if(vertice > 3000) continue;
        if (vertice > 1000) {
			diff1 = abs(cap_number[1] - vertice);
			diff3 = abs(cap_number[3] - vertice);
			diff5 = abs(cap_number[5] - vertice);
			String cap = (diff1 <= diff3 && diff1 <= diff5) ? "cap one" :
                         (diff3 <= diff1 && diff3 <= diff5) ? "cap three" : "cap five";
			Print(cap);
        }
        if (digitalRead(Button_Exit) == HIGH) {
            Print("exit mode two");
            break;
        }
    }
    
    Serial.print("cap_number1: ");
    Serial.println(cap_number[1], 2);
    Serial.print("cap_number3: ");
    Serial.println(cap_number[3], 2);
    Serial.print("cap_number5: ");
    Serial.println(cap_number[5], 2);
}


void ModeThree_EvenCapLearning_Water()
{
    // 按下按钮1, 对 2，4，5 三个杯子进行识别训练
    Print("go into mode three");
    int count = 1, ans = 0;
    while (1) {
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if ((vertice > cap_number[0] + 5 || vertice < cap_number[0] - 5) && vertice > 1000.00 && vertice < 3000) {
            if(count == 1)  ans = 2;
            if(count == 2)  ans = 4;
            if(count == 3)  ans = 5; 
            cap_number[ans] = vertice;                    // 记录n号杯的值
            cap_number[0] = cap_number[ans];              // 更新count号杯的值
            String str = String(count) + " number " + String(cap_number[ans]);
            Print(str);
            count += 1;
        }
        if(digitalRead(Button_Exit) == HIGH) break;
        if (count > 3) {
            Print("learning success!");
            break;
        }
    }
	cap_number[0] = 0.00;
    double Temp[10]; // 临时数组，用于存储cap_number
    std::copy(cap_number, cap_number + 10, Temp);
    std::sort(Temp, Temp + 10, std::greater<double>()); // 从大到小排序

    while (1) {
		double diff2,diff4,diff5;
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if(vertice > 3000) continue;
        if (vertice > 1000) {
			diff2 = abs(cap_number[2] - vertice);
			diff4 = abs(cap_number[4] - vertice);
			diff5 = abs(cap_number[5] - vertice);
			String cap = (diff2 <= diff4 && diff2 <= diff5) ? "cap two" :
                         (diff4 <= diff2 && diff4 <= diff5) ? "cap four" : "cap five";
			Print(cap);
        }
        if (digitalRead(Button_Exit) == HIGH) {
            Print("exit mode two");
            break;
        }
    }
    
    Serial.print("cap_number1: ");
    Serial.println(cap_number[2], 2);
    Serial.print("cap_number3: ");
    Serial.println(cap_number[4], 2);
    Serial.print("cap_number5: ");
    Serial.println(cap_number[5], 2);
}

void ModeFour_FiveCapWaterLearning()
{
    ModeFour_RecognitionLearning();
    Print("Start train");
    Music_Score_Vec.clear();
    while(1)
    {
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if(vertice > 1000){
            Music_Score_Vec.push_back(vertice);
        }
        if(digitalRead(Button_Exit) == HIGH){
            Print("Learn end");
            break;
        }
    }
    ModeFourMusicScoreOutPut();         // 播放学习的音乐
    delay(1000);
}

void ModeFour_RecognitionLearning()
{
    // 按下按钮1, 对 1，3，5 三个杯子进行识别训练
    Print("go into mode four");
    int count = 1;
    while (1) {
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if ((vertice > cap_number[0] + 5 || vertice < cap_number[0] - 5) && vertice > 1000.00 && vertice < 3000) {
            cap_number[count] = vertice;                    // 记录n号杯的值
            cap_number[0] = cap_number[count];              // 更新count号杯的值
            String str = String(count) + " number " + String(cap_number[count]);
            Print(str);
            count += 1;
        }
        if(digitalRead(Button_Exit) == HIGH) break;
        if (count > 5) {
            Print("learning success!");
            break;
        }
    }
	cap_number[0] = 0.00;
    double Temp[10]; // 临时数组，用于存储cap_number
    std::copy(cap_number, cap_number + 10, Temp);
    std::sort(Temp, Temp + 10, std::greater<double>()); // 从大到小排序

    while (1) {
		double diff1,diff2,diff3,diff4,diff5;
        FFT_transform();
        Serial.print("vertice: ");
        Serial.println(vertice);
        if(vertice > 3000){continue; }
        if (vertice > 1000) {
			diff1 = abs(cap_number[1] - vertice);
            diff2 = abs(cap_number[2] - vertice);
			diff3 = abs(cap_number[3] - vertice);
            diff4 = abs(cap_number[4] - vertice);
			diff5 = abs(cap_number[5] - vertice);

			// 三目运算符
            String cap = (diff1 <= diff2 && diff1 <= diff3 && diff1 <= diff4 && diff1 <= diff5) ? "cap one" :
                         (diff2 <= diff1 && diff2 <= diff3 && diff2 <= diff4 && diff2 <= diff5) ? "cap two" :
                         (diff3 <= diff1 && diff3 <= diff2 && diff3 <= diff4 && diff3 <= diff5) ? "cap three" :
                         (diff4 <= diff1 && diff4 <= diff2 && diff4 <= diff3 && diff4 <= diff5) ? "cap four" :
                         "cap five";
			Print(cap);
            if(cap == "cap one") {
                tone(BUZZER_PIN, NOTE_DO);  delay(500);  noTone(BUZZER_PIN);
            }
            if(cap == "cap two") {
                tone(BUZZER_PIN, NOTE_RE);  delay(500);  noTone(BUZZER_PIN);
            }
            if(cap == "cap three") {
                tone(BUZZER_PIN, NOTE_MI);  delay(500);  noTone(BUZZER_PIN);
            }
            if(cap == "cap four") {
                tone(BUZZER_PIN, NOTE_FA);  delay(500);  noTone(BUZZER_PIN);
            }
            if(cap == "cap five") {
                tone(BUZZER_PIN, NOTE_SOL); delay(500);  noTone(BUZZER_PIN);
            }
            cap = "";
        }
        if (digitalRead(Button_Exit) == HIGH) {
            Print("exit learning");
            break;
        }
    }
    delay(1000);
    Serial.print("cap_number1: ");
    Serial.println(cap_number[1], 2);
    Serial.print("cap_number2: ");
    Serial.println(cap_number[2], 2);
    Serial.print("cap_number3: ");
    Serial.println(cap_number[3], 2);
    Serial.print("cap_number4: ");
    Serial.println(cap_number[4], 2);
    Serial.print("cap_number5: ");
    Serial.println(cap_number[5], 2);
}

void ModeFive_EigthCapWaterLearning()
{
    Print("enter mode five");
    while(1) {
        if(cap_number[1] != 0.00 && cap_number[2] != 0.00 && cap_number[3] != 0.00 && cap_number[4] != 0.00 && cap_number[5] != 0.00) {
            while(1) {
                double diff1,diff2,diff3,diff4,diff5;
                FFT_transform();
                Serial.print("vertice: ");
                Serial.println(vertice);
                if(vertice > 3000) continue;
                if (vertice > 1000) {
                    diff1 = abs(cap_number[1] - vertice);
                    diff2 = abs(cap_number[2] - vertice);
                    diff3 = abs(cap_number[3] - vertice);
                    diff4 = abs(cap_number[4] - vertice);
                    diff5 = abs(cap_number[5] - vertice);
                    
                    Serial.print("diff1: ");
                    Serial.println(diff1, 2);
                    Serial.print("diff2: ");
                    Serial.println(diff2, 2);
                    Serial.print("diff3: ");
                    Serial.println(diff3, 2);
                    Serial.print("diff4: ");
                    Serial.println(diff4, 2);
                    Serial.print("diff5: ");
                    Serial.println(diff5, 2);

                    if(diff1 > 3 && diff2 > 3 && diff3 > 3 && diff4 > 3 && diff5 > 3) {
                        Print("zero cap");
                        continue;
                    }

                    // 三目运算符
                    String cap = (diff1 <= diff2 && diff1 <= diff3 && diff1 <= diff4 && diff1 <= diff5) ? "cap one" :
                                (diff2 <= diff1 && diff2 <= diff3 && diff2 <= diff4 && diff2 <= diff5) ? "cap two" :
                                (diff3 <= diff1 && diff3 <= diff2 && diff3 <= diff4 && diff3 <= diff5) ? "cap three" :
                                (diff4 <= diff1 && diff4 <= diff2 && diff4 <= diff3 && diff4 <= diff5) ? "cap four" :
                                "cap five";
                    Print(cap);
                }
                if(digitalRead(Button_Exit) == HIGH) break;
            }
            break;
        }else {
            Print("enter mode four learning");
            ModeFour_RecognitionLearning();
        }
    }
    Print("exit mode five");
}

void FFT_transform()
{
    /* 采集样本 */
    for (int i = 0; i < SAMPLES; i++) {
        microSeconds = micros();
        
        vReal[i] = analogRead(FFT_PIN);  // 读取模拟输入
        vImag[i] = 0;

        /* 等待下一个采样周期 */
        while (micros() - microSeconds < samplingPeriod) {}
    }

    /* 执行FFT */
    FFT.windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD); // 使用汉明窗
    FFT.compute(vReal, vImag, SAMPLES, FFT_FORWARD); // 执行FFT
    FFT.complexToMagnitude(vReal, vImag, SAMPLES); // 将结果转换为幅度
        
    // 提取频率特征
    vertice = FFT.majorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

    // /* 输出频域数据 */
    // for (int i = 0; i < (SAMPLES / 2); i++) {
    //     Serial.print((i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES, 1);      // 频率值
    //     Serial.print(" ");
    //     Serial.println(vReal[i], 1);                                    // 幅度值
    // }

    // Serial.print("Dominant Frequency: ");
    // Serial.println(vertice, 3);                // 输出主频率
    // Print(vertice);                            // 输出主频率
    delay(20);
}