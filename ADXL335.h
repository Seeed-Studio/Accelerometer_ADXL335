/*
 * ADXL335.h
 * Library for accelerometer_ADXL335
 *
 * Copyright (c) 2013 seeed technology inc.
 * Author        :   FrankieChu 
 * Create Time   :   Jan 2013
 * Change Log    :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#ifndef __ADXL335_H__
#define __ADXL335_H__

#include <Arduino.h>
/*macro definitions of Analog read pins*/
#define X_AXIS_PIN A0
#define Y_AXIS_PIN A1
#define Z_AXIS_PIN A2

#define ADC_AMPLITUDE 1024//amplitude of the 10bit-ADC of Arduino is 1024LSB
#define ADC_REF 5   //ADC reference is 5v
#define ZERO_X  1.22 //accleration of X-AXIS is 0g, the voltage of X-AXIS is 1.22v
#define ZERO_Y  1.22 //
#define ZERO_Z  1.25 //
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
