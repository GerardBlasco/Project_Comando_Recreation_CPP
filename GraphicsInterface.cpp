#include "GraphicsInterface.h"
#include "Parameters.h"
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

GraphicsInterface::GraphicsInterface()
{
	//Abrimos ventana e inicializamos gráficos
	SDL_Init(SDL_INIT_VIDEO);

	SDL_CreateWindowAndRenderer(Parameters::window_title, Parameters::width, Parameters::height, 0, &window, &renderer);
}

GraphicsInterface::~GraphicsInterface()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool GraphicsInterface::LoadImage(std::string path)
{
	SDL_Texture* txt = IMG_LoadTexture(renderer, path.c_str());

	imageColection.insert(std::make_pair(path, txt));

	return false;
}

bool GraphicsInterface::MustWindowClose()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) return true;
	}

	return false;
}

void GraphicsInterface::ClearFrame()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void GraphicsInterface::DrawFrame()
{
	SDL_RenderPresent(renderer);
}

void GraphicsInterface::DrawSprite(std::string imgName, Transform transform, float width, float height)
{
	SDL_FRect rect;
	rect.x = transform.position.x;
	rect.y = transform.position.y;
	rect.w = width;
	rect.h = height;

	SDL_RenderTexture(renderer, imageColection[imgName], NULL, &rect);
}
