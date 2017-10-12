#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
ViStatus status;
ViChar commandbuffer[256];
ViChar commandbuffer2[256];

float frequencyStartStop(ViSession inst, float startFrequency, float stopFrequency)

{

	sprintf(commandbuffer, "FREQ:STAR %f", startFrequency);
	status = viWrite(inst, commandbuffer, 12,VI_NULL);
	sleep(2);
	sprintf(commandbuffer2, "FREQ:STOP %f", stopFrequency);

	status = viWrite(inst, commandbuffer2, 12,VI_NULL);
	sleep(2);
	return 0;
}
