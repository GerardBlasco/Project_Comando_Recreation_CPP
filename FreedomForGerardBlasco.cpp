// FreedomForGerardBlasco.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "Game.h"

int main()
{
    Game::Create();
    Game::Play();
    Game::Destroy();
}

// Clase Game: Singleton
// Se crea mediante método static Create()
// Constructor Privado
// Método estático público Play()
// Dentro del constructor de Game, se crea GraphicsInterface (variable puntero a GraphicsInterface)
// Método static Play debe llamar a GraphicsInterface para empezar la pantalla?
// Play tiene un loop infinito de juego (while !Gameover) o algo así
//
// Class Game:
// public static void Create();
// public static void Play();
//
// Clase GraphicsInterface:
// El constructor inicializa los graficos, abre la ventana
