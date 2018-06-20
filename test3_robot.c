/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : test3_robot
//
//  Target Board : atmega32
//
//  Date Created : 19-07-2017 16:53:19
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>
#include "pwm.h"

int main()
{
	pwm_init();
	
	char a[14],z;
	while (1)
	{
	if(read(portc,0)==1)	//Reading vlaues from RC5 sensor, Connection: RC_Sensor Port c Pin 0
		{
			_delay_us(500);
			
			for(int i=0;i<14;i++)
			{
				if(read(portc,0)==1)
				{ 
				
					a[i] = 1;
				
				}
				else
				{
					a[i]=0;
				}
				_delay_us(1777);
				
			}
		a[8]  = a[8] <<5; // left shift by 5 and so on
		a[9]  = a[9] <<4;	//left sift by 4
		a[10] = a[10]<<3;
		a[11] = a[11]<<2;
		a[12] = a[12]<<1;
		a[13] = a[13]<<0;
		
		z=a[8] | a[9] | a[10] | a[11] | a[12] | a[13];	//Receiving value in variable z as sent by the sensor
	
		
		if(z==62);		//Sensor value for a button pressed which is defined to here in code to move in front direction
		{
	
		//Turning ON Motor 1 & Motor 2, by giving HIGH from one pin and low signal from other pin such the two pins act like a Bettery of 5v
		
			write(portd,4,h);	
			write(portd,5,l);	
			write(portd,6,h);	
			write(portd,7,l);
			
		
		}
		
		if(z==52)		//52 is the value recieved and here if value = 52, turning off both the MOTORS i.e. stop the car
		{
			//Sending low signal from both the pins in order to turn the Motor off
			
				write(portd,4,l);	
				write(portd,5,l);
				write(portd,6,l);
				write(portd,7,l);
			
		}
		
		if(z==30)		//if value recieved = 30 turn the Car in right direction
		{
			//Motor 1 = left Motor, Front movement of motor 1 and back movement of motor 2 turns the Car in right direction
			
				write(portd,4,h);	
				write(portd,5,l);
				write(portd,6,l);
				write(portd,7,h);
		
		}
		
		if(z==28)		//if value = 28, turn the Car in left direction
		{
		
				write(portd,4,l);
				write(portd,5,h);
				write(portd,6,h);
				write(portd,7,l);
				
		}
		
		if(z==60)		//if value =60, then turn the Car Back
		{
				//Turning the Motor in reverse direction
				
				write(portd,4,l);	
				write(portd,5,h);
				write(portd,6,l);
				write(portd,7,h);
			
		
		}
		
		if(z==16)
		{
		
		pwm(180);
		
		}
		
		}
		
		
		
	}

}