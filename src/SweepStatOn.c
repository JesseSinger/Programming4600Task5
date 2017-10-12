#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
ViStatus status;

float sweepStatOn(ViSession inst)
{

	status = viWrite(inst, "SWE:STAT ON", 11,VI_NULL);
	return 0;
}
