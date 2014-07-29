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

