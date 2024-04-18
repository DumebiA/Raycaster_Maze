#include "../headers/main.h"

/**
 * color_code - A code to return the RGBA code of the requested color
 *
 * @c: An array of characters (string) specifying the requested color
 * Return: A struct of type ColorRGBA for the requested color
 */
ColorRGBA color_code(char *c)
{
	ColorRGBA RGB_Black = {0, 0, 0, 1.0};
	ColorRGBA RGB_Red = {255, 0, 0, 1.0};
	ColorRGBA RGB_Orange = {255, 165, 0, 1.0};
	ColorRGBA RGB_Yellow = {255, 255, 0, 1.0};
	ColorRGBA RGB_Green = {0, 128, 0, 1.0};
	ColorRGBA RGB_Blue = {0, 0, 255, 1.0};
	ColorRGBA RGB_Indigo = {75, 0, 130, 1.0};
	ColorRGBA RGB_Violet = {238, 130, 238, 1.0};
	ColorRGBA RGB_White = {255, 255, 255, 1.0};

	if (!strcmp(c, "red"))
		return (RGB_Red);
	else if (!strcmp(c, "green"))
		return (RGB_Green);
	else if (!strcmp(c, "blue"))
		return (RGB_Blue);
	else if (!strcmp(c, "yellow"))
		return (RGB_Yellow);
	else if (!strcmp(c, "orange"))
		return (RGB_Orange);
	else if (!strcmp(c, "blue"))
		return (RGB_Blue);
	else if (!strcmp(c, "indigo"))
		return (RGB_Indigo);
	else if (!strcmp(c, "violet"))
		return (RGB_Violet);
	else if (!strcmp(c, "white"))
		return (RGB_White);
	else if (!strcmp(c, "black"))
		return (RGB_Black);
	else
		return (RGB_Black);
}

/**
 * color_walls - Assigns a color code to each integer case
 *
 * @worldMap: A 2-dimensional array of integer values
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @color: struct of type ColorRGBA containing the RGBA value of given color
 * @side: Side of the wall that was hit (NS or EW)
 */
void walls_paint(int (*worldmap)[MAP_WIDTH], int mX, int mY,
				ColorRGBA *paint, int s)
{
	switch (worldmap[mX][mY])
	{
		case 1:
			*paint = color_code("red");
			break;
		case 2:
			*paint = color_code("green");
			break;
		case 3:
			*paint = color_code("blue");
			break;
		case 4:
			*paint = color_code("white");
			break;
		default:
			*paint = color_code("yellow");
			break;
	}

	/* give x and y sides different brightness */
	if (s == 1)
		rgba_div(paint, 2, 1.0);
}

/**
 * color_wall - Assigns a color code to each integer case
 *
 * @wall_code: An integer value for the wall
 * @side: Side of the wall that was hit (NS or EW)
 * Return: A struct of type ColorRGBA for the requested color
 */
ColorRGBA color_wall(int wall_code, int side)
{
	ColorRGBA color;

	switch (wall_code)
	{
		case 1:
			color = rgba_color_code("red");
			break;
		case 2:
			color = rgba_color_code("green");
			break;
		case 3:
			color = rgba_color_code("blue");
			break;
		case 4:
			color = rgba_color_code("white");
			break;
		default:
			color = rgba_color_code("yellow");
			break;
	}

	/* give x and y sides different brightness */
	if (side == 1)
		rgba_div(&color, 2, 1.0);

	return (color);
}
