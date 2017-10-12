#ifndef __SETVOLTAGEFREQAMPOFFSET_H
#define __SETVOLTAGEFREQAMPOFFSET_H
#include <visatype.h>

// expecting values from - - to -- for amplitude, - - for frequency, - - for offset
float setVoltageFreqAmpOffset(ViSession, float , float, float);


#endif