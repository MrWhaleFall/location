#include <reg51.h>
#include "myTools.h"

uchar recMsg[26]={0x00};
uchar end=0;//When it equal 5,accept end.
//function of delay
void delayus(uint i){
	while(i--);
}
void delayms(uint i){
   while(i--){
   	delayus(200);
   }
}

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
void sendMsg(char* msg[]){
	/*
	static char flag='n';
	//set preferences of register.
	if('n'==flag){
		TMOD|=0X20;
		SCON=0X50;
		TH1=0XFF;
		TL1=0XFF;
		PCON=0X80;//set SMOD
		ES=1;
		TR1=1;
		EA=1;
		flag='y';	
	}
	*/
	ES=0;
	delayms(100);
	sendString(msg);
	delayus(100);
	ES=1;
}

void UsartInit()
{
	SCON=0X50;		
	TMOD=0X20;			
	PCON=0X80;			
	TH1=0XFF;			
	TL1=0XFF;
	ES=1;					
	EA=1;					
	TR1=1;					
}

void receiver() interrupt 4
{
	
	static char i=0;
	static char flag=0;
	char ch=0;
	static ch2=0;//ch2:How times get ',' to judge the end.
	
	ch=SBUF;
	if('+'==ch || flag==1){
		flag++;
		
		if('I'==ch){
			flag++;//flag=3
		}
		else if(flag==2) {
			flag=0;
		}
	}
	if(flag>=3){
		flag++;
		//this time get ':'.
		if(flag>7){
			if(ch==',')
			{
				ch2++;
			}
			if(ch2!=1){
			   recMsg[i++]=ch;
			}
			if(ch2==2){
				end++;
				if(end==5){					
					recMsg[i++]='\r';
					recMsg[i++]='\n';
					recMsg[i++]='\0';
					i=0;
					flag=0;
					ch2=0;
					
				}
			}			
		}
	}
	RI=0;
}
