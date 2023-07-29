#pragma once
#include "color.h"
#include "vertex2.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <stack>
#include <random>

int width = 100;
int height = 100;
std::vector<Color> framebuffer;
Color clearColor = Color(0, 0, 0);
Color currentColor = Color(255, 255, 255);

void clear()
{
    framebuffer.resize(width * height);
    fill(framebuffer.begin(), framebuffer.end(), clearColor);
}

void setClearColor(Color newColor)
{
    clearColor = newColor;
}

void setCurrentColor(Color newColor)
{
    currentColor = newColor;
}

void setSize(int newW, int newH)
{
    width = newW;
    height = newH;
    framebuffer.resize(width * height);
    clear();
}

// Función punto
void point(Vertex2 vertex)
{
    int index = static_cast<int>(vertex.y) * width + static_cast<int>(vertex.x);
    if (index >= 0 && index <= framebuffer.size())
        framebuffer[index] = currentColor;
}

// Devolver framebuffer como array
Color *getAsArray()
{
    if (framebuffer.empty())
        return nullptr;
    return &framebuffer[0];
}

void block(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x, y + 1});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x + 1, y});
}

void blinker(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x, y + 1});
    point(Vertex2{x, y + 2});
}

void glider(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x + 2, y + 1});
    point(Vertex2{x + 1, y + 2});
    point(Vertex2{x, y + 2});
}

void beeHive(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x + 1, y});
    point(Vertex2{x + 2, y + 1});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x, y + 2});
    point(Vertex2{x + 1, y + 2});
}

void toad(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x + 1, y + 2});
    point(Vertex2{x - 2, y + 1});
    point(Vertex2{x - 2, y + 2});
    point(Vertex2{x - 1, y + 3});
}

void lwss(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x + 1, y});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x, y + 1});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x + 2, y + 1});
    point(Vertex2{x - 1, y + 2});
    point(Vertex2{x, y + 2});
    point(Vertex2{x + 1, y + 3});
    point(Vertex2{x + 2, y + 2});
    point(Vertex2{x + 3, y + 2});
    point(Vertex2{x + 2, y + 3});
}

void loaf(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x + 1, y});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x, y + 2});
    point(Vertex2{x + 1, y + 3});
    point(Vertex2{x + 2, y + 2});
    point(Vertex2{x + 2, y + 1});
}

void beacon(float x, float y)
{
    point(Vertex2{x, y});
    point(Vertex2{x + 1, y});
    point(Vertex2{x, y + 1});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x + 2, y + 2});
    point(Vertex2{x + 3, y + 2});
    point(Vertex2{x + 3, y + 3});
    point(Vertex2{x + 2, y + 3});
}

void mwss(float x, float y)
{
    point(Vertex2{x + 0, y + 0});
    point(Vertex2{x + 1, y + 0});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x + 2, y + 1});
    point(Vertex2{x - 3, y + 1});
    point(Vertex2{x - 2, y + 1});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x - 3, y + 2});
    point(Vertex2{x - 2, y + 2});
    point(Vertex2{x - 1, y + 2});
    point(Vertex2{x + 0, y + 2});
    point(Vertex2{x + 1, y + 2});
    point(Vertex2{x - 2, y + 3});
    point(Vertex2{x - 1, y + 3});
    point(Vertex2{x + 0, y + 3});
}

void boat(float x, float y)
{
    point(Vertex2{x + 0, y + 0});
    point(Vertex2{x + 1, y + 0});
    point(Vertex2{x + 0, y + 1});
    point(Vertex2{x + 2, y + 1});
    point(Vertex2{x + 1, y + 2});
}

void tub(float x, float y)
{
    point(Vertex2{x + 0, y + 0});
    point(Vertex2{x - 1, y - 1});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x + 0, y - 2});
}

void pulsar(float x, float y)
{
    // Primera figura pulsar
    point(Vertex2{x, y});
    point(Vertex2{x + 6, y});
    point(Vertex2{x, y + 1});
    point(Vertex2{x + 6, y + 1});
    point(Vertex2{x, y + 2});
    point(Vertex2{x + 1, y + 2});
    point(Vertex2{x + 6, y + 2});
    point(Vertex2{x + 5, y + 2});
    point(Vertex2{x - 4, y + 4});
    point(Vertex2{x - 3, y + 4});
    point(Vertex2{x - 2, y + 4});
    point(Vertex2{x + 1, y + 4});
    point(Vertex2{x + 2, y + 4});
    point(Vertex2{x + 4, y + 4});
    point(Vertex2{x + 5, y + 4});
    point(Vertex2{x + 8, y + 4});
    point(Vertex2{x + 9, y + 4});
    point(Vertex2{x + 10, y + 4});
    point(Vertex2{x - 2, y + 5});
    point(Vertex2{x, y + 5});
    point(Vertex2{x + 2, y + 5});
    point(Vertex2{x + 4, y + 5});
    point(Vertex2{x + 6, y + 5});
    point(Vertex2{x + 8, y + 5});
    point(Vertex2{x, y + 6});
    point(Vertex2{x + 1, y + 6});
    point(Vertex2{x + 5, y + 6});
    point(Vertex2{x + 6, y + 6});

    // Segunda figura pulsar
    point(Vertex2{x, y + 8});
    point(Vertex2{x + 1, y + 8});
    point(Vertex2{x + 5, y + 8});
    point(Vertex2{x + 6, y + 8});
    point(Vertex2{x - 2, y + 9});
    point(Vertex2{x, y + 9});
    point(Vertex2{x + 2, y + 9});
    point(Vertex2{x + 4, y + 9});
    point(Vertex2{x + 5, y + 9});
    point(Vertex2{x + 8, y + 9});
    point(Vertex2{x - 4, y + 10});
    point(Vertex2{x - 3, y + 10});
    point(Vertex2{x - 2, y + 10});
    point(Vertex2{x + 1, y + 10});
    point(Vertex2{x + 2, y + 10});
    point(Vertex2{x + 4, y + 10});
    point(Vertex2{x + 5, y + 10});
    point(Vertex2{x + 8, y + 10});
    point(Vertex2{x + 9, y + 10});
    point(Vertex2{x + 10, y + 10});
    point(Vertex2{x, y + 12});
    point(Vertex2{x + 1, y + 12});
    point(Vertex2{x + 5, y + 12});
    point(Vertex2{x + 6, y + 12});
    point(Vertex2{x, y + 13});
    point(Vertex2{x + 6, y + 13});
    point(Vertex2{x, y + 14});
    point(Vertex2{x + 6, y + 14});
}

void hwss(float x, float y)
{
    point(Vertex2{x + 0, y + 0});
    point(Vertex2{x + 1, y + 0});
    point(Vertex2{x + 2, y + 0});
    point(Vertex2{x + 3, y + 0});
    point(Vertex2{x + 4, y + 0});
    point(Vertex2{x + 5, y + 0});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x + 5, y + 1});
    point(Vertex2{x + 5, y + 2});
    point(Vertex2{x - 1, y + 3});
    point(Vertex2{x + 4, y + 3});
    point(Vertex2{x + 1, y + 4});
    point(Vertex2{x + 2, y + 4});
}

void pentaDecathlon(float x, float y)
{
    point(Vertex2{x + 0, y + 0});
    point(Vertex2{x - 1, y + 1});
    point(Vertex2{x + 0, y + 1});
    point(Vertex2{x + 1, y + 1});
    point(Vertex2{x - 1, y + 4});
    point(Vertex2{x + 0, y + 4});
    point(Vertex2{x + 1, y + 4});
    point(Vertex2{x - 1, y + 6});
    point(Vertex2{x + 1, y + 6});
    point(Vertex2{x - 1, y + 7});
    point(Vertex2{x + 1, y + 7});
    point(Vertex2{x - 1, y + 9});
    point(Vertex2{x + 0, y + 9});
    point(Vertex2{x + 1, y + 9});
    point(Vertex2{x - 1, y + 12});
    point(Vertex2{x + 0, y + 12});
    point(Vertex2{x + 1, y + 12});
    point(Vertex2{x + 0, y + 13});
}

void initialState()
{
    unsigned int seed = 3487529461;
    std::mt19937 rng(seed);

    std::uniform_int_distribution<> dis_x(0, width - 1);
    std::uniform_int_distribution<> dis_y(0, height - 1);

    for (int i = 0; i < (width * height) / std::min(height, width) * 2; i++)
    {
        int x = dis_x(rng);
        int y = dis_y(rng);

        if (i % 23 == 0)
            toad(x, y);
        else if (i % 19 == 0)
            lwss(x, y);
        else if (i % 17 == 0)
            glider(x, y);
        else if (i % 13 == 0)
            beacon(x, y);
        else if (i % 11 == 0)
            mwss(x, y);
        else if (i % 7 == 0)
            boat(x, y);
        else if (i % 5 == 0)
            tub(x, y);
        else if (i % 3 == 0)
            pentaDecathlon(x, y);
        else if (i % 2 == 0)
            hwss(x, y);
        else
            pulsar(x, y);
    }
}

void conwaysGame()
{
    std::vector<Color> newFB = framebuffer;
    for (int currentY = 0; currentY < height; currentY++)
    {
        for (int currentX = 0; currentX < width; currentX++)
        {
            int aliveNbrs = 0;
            Color pixelColor = framebuffer[currentY * width + currentX];

            // Obtener pixeles adyacentes vivos
            // esquina superior izquierda
            if ((currentX > 0 && currentY > 0 && framebuffer[(currentY - 1) * width + (currentX - 1)] == currentColor) || (currentX == 0 && currentY == 0 && framebuffer[(height - 1) * width + (width - 1)] == currentColor) || (currentY == 0 && currentX > 0 && framebuffer[(height - 1) * width + (currentX - 1)] == currentColor) || (currentX == 0 && currentY > 0 && framebuffer[(currentY - 1) * width + (width - 1)] == currentColor))
                aliveNbrs++;

            // esquina superior derecha
            if ((currentY > 0 && currentX < width - 1 && framebuffer[(currentY - 1) * width + (currentX + 1)] == currentColor) || (currentY == 0 && currentX == width - 1 && framebuffer[(height - 1) * width + 0] == currentColor) || (currentY == 0 && currentX < width - 1 && framebuffer[(height - 1) * width + (currentX + 1)] == currentColor) || (currentX == width - 1 && currentY > 0 && framebuffer[(currentY - 1) * width + 0] == currentColor))
                aliveNbrs++;

            // esquina inferior izquierda
            if ((currentY < height - 1 && currentX > 0 && framebuffer[(currentY + 1) * width + (currentX - 1)] == currentColor) || (currentY == height - 1 && currentX == 0 && framebuffer[0 * width + (width - 1)] == currentColor) || (currentY == height - 1 && currentX > 0 && framebuffer[0 * width + (currentX - 1)] == currentColor) || (currentX == 0 && currentY < height - 1 && framebuffer[(currentY + 1) * width + (width - 1)] == currentColor))
                aliveNbrs++;

            // esquina inferior derecha
            if ((currentY < height - 1 && currentX < width - 1 && framebuffer[(currentY + 1) * width + (currentX + 1)] == currentColor) || (currentY == height - 1 && currentX == width - 1 && framebuffer[0] == currentColor) || (currentY == height - 1 && currentX < width - 1 && framebuffer[0 * width + (currentX + 1)] == currentColor) || (currentX == width - 1 && currentY < height - 1 && framebuffer[(currentY + 1) * width + 0] == currentColor))
                aliveNbrs++;

            // arriba
            if ((currentY > 0 && framebuffer[(currentY - 1) * width + currentX] == currentColor) || (currentY == 0 && framebuffer[(height - 1) * width + currentX] == currentColor))
                aliveNbrs++;

            // izquierda
            if ((currentX > 0 && framebuffer[currentY * width + (currentX - 1)] == currentColor) || (currentX == 0 && framebuffer[currentY * width + (width - 1)] == currentColor))
                aliveNbrs++;

            // derecha
            if ((currentX < width - 1 && framebuffer[currentY * width + (currentX + 1)] == currentColor) || (currentX == width - 1 && framebuffer[currentY * width + 0] == currentColor))
                aliveNbrs++;

            // abajo
            if ((currentY < height - 1 && framebuffer[(currentY + 1) * width + currentX] == currentColor) || (currentY == height - 1 && framebuffer[0 * width + currentX] == currentColor))
                aliveNbrs++;

            // Reglas del juego de Conway
            if (pixelColor == clearColor && aliveNbrs == 3)
                newFB[currentY * width + currentX] = currentColor;
            else if (pixelColor == currentColor && (aliveNbrs < 2 || aliveNbrs > 3))
                newFB[currentY * width + currentX] = clearColor;
        }
    }
    framebuffer = newFB;
}