/*****************************************************************************/
//	Function:    Header file for ADXL335 
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
#ifndef __ADXL335_H__
#define __ADXL335_H__

#include <Arduino.h>
/*macro definitions of Analog read pins*/
#define X_AXIS_PIN A0
#define Y_AXIS_PIN A1
#define Z_AXIS_PIN A2

#define ADC_AMPLITUDE 1024//amplitude of the 10bit-ADC of Arduino is 1024LSB
#define ADC_REF	5	//ADC reference is 5v
#define ZERO_X	1.22 //accleration of X-AXIS is 0g, the voltage of X-AXIS is 1.22v
#define ZERO_Y	1.22 //
#define ZERO_Z	1.25 //
#define SENSITIVITY 0.25//sensitivity of X/Y/Z axis is 0.25v/g

class ADXL335
{
private:
	void pinsInit();
	float scale;
public:
	void begin();
	void getXYZ(int16_t *x,int16_t *y,int16_t *z);
	void getAcceleration(float *ax,float *ay,float *az);
};

#endif
