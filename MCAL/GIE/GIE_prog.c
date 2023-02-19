
#include "GIE_Interface.h"
#include "GIE_Private.h"


void M_GIE_Void_GlobalInterruptEnable(void)
{
	//	set the global intr. enabled
	SET_BIT(SREG_REG,7);
}

void M_GIE_Void_GlobalInterruptDisable(void)
{
	//	set the global intr. enabled
	CLR_BIT(SREG_REG,7);
}
