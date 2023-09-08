#include "PID.h"


float I_Target,I_error,p_error,s_error,pid_out,PWM_1;

extern float U_data,V_data;

float j,k;

float U1,I1,V,I;

float ki=0.f,kp=20.f;
void PID(void)
{
		
		I_Target=0.1f*U_data;
	
		I_error=I_Target-V_data;
		p_error=I_error;
		s_error=s_error+I_error;
		if(s_error>1000)
				s_error=1000;
		if(s_error<-1000)
				s_error=-1000;	
		pid_out=kp*p_error+ki*s_error;
		PWM_1 = PWM_1 + pid_out;
		if(PWM_1>max)
				PWM_1=max;
		if(PWM_1<min)
				PWM_1=min;	

			k++;
			U1=U_data*U_data + U1;
			I1=V_data*V_data + I1;
			if(k==800)
			{
				V=sqrt(U1/800);
				I=sqrt(I1/800);
				U1=0;
				I1=0;
				k=0;
			}

		if(V<2)
		{
			PWM_1=50;
		}
     TIM1->CCR1=PWM_1;
}
