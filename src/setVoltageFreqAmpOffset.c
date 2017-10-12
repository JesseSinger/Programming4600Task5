#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
// expecting values from - - to -- for amplitude, - - for frequency, - - for offset

ViStatus status;


float setVoltageFreqAmpOffset(ViSession inst, float frequency, float amplitude, float offset)

{
	//scrub for input error
if(frequency > 19999999.0)
{
	frequency = 19999999.0;
}

if(frequency < 0.0)
{
	frequency = 0.0;
}

if (amplitude > 20.0)
{
	amplitude = 20.0;
}


if (amplitude < 0.0)
{
	amplitude = 0.0;
}

if (offset > 7.5)
{
	offset = 7.5;
}

if (offset < 0.0)
{
	offset = 0.0;
}



char commandString[128];
//printf("APPL:SIN %0.2f, %0.2f, %0.2f", frequency, amplitude, offset);
sprintf(commandString, "APPL:SIN %f, %f, %f", frequency, amplitude, offset);
status = viWrite(inst, commandString, sizeof commandString,VI_NULL);
sleep(2);
return 0;
}


