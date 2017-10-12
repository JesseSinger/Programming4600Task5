#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
// expecting values from - - to -- for amplitude, - - for frequency, - - for offset
ViStatus status;

float outputOff(ViSession inst) 

{
sleep(5);
  status = viWrite(inst, "OUTP OFF", 8,VI_NULL);
sleep(2);

return 0;
}