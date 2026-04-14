#include "GraphicsInterface.h"
#include "Parameters.h"
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_ttf/SDL_ttf.h"

GraphicsInterface::GraphicsInterface()
{
	//Abrimos ventana e inicializamos gráficos
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init(); // Para la fuente del texto

	SDL_CreateWindowAndRenderer(Parameters::window_title, Parameters::width, Parameters::height, 0, &window, &renderer);

	font = TTF_OpenFont("Assets/Fuentes/VCR_OSD_MONO_1.001.ttf", 32); //Fuente de texto
	if (!font) {
		std::cout << "No se ha encontrado la fuente";
	}

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
	rect.x = transform.position.x - (width / 2); // Se le resta la mitad de su ancho y alto...
	rect.y = transform.position.y - (height / 2); // ...para que el "pivote" quede en el centro del sprite
	rect.w = width;
	rect.h = height;

	SDL_RenderTexture(renderer, imageColection[imgName], NULL, &rect);
}

//Metodo para dibujar texto en el juego
void GraphicsInterface::DrawText(const std::string& text, int x, int y)
{
	if (!font) return;

	SDL_Color color = { 255, 255, 255, 255 };

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), text.length(), color);
	if (!surface) return;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		SDL_DestroySurface(surface);
		return;
	}

	SDL_FRect rect;
	rect.x = x;
	rect.y = y;
	rect.w = surface->w;
	rect.h = surface->h;

	SDL_RenderTexture(renderer, texture, NULL, &rect);

	SDL_DestroyTexture(texture);
	SDL_DestroySurface(surface);
}