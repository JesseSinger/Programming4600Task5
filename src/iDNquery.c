#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
// expecting values from - - to -- for amplitude, - - for frequency, - - for offset

ViStatus status;
ViChar resultBuffer[256];
ViInt32 resultCount;

float IDNquery(ViSession inst) 

{
sleep(5);
  status = viWrite(inst, "*IDN?", 5,VI_NULL);
sleep(5);
  status = viRead(inst, resultBuffer, 256, &resultCount);
sleep(2);

return 0;
}