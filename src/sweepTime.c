#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
ViStatus status;
ViChar commandbuffer2 [256];
float sweepTime(ViSession inst, float sweepyTime)
{
	sprintf(commandbuffer2, "SWE:TIME %f", sweepyTime);

	status = viWrite(inst, commandbuffer2, 18,VI_NULL);
	return 0;
}