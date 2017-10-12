#define VOLTS_VPP 0
#define VOLTS_VRMS 1
#define VOLTS_DMS 2

#include <stdio.h> 
#include <stdlib.h>  
#include <visa.h> // library interface used for oscillscope and function generator
#include <windows.h> // library for sleep(microseconds)



class functionGenerator
{
	private: //private members, not for touching!
	ViSession viDG1022; //session for function generator by Rigol, DG1022
	float amplitude;
	float offset;
	float phase;
	float startFreq;
	float stopFreq;
	float voltage;
	float sweepyTime;
	float frequency;
	ViChar desc[VI_FIND_BUFLEN];
	ViFindList fList;
	ViUInt32 numInst;
	ViStatus status;
	ViSession defaultRM;
	ViChar commandbuffer[256];
	ViChar commandbuffer2[256];
	ViChar commandbuffer3 [256];
	int VoltageUnit = 0;
	ViChar resultBuffer[256];
	ViInt32 resultCount;

public:
	
	myclass();
	openInstrument();
	functionGenerator();
	setVoltageFreqAmpOffset();
	setAmplitude();
	setOffset();
	setPhase();
	setVoltageUnit();
	frequencyStartStop();
	linearSweep();
	outputOn();
	sweepSpaceLin();
	sweepStatOn();
	sweepTime();
	funcSin();
	IDNquery();
};


functionGenerator::functionGenerator()
{
	frequency = 20000.0;
	amplitude = 2.0;
	offset = .5;
	phase = 10.0;
	startFreq = 150.0;
	stopFreq = 1000.0;
	sweepyTime = 10.0;
	voltage = 0.0;
}


functionGenerator::IDNquery() 

{
Sleep(5000);
  status = viWrite(viDG1022, (unsigned char*)"*IDN?", 5,VI_NULL);
Sleep(5000);
  status = viRead(viDG1022, (unsigned char*)resultBuffer, 256, VI_NULL);
Sleep(5000);
}


functionGenerator::openInstrument()
{
 status=viOpenDefaultRM(&defaultRM);

  if(status !=VI_SUCCESS) return EXIT_FAILURE;

  status=viFindRsrc(defaultRM, "USB[0-9]::0x0400?*INSTR",&fList, &numInst, desc);

status = viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
Sleep(2000);
  printf("Opened(%s)\n", desc);



}

functionGenerator::setVoltageUnit()
{

if(VoltageUnit==0)
{
status = viWrite(viDG1022, (unsigned char*)"VOLT:UNIT VPP", 13,VI_NULL);
Sleep(2000);
}

if(VoltageUnit==1)
	{
	status = viWrite(viDG1022, (unsigned char*)"VOLT:UNIT VRMS", 13,VI_NULL);
Sleep(2000);
	}

if(VoltageUnit==2)
	{
	status = viWrite(viDG1022, (unsigned char*)"VOLT:UNIT DBM", 13,VI_NULL);
	Sleep(2000);
}

	return 0;

}


functionGenerator::setVoltageFreqAmpOffset()
{
	Sleep(2000);
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

Sleep(2000);

char commandString[128];
printf("APPL:SIN %0.2f, %0.2f, %0.2f", frequency, amplitude, offset);
sprintf(commandString,"APPL:SIN %f, %f, %f", frequency, amplitude, offset);
status = viWrite(viDG1022, (unsigned char*)commandString, sizeof commandString, VI_NULL);
Sleep(2000);
return 0;

}

functionGenerator::setPhase()
{
Sleep(5000);
  status = viWrite(viDG1022, (unsigned char*)"PHAS 10", 7,VI_NULL);
Sleep(2000);

return 0;

}

functionGenerator::outputOn()
{
Sleep(5000);
  status = viWrite(viDG1022, (unsigned char*)"OUTP ON", 7,VI_NULL);
Sleep(2000);

return 0;

}

functionGenerator::funcSin() 
{
Sleep(5000);
  status = viWrite(viDG1022, (unsigned char*)"FUNC SIN", 8,VI_NULL);
  Sleep(2000);
	return 0;
}


functionGenerator::sweepSpaceLin()
{
Sleep(2000);
	status = viWrite(viDG1022, (unsigned char*)"SWE:SPAC LIN", 12,VI_NULL);
	Sleep(2000);
	return 0;
}

functionGenerator::sweepStatOn()
{
Sleep(2000);
	status = viWrite(viDG1022, (unsigned char*)"SWE:STAT ON", 11,VI_NULL);
	Sleep(2000);
	return 0;
}





functionGenerator:: frequencyStartStop()

{
Sleep(2000);
	sprintf(commandbuffer, (const char*)"FREQ:STAR %f", startFreq);
	status = viWrite(viDG1022, (unsigned char*)commandbuffer, 12,VI_NULL);
	Sleep(2000);
	sprintf(commandbuffer2, (const char*)"FREQ:STOP %f", stopFreq);
Sleep(2000);
	status = viWrite(viDG1022, (unsigned char*)commandbuffer2, 12,VI_NULL);
	Sleep(2000);
	return 0;
}

functionGenerator::sweepTime()
{
	Sleep(2000);
	sprintf(commandbuffer3, (const char*)"SWE:TIME %f", sweepyTime);
Sleep(2000);
	status = viWrite(viDG1022, (unsigned char*)commandbuffer3, 18,VI_NULL);
	Sleep(2000);
	return 0;
}



functionGenerator::linearSweep()
{
funcSin();
Sleep(2000);
sweepStatOn();
Sleep(2000);
sweepSpaceLin();
Sleep(2000);
frequencyStartStop();
Sleep(2000);
sweepTime();
Sleep(2000);
status = viWrite(viDG1022, (unsigned char*)"TRIG:SOUR IMM", 13,VI_NULL);
Sleep(2000);
outputOn();
Sleep(5000);
 // status = viWrite(inst, "OUTP OFF", 8,VI_NULL);


}


int main(void)  
{  

	functionGenerator FG;

	FG.openInstrument();
	//FG.setVoltageUnit();
	FG.IDNquery();
	FG.setVoltageFreqAmpOffset();
	Sleep(2000);
	FG.setPhase();
	Sleep(2000);
	FG.linearSweep();
 
  return(0);  

}  