/*
Basic SDL2 boilerplate using C/C++14.
Special thanks to the authors at:
https://www.parallelrealities.co.uk/tutorials/shooter/shooter1.php
https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html
for the C boilerplate.
*/

#include <iostream>

#include <SDL2/SDL.h>

#define SCREEN_WIDTH   400
#define SCREEN_HEIGHT  400

static SDL_Renderer* renderer = nullptr;
static SDL_Window* window = nullptr;

static bool done = false;

void initSDL()
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	window = SDL_CreateWindow("WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (window == nullptr)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	if (renderer == nullptr)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}

void doQuit()
{
	std::cout << "Got Quit Signal -- quitting\n";
	done = true;
}

void doInput()
{
	SDL_Event event;
	bool do_get_event = true;

	while (SDL_PollEvent(&event) && do_get_event)
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				// keys: https://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlkey.html
				if( event.key.keysym.sym == SDLK_ESCAPE )
				{
					std::cout << "ESCAPE_KEY\n";
					do_get_event = false;
					doQuit();
				}
				break;
			case SDL_QUIT:
				doQuit();
				break;

			default:
				break;
		}
	}
}

void cleanup()
{
	if(window)
		SDL_DestroyWindow(window);

	SDL_Quit();
}

int main(int argc, char** argv)
{
	initSDL();

	atexit(cleanup);

	while (!done)
	{
		//prepareScene();
		doInput();
		//presentScene();

		SDL_Delay(16);
	}
	
	std::cout << "Done.\n";
	
	return EXIT_SUCCESS;
}

