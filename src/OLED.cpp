#include "OLED.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void OLED_Init()
{
    // OLED屏
    u8g2.begin();
    u8g2.setFont(u8g2_font_ncenB08_tr);     // 设置字体
    u8g2.drawStr(1, 24, "Hello, World!");   // 在屏幕上显示文字
    u8g2.sendBuffer();                      // 发送缓冲区内容到屏幕
}

void Print(const char *str)
{
    u8g2.clearBuffer();     // 清空缓冲区
    u8g2.setCursor(1, 24);
    u8g2.print(str);
    u8g2.sendBuffer();      // 发送缓冲区内容到屏幕
}

void Print(String str)
{
    u8g2.clearBuffer();     // 清空缓冲区
    u8g2.setCursor(1, 24);
    u8g2.print(str);
    u8g2.sendBuffer();      // 发送缓冲区内容到屏幕
}

void Print(double num)
{
    u8g2.clearBuffer();     // 清空缓冲区
    u8g2.drawStr(1, 24, std::to_string(num).c_str());
    u8g2.sendBuffer();      // 发送缓冲区内容到屏幕
}

