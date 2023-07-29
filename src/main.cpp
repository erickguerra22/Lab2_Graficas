#include <SDL.h>
#include "framebuffer.h"
#include "renderbuffer.h"

int scale = 4;

void render(SDL_Renderer *renderer)
{
  // Render the framebuffer to the screen
  renderBuffer(renderer);

  conwaysGame();
}

int main(int argv, char **args)
{
  setSize(GetSystemMetrics(SM_CXSCREEN) / scale, (GetSystemMetrics(SM_CYSCREEN) - 25) / scale);

  initialState();

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window = SDL_CreateWindow("Lab 2: Conway’s Game Of Life", 0, 25, width * scale, height * scale, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_RenderSetScale(renderer, scale, scale);

  SDL_Event event;

  bool isRunning = true;
  while (isRunning)
  {
    while (SDL_PollEvent(&event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
        isRunning = false;
      }
    }

    render(renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(100);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}