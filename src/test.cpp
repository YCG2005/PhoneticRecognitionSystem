// #include <arduinoFFT.h>

// #define SAMPLES 128             // 必须为2的幂次
// #define SAMPLING_FREQUENCY 1000 // 采样频率

// arduinoFFT FFT = arduinoFFT();

// unsigned int samplingPeriod;
// unsigned long microSeconds;

// double vReal[SAMPLES];
// double vImag[SAMPLES];

// void setup() {
//   Serial.begin(115200);
//   samplingPeriod = round(1000000 * (1.0 / SAMPLING_FREQUENCY));
// }

// void loop() {
//   /* 采集样本 */
//   for (int i = 0; i < SAMPLES; i++) {
//     microSeconds = micros();
    
//     vReal[i] = analogRead(A0);  // 读取模拟输入
//     vImag[i] = 0;

//     /* 等待下一个采样周期 */
//     while (micros() - microSeconds < samplingPeriod) {}
//   }

//   /* 执行FFT */
//   FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD); // 使用汉明窗
//   FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD); // 执行FFT
//   FFT.ComplexToMagnitude(vReal, vImag, SAMPLES); // 将结果转换为幅度

//   /* 输出频域数据 */
//   for (int i = 0; i < (SAMPLES / 2); i++) {
//     Serial.print((i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES, 1);
//     Serial.print(" ");
//     Serial.println(vReal[i], 1);
//   }

//   delay(1000); // 每秒输出一次结果
// }
