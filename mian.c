#include <reg51.h>
#include "myTools.h"
#include "recAndSend.h"

uchar j=0;
sbit ES_RI=P0^4;
sbit BT_RI=P0^5;
sbit ES_TI=P0^6;
sbit BT_TI=P0^7;
extern uchar end;
extern uchar recMsg[26];
sbit LEVEL=P0^0;
int main(){
	 
	
	delayms(5000);
	UsartInit();
	sendMsg("AT+CIPSTART=\"TCP\",\"10.4.19.76\",3333\r\n\0");
		delayms(1000);
		sendMsg("AT+INQ\r\n\0");
		/*
	while(1){		   
		if(end==5){		
			end=0;
			
			j=Strlen(recMsg);
			sendMsg("AT+CIPSEND=");//26\r\n\0");
			sendByte(j);
			sendMsg("\r\n\0");
			
			/*sendMsg("AT+CIPSEND=22\r\n\0");
			delayms(1000);
			sendMsg(recMsg); 
			sendMsg("hello\r\n\0");
			sendMsg(recMsg);
		}
	}
	*/
	
	UsartInit();
	while(1){
		j++;
		if(j==600)
		{
			j=0;
			sendMsg("AT+INQ\r\n\0");
		}
		if(end==5){
			sendMsg("AT+CIPSEND=26\r\n\0");
			delayms(10);
			end=0;
			sendMsg(recMsg);
		}
	}	
}