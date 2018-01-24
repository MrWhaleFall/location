#include <reg51.h>
#include <intrins.h>
#include <string.h>
#include "mytools.h"
#include "recAndSend.h"


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
		//sendToBT();
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

	//sendToBT();
}



