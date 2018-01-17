#include <reg51.h>

//function of delay
void delayus(uint i){
	while(i--);
}
void delayms(uint i){
   while(i--){
   	delayus(200);
   }
}