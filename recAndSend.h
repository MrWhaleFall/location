/*--------------the receive and send function of RSSI-------------*/

#ifndef __RECANDSEND_H_
#define __RECANDSEND_H_

#include "myTools.h"



//Define Pins
  //bluetooths EN
sbit LU_EN=P0^0;
sbit LD_EN=P0^1;
sbit RU_EN=P0^2;
sbit RD_EN=P0^3;



//Declared global function
char *getRSSI(char wit);//from witch bluetooth get RSSI.
char *sendRSSI();

#endif
