/*------------------myTools---------------
there are many functions halp us engaged in hardware development.
author: Golden Retriever
time:Jan 17,2018
************************************************/


#ifndef __MYTOOLS_H_
#define __MYTOOLS_H_

//Redefine keywords
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int 
#endif



//Declared global variable

//Declared global functions
void delayus(uint i);//The rang of i is 0~65535. when i=1 it delay 5us
void delayms(uint i);//delay 1ms

void UsartInit();
void sendMsg(char* msg);//Baud rate:115200bps
void sendByte(uchar byte);
uchar Strlen(uchar *s);

#endif 