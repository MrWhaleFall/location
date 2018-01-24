#include <reg51.h>
#include "myTools.h"
#include "recAndSend.h"
sbit LEVEL=P0^0;
sbit fff=P0^1;
int main(){
	getRSSI(1);
	fff=1;
	LEVEL=0;
	while(1);	
}