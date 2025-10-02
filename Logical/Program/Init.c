
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
    count = 0;
    Speed = 0;
    Enable = 1;
    
    fb_motor.speed_integrator.dt = 0.02;
    fb_motor.speed_integrator.out = 0;
    
    fb_motor.position_integrator.dt = 0.02;
    fb_motor.position_integrator.out = 0;
    
    fb_motor.dt = 0.02;
    fb_motor.ke = 43.98;
    fb_motor.Tm = 0.173;
    
    fb_motor1.speed_integrator.dt = 0.02;
    fb_motor1.speed_integrator.out = 0;
    
    fb_motor1.position_integrator.dt = 0.02;
    fb_motor1.position_integrator.out = 0;
    
    fb_motor1.dt = 0.02;
    fb_motor1.ke = 43.98;
    fb_motor1.Tm = 0.173;
    
    fb_controller.dt = 0.02;
    fb_controller.k_p = 3.804;
    fb_controller.k_i = 21.99;
    fb_controller.max_abs_value = 24;
    
    //fb_motor.integrator.dt = 0.02;
    //fb_motor1.integrator.dt = 0.02;
    fb_controller.integrator.dt = 0.02;
}
