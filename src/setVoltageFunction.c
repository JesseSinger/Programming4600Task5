#define VOLTS_VPP 0
#define VOLTS_VRMS 1
#define VOLTS_DMS 2

#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
//#include <setVoltageFunctions.h>


float voltage = 0.0;
ViStatus status;
ViSession viDG1022;


float setVoltageUnit(int VoltageUnit)
{

if(VoltageUnit==0)
{
status = viWrite(viDG1022, "VOLT:UNIT VPP", 13,VI_NULL);
sleep(2);
}

if(VoltageUnit==1)
	{
	status = viWrite(viDG1022, "VOLT:UNIT VRMS", 13,VI_NULL);
	sleep(2);
	}

if(VoltageUnit==2)
	{
	status = viWrite(viDG1022, "VOLT:UNIT DBM", 13,VI_NULL);
	sleep(2);
}

	return 0;
}



//#endif