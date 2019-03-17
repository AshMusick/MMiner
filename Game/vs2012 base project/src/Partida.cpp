
#include <windows.h>
#include <iostream>
#include "Partida.h"
//#include "Tablero.h"


King::Engine Partida::mEngine("./assets");	//Inicializacion del motor. Variable static

Partida::Partida()
{
	coordIniX = 0.0;
	coordIniY = 0.0;
	coordFinX = 0.0;
	coordFinY = 0.0;
	bool secondClick = false;
}

Partida::~Partida()
{
	delete this->tablero;
}

void Partida::Start()
{
	mEngine.Start(*this);
}

void Partida::Update()
{
	//Creador de tablero
	if (!gameFlag)
	{
		tablero = new Tablero();
		do{
			tablero->createBoard();
		} 
		while (tablero->checkBoard());
		gameFlag = true;
	}
	
	//Render
	Partida::mEngine.Render(King::Engine::TEXTURE_BACKGROUND, 0.0f, 0.0f);
	tablero->drawBoard();
	
	//Interaccion de usuario
	if (mEngine.GetMouseButtonDown()) 
	{
		if ((mEngine.GetMouseX() > 325.0f && mEngine.GetMouseX() < 685.0f) && 
			(mEngine.GetMouseY() > 100.0f && mEngine.GetMouseY() < 460.0f))
		{
			if (!secondClick) {
				//guardo coordenadas iniciales
				coordIniX = mEngine.GetMouseX();
				coordIniY = mEngine.GetMouseY();
				std::cout << "click 1" << std::endl;
				secondClick = true;
				Sleep(500);
			}
			else {
				//guardo coordenadas finales
				coordFinX = mEngine.GetMouseX();
				coordFinY = mEngine.GetMouseY();
				std::cout << "click 2" << std::endl;
				tablero->moveBoard(coordIniX, coordIniY, coordFinX, coordFinY);
				secondClick = false;
				Sleep(500);
			}
		}
	}
	//else if(mEngine.GetMouseButtonUp())
	//{
	//}
}


