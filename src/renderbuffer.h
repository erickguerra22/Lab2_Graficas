#pragma once
#include <SDL.h>
#include "framebuffer.h"

void renderBuffer(SDL_Renderer *renderer)
{
    // Create a texture
    SDL_Texture *texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGB24,
        SDL_TEXTUREACCESS_STREAMING,
        width,
        height);

    // Update the texture with the pixel data from the framebuffer
    SDL_UpdateTexture(
        texture,
        nullptr,
        &framebuffer[0],
        width * sizeof(Color));

    // Copy the texture to the renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Destroy the texture
    SDL_DestroyTexture(texture);
}