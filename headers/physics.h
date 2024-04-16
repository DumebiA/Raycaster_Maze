#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include <math.h>

/* PI = 3.14159265358979323846 */
#define PI M_PI

/* CONVERSION OF ANGLES */
double deg(float a, char b);
double grd(float a, char b);
double rad(float a, char b);
float handle_mod1(float target);

#endif /* _PHYSICS_H_ */
