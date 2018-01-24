#include <reg51.h>
#include "myTools.h"
#include "recAndSend.h"

extern uchar end;
extern uchar recMsg[26];
sbit LEVEL=P0^0;
sbit fff=P0^1;
int main(){
	/*
	getRSSI(1);
	fff=1;
	LEVEL=0;
	while(1);*/
	UsartInit();
	fff=0;
	sendMsg("ads\r\n");
	while(1){
		
		
		if(end!=0)
			fff=1;
		if(end==4){
			sendMsg(recMsg);
		}
	}	
}