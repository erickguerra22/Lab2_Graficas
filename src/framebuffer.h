#pragma once
#include "color.h"
#include "vertex2.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <stack>

int width = GetSystemMetrics(SM_CXSCREEN);
int height = GetSystemMetrics(SM_CYSCREEN) - 25;
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