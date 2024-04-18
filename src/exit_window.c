#include "../headers/main.h"

/**
 * done_esc - A function that returns 1 if you close the window or press the escape
 * key. Also handles everything that's needed per frame.
 *
 * @e: An SDL Event
 * @n: The delay flag (true or false)
 * @k: A boolean array to store key states
 * Return: Boolean success flag (true or flase)
 */
bool done_esc(SDL_Event *e, bool n, const unsigned char *k)
{
	/* delay gives CPU some free time */
	/* use once per frame to avoid 100% usage of a CPU core */
	if (n)
		SDL_Delay(5); /* so it consumes less processing power */
	SDL_PollEvent(e);
	/**
	 * while (SDL_PollEvent(event))
	 * {
	 *	if (event->type == SDL_QUIT)
	 *		return (true);
	 * }
	 */
	/* read_Keys(keys); */
	if (k[SDLK_ESCAPE])
		return (true);

	return (false);
}

/**
 * read_Keys - A function that gives value of pressed key to keys array.
 *
 * @k: A boolean array to store key states
 */
void read_Keys(const unsigned char *k)
{
	SDL_PumpEvents();
	k = SDL_GetKeyboardState(NULL);
	for (int n = 0; n < 1; n++)
	{
		if (k[n] == 1)
			break;
	}
}
