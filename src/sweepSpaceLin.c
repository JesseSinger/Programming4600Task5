#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
ViStatus status;

float sweepSpaceLin(ViSession inst)
{

	status = viWrite(inst, "SWE:SPAC LIN", 12,VI_NULL);
	return 0;
}
