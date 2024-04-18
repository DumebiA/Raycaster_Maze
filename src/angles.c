#include "../headers/main.h"

/**
 * deg - A function to convert a given value of either Gradients
 * or Radians to Degrees.
 *
 * @a: Value in Gradients or Radians
 * @b: 'g' for Gradient or 'r' for Radians
 * Return: Value in Degrees else -1
 */
double deg(float a, char b)
{
	if (b == 'g')
		a *= 0.9;
	else if (b == 'r')
		a = a * 180 / PI;
	else
		return (-1);

	return (a);
}

/**
 * grd - A function to convert a given value of either Degrees
 * or Radians to Gradients.
 *
 * @a: Value in Degrees or Radians
 * @b: 'd' for Degrees or 'r' for Radians
 * Return: Value in Gradients else -1
 */
double grd(float a, char b)
{
	if (b == 'd')
		a /= 0.9;
	else if (b == 'r')
		a = a * 200 / PI;
	else
		return (-1);

	return (a);
}

/**
 * rad - A function to convert a given value of either Degrees
 * or Gradients to Radians.
 *
 * @a: Value in Degrees or Gradients
 * @b: 'd' for Degrees or 'g' for Gradients
 * Return: Value in Radians else -1
 */
double rad(float a, char b)
{
	if (b == 'd')
		a = a * PI / 180;
	else if (b == 'g')
		a = a * PI / 200;
	else
		return (-1);

	return (a);
}
