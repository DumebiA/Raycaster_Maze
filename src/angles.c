#include "../headers/main.h"

/**
 * deg - A function to convert a given value of either Gradients
 * or Radians to Degrees.
 *
 * @v: Value in Gradients or Radians
 * @f: 'g' for Gradient or 'r' for Radians
 * Return: Value in Degrees else -1
 */
double deg(float v, char f)
{
	if (f == 'g')
		v *= 0.9;
	else if (f == 'r')
		v = v * 180 / PI;
	else
		return (-1);

	return (v);
}

/**
 * grd - A function to convert a given value of either Degrees
 * or Radians to Gradients.
 *
 * @val: Value in Degrees or Radians
 * @format: 'd' for Degrees or 'r' for Radians
 * Return: Value in Gradients else -1
 */
double grd(float val, char format)
{
	if (format == 'd')
		val /= 0.9;
	else if (format == 'r')
		val = val * 200 / PI;
	else
		return (-1);

	return (val);
}

/**
 * rad - A function to convert a given value of either Degrees
 * or Gradients to Radians.
 *
 * @val: Value in Degrees or Gradients
 * @format: 'd' for Degrees or 'g' for Gradients
 * Return: Value in Radians else -1
 */
double rad(float val, char format)
{
	if (format == 'd')
		val = val * PI / 180;
	else if (format == 'g')
		val = val * PI / 200;
	else
		return (-1);

	return (val);
}
