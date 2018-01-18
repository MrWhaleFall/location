#include <reg51.h>
#include "myTools.h"
//function of delay
void delayus(uint i){
	while(i--);
}
void delayms(uint i){
   while(i--){
   	delayus(200);
   }
}


/************************************testing******************
//this function is used 22.1184MHZ
void iniTimer0(){
	TMOD|=0X01;//Select timer0 mode,word mode 1
	TH0=0XFF;
	TL0=0XFE;//delay 1us
	ET0=1;//allow timer0
	EA=1;
	TR0=1;//when use timer0 just let TR0=1

}

void timer0(uint i){
	static char flag='n';//'y':Has been initialized
	if('n'==flag){
		iniTimer0();
	}
}
*/