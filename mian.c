#include <reg51.h>
#include <string.h>
#include "myTools.h"
#include "recAndSend.h"

sbit ES_RI=P0^4;
sbit BT_RI=P0^5;
sbit ES_TI=P0^6;
sbit BT_TI=P0^7;
extern uchar end;
extern uchar recMsg[26];
sbit LEVEL=P0^0;
int main(){
	 
	UsartInit();
	delayms(7000);
	sendMsg("AT+CIPSTART=\"TCP\",\"10.4.19.76\",3333\r\n\0");
		delayms(1000);
		sendMsg("AT+INQ\r\n\0");
	while(1){		   
		if(end==5){		
			end=0;
			sendMsg("AT+CIPSEND=26\r\n\0");
			delayms(1000);
			sendMsg(recMsg);
		}
	}
	
	/*
	UsartInit();
	while(1){
		if(end==5){
			end=0;
			sendMsg(recMsg);
		}
	}*/	
}