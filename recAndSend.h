/*--------------the receive and send function of RSSI-------------*/

#ifndef __RECANDSEND_H_
#define __RECANDSEND_H_

#include "myTools.h"



//Define Pins
  //bluetooths EN
sbit LU=P0^0;
sbit LD=P0^1;
sbit RU=P0^2;
sbit RD=P0^3;



//Declared global function
char *getRSSI(char wit);//from witch bluetooth get RSSI.
char *sendRSSI();

#endif
