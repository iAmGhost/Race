#pragma once
/*
    Title:    LCD Control Library
    Author:   Minsuk Kim. (Default 3rd)
    Date:     9/2001
    Purpose:  LCD Control Functions.
    Note:     To contact me, mail to mjkms@ihanyang.ac.kr
    
    Interface:
		void lcdClear(void)
			: Clear lcd pannel.
		void lcd_putch(unsigned char reg)
			: Output one charactor.
		void putcharInt(unsigned char reg)
			: Output one charactor as decimel.
		void putString(char str[])
			: Output String to next place.
		void printLCD(char str[])
			: Clear lcd and output String.
		void secondRow(void)
			: Go to next line.
*/

//#define LCD_DATA_DIR
#define LCD_DATA	(*(volatile unsigned char *)0x8000)
#define LCD_CONTROL	(*(volatile unsigned char *)0x8001)

char lcd_con;

#define LCD_ENABLE_ON	(LCD_CONTROL = (lcd_con|=0x04))
#define LCD_ENABLE_OFF	(LCD_CONTROL = (lcd_con&=0x0b))
#define LCD_R_W_ON		(LCD_CONTROL = (lcd_con|=0x02))
#define LCD_R_W_OFF		(LCD_CONTROL = (lcd_con&=0x0d))
#define LCD_RS_ON		(LCD_CONTROL = (lcd_con|=0x01))
#define LCD_RS_OFF		(LCD_CONTROL = (lcd_con&=0x0e))


/* private function */
void lcdDelay(int d);
void lcdClear();
void lcdRegWrite(unsigned char reg);
void lcdDelayLong(int d);

/* public function. interface */
void lcdInit(void);
void lcdClear(void);
void lcd_puts(char lcd_l, char *s);
void lcd_putch(unsigned char reg);
void lcd_putn6(unsigned int number);
void putcharInt(unsigned char reg);
void putcharHex(unsigned char reg);
void putString(char str[]);
void printLCD(char str[]);
void secondRow(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
