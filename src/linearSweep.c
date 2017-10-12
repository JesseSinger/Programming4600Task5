#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
#include <funcSin.h>
#include <sweepStatOn.h>
#include <sweepSpaceLin.h>
#include <frequencyStartStop.h>
#include <sweepTime.h>

// expecting values from - - to -- for amplitude, - - for frequency, - - for offset
ViStatus status;


float linearSweep(ViSession inst, float startFreq, float stopFreq, float sweepyTime) 

{
funcSin(inst);
sleep(2);
sweepStatOn(inst);
sleep(2);
sweepSpaceLin(inst);
sleep(2);
frequencyStartStop(inst, startFreq, stopFreq);
sleep(2);
sweepTime(inst,sweepyTime);
sleep(2);
status = viWrite(inst, "TRIG:SOUR IMM", 13,VI_NULL);
sleep(2);
outputOn(inst);
sleep(5);
 // status = viWrite(inst, "OUTP OFF", 8,VI_NULL);


return 0;
}