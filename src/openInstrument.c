#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>

ViChar desc[VI_FIND_BUFLEN];
ViFindList fList;
ViUInt32 numInst;
ViStatus status;
ViSession defaultRM;
ViSession viDG1022;


void openInstrument(void)
{
 status=viOpenDefaultRM(&defaultRM);

  if(status !=VI_SUCCESS) return EXIT_FAILURE;

  status=viFindRsrc(defaultRM, "USB[0-9]::0x0400?*INSTR",&fList, &numInst, desc);

status = viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
sleep(2);
  printf("Opened(%s)\n", desc);

}