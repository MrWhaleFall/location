#include <reg51.h>
#include <intrins.h>
#include <string.h>
#include "mytools.h"
#include "recAndSend.h"

//********************send message***********************
void sendByte(uchar byte)
{
	SBUF=byte;
	while(!TI);
	TI=0;
}
void sendString(uchar *s)
{
	//strcat(s,'\0');
	while(*s!='\0')
	{
		sendByte(*s);
		s++;
	}
}
void sendToBT(){
	static code char startBT[9]={'A','T','+','I','N','Q',0X0D,0X0A,'\0'};//instruct:AT+INQ\r
	static char flag='n';
	//set preferences of register.
	if('n'==flag){
		TMOD|=0X20;
		SCON=0X50;
		TH1=0XFF;
		TL1=0XFF;
		PCON=0X80;
		//ES=1;
		TR1=1;
		EA=1;
		
		flag='y';	
	}
	ES=0;
	delayms(100);
	sendString(startBT);
	delayus(100);
	ES=1;
}
/*****************************End of send struction************************************/
void initBT(){
	uchar i=0;
	bit j=0;
	for(i=0;i<0;i++){
		if(0==i){
			LU_EN=1;LD_EN=0;RD_EN=0;RU_EN=0;
		}
		//To iterate over,left shift.
		j=LU_EN;
		_nop_();
		LU_EN=LD_EN;
		_nop_();
		LD_EN=RD_EN;
		_nop_();
		RD_EN=RU_EN;
		RU_EN=j;
		
		//Send instruct to bluetooth.
		sendToBT();
		if(3==i){
			LU_EN=0;
		}
	}
}

char *getRSSI(char wit){
	static char flag='n';//n:have not been initialized,y:have been initialized. 
	if(flag=='n'){
		initBT();//Initialize bluetooth.
		flag='y';
	}
	LU_EN=0;RU_EN=0;RD_EN=0;LD_EN=0;
	switch(wit){
		case 0:
			LU_EN=1;
			break;
		case 1:
			RU_EN=1;
			break;
		case 2:
			RD_EN=1;
			break;
		case 3:
			LD_EN=1;
			break;
	}

	sendToBT();
}



