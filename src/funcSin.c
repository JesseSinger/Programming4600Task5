#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
ViStatus status;

float funcSin(ViSession inst) 
{
sleep(5);
  status = viWrite(inst, "FUNC SIN", 8,VI_NULL);
	return 0;
}