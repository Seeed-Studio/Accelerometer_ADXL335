/*****************************************************************************/
//	Function:    Cpp file for ADXL335 
//  Hardware:    Grove - 3-Axis Analog Accelerometer
//	Arduino IDE: Arduino-1.0
//	Author:	 FrankieChu		
//	Date: 	 Jan 10,2013
//	Version: v1.0
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
/*******************************************************************************/
#include <Arduino.h>
#include "ADXL335.h"

void ADXL335::pinsInit()
{
	pinMode(X_AXIS_PIN, INPUT);
	pinMode(Y_AXIS_PIN, INPUT);
	pinMode(Z_AXIS_PIN, INPUT);
}
void ADXL335::begin()
{
	pinsInit();
	scale = (float)SENSITIVITY*ADC_AMPLITUDE/ADC_REF;
}
void ADXL335::getXYZ(int16_t *x,int16_t *y,int16_t *z)
{
	*x = analogRead(X_AXIS_PIN);
	*y= analogRead(Y_AXIS_PIN);
	*z = analogRead(Z_AXIS_PIN);
}
void ADXL335::getAcceleration(float *ax,float *ay,float *az)
{
	int x,y,z;
	float xvoltage,yvoltage,zvoltage;
	getXYZ(&x,&y,&z);
	xvoltage = (float)x*ADC_REF/ADC_AMPLITUDE;
	yvoltage = (float)y*ADC_REF/ADC_AMPLITUDE;
	zvoltage = (float)z*ADC_REF/ADC_AMPLITUDE;
	Serial.println("voltage:");
	Serial.println(xvoltage);
	Serial.println(yvoltage);
	Serial.println(zvoltage);
	*ax = (xvoltage - ZERO_X)/SENSITIVITY;
	*ay = (yvoltage - ZERO_Y)/SENSITIVITY;
	*az = (zvoltage - ZERO_Z)/SENSITIVITY;
	
}

