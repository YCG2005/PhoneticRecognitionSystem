#ifndef _DEFINE_H_
#define _DEFINE_H_

// low 1-7
#define LOW_1		262
#define LOW_1_p_5	277
#define LOW_2		294
#define LOW_2_p_5	311
#define LOW_3		330
#define LOW_4		349
#define LOW_4_p_5	370
#define LOW_5		392
#define LOW_5_p_5	415
#define LOW_6		440
#define LOW_6_p_5	466
#define LOW_7		494

// mid 1-7
#define MID_1		523
#define MID_1_p_5	554
#define MID_2		587
#define MID_2_p_5	622
#define MID_3		659
#define MID_4		698
#define MID_4_p_5	740
#define MID_5		784
#define MID_5_p_5	831
#define MID_6		880
#define MID_6_p_5	932
#define MID_7		988

// high 1-7
#define HIG_1		1046
#define HIG_1_p_5	1109
#define HIG_2		1175
#define HIG_2_p_5	1245
#define HIG_3		1319
#define HIG_4		1397
#define HIG_4_p_5	1480
#define HIG_5		1568
#define HIG_5_p_5	1661
#define HIG_6		1760
#define HIG_6_p_5	1865
#define HIG_7		1976

// 音阶的频率（单位：赫兹）
const int NOTE_DO = 261;  // C4
const int NOTE_RE = 294;  // D4
const int NOTE_MI = 329;  // E4
const int NOTE_FA = 349;  // F4
const int NOTE_SOL = 392;  // G4
const int NOTE_LA = 440;  // A4
const int NOTE_SI = 493;  // B4

// pinout
#define FFT_PIN			0				// FFT引脚
#define BUZZER_PIN  	1				// 蜂鸣器引脚
#define Button_One		10				// 按键1引脚	mode one 
#define Button_Two		6				// 按键2引脚	mode two
#define Button_Three 	12				// 按键3引脚	mode three
#define Button_Four		7				// 按键4引脚	mode four
#define Button_Five		2				// 按键6引脚	musical mode
#define Button_Exit		3				// 按键5引脚	exit mode

#define SAMPLES 2048            	// 必须为2的幂次
#define SAMPLING_FREQUENCY 10000 	// 采样频率

#endif // _DEFINE_H_