
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorContr.h"
#ifdef __cplusplus
	};
#endif
 
void FB_Motor(struct FB_Motor* inst)
{
    /*
    REAL a = inst->u / inst->ke - inst->w;
    REAL b = a / inst->Tm;
    
    inst->integrator.in = b;
    FB_Integrator(&inst->integrator);
    
    inst->w = inst->integrator.out;
    
    inst->integrator.in = inst->w * inst->dt;
    FB_Integrator(&inst->integrator);
    
    inst->phi = inst->integrator.out;
    */
    
    inst->speed_integrator.in = (inst->u / inst->ke - inst->w) / inst->Tm;;
    inst->speed_integrator.dt = inst->dt;
    FB_Integrator(&inst->speed_integrator);
    inst->w = inst->speed_integrator.out;

    inst->position_integrator.in = inst->w;
    inst->position_integrator.dt = inst->dt;
    FB_Integrator(&inst->position_integrator);
    inst->phi = inst->position_integrator.out;
    
}
