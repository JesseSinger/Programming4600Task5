#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
// expecting values from - - to -- for amplitude, - - for frequency, - - for offset
ViStatus status;

float setPhase(ViSession inst, float phase) 

{
sleep(5);
  status = viWrite(inst, "PHAS 10", 7,VI_NULL);
sleep(2);

return 0;
}