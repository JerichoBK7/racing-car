/*************************************************************************/
/*                             B A T T E R Y                             */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 * @file _battery.h
 * Implementation of battery for the car
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef _BATTERY_H
#define _BATTERY_H

#include "stdlib.h"
#include "BMPLoader.h"
#include "superficie.h"
#include "random.h"
#include "primitivas.h"

class _battery
{
private:
    vector<BMPClass *> bateria;
    vector<superficie> battery;
    _object3D *juntas,*juntas2;
public:
    /*Constructor*/
    _battery();
    /*Destructor*/
    ~_battery();
    /*Otros metodos*/
    void draw(int);
};

#endif // _BATTERY_H
