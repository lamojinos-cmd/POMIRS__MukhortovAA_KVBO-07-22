#include <bur/plctypes.h>
#include <bur/plc.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
    if(Enable)
    {
        
        count += 1;
        
        if (count >= 1000 && count <= 1500) Speed = 40;
        else Speed = 5;
        
        fb_controller.e = Speed - fb_motor.w;

        fb_motor.u = Speed * fb_motor.ke;
        fb_motor1.u = (Speed - fb_controller.u) * fb_motor1.ke;
        
        FB_Regulator(&fb_controller);
        FB_Motor(&fb_motor);
        FB_Motor(&fb_motor1);
        
        /*
        count += 1;
        
        if (count >= 1000 && count <= 1500) Speed = 40;
        else Speed = 5;
  
        fb_controller.e = Speed - fb_motor.w;

        FB_Regulator(&fb_controller);
        
        fb_motor.u = fb_controller.u;
        fb_motor1.u = Speed * fb_motor1.ke;
        
        FB_Motor(&fb_motor);
        FB_Motor(&fb_motor1);   */  
    }
    else Speed = 0;
}
