#include <SDL.h>
#include "framebuffer.h"
#include "renderbuffer.h"

float x = 10;
float y = 10;

void render(SDL_Renderer *renderer)
{

  // Clear the framebuffer
  clear();

  // Draw a point
  point(Vertex2{x++, y++});

  // Render the framebuffer to the screen
  renderBuffer(renderer);
}

int main(int argv, char **args)
{
  setSize(1000, 1000);
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window = SDL_CreateWindow("Lab 2: Conway’s Game Of Life", 0, 25, width, height, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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