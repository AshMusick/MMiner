
#include <windows.h>
#include <iostream>
#include <string>
#include "Partida.h"
//#include "Tablero.h"


King::Engine Partida::mEngine("./assets");	//Inicializacion del motor. Variable static

Partida::Partida()
{
	coordIniX = 0.0;
	coordIniY = 0.0;
	coordFinX = 0.0;
	coordFinY = 0.0;
	Puntaje = 0;
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
		tablero = new Tablero(Puntaje);
		time(&this->TiempoInicio);
		do{
			tablero->createBoard();
		} 
		while (tablero->checkBoard());
		gameFlag = true;
	}
	
	//tiempo actual
	time(&this->TiempoActual);
	//Render
	Partida::mEngine.Render(King::Engine::TEXTURE_BACKGROUND, 0.0f, 0.0f);
	//Nombre del jugador
	Partida::mEngine.Write("Jugador: Lucho", 350, 50.0f); 
	//puntaje
	this->Puntaje = tablero->getPuntaje();
	string puntajeConcatenado = "Puntaje: " + std::to_string(this->Puntaje);
	Partida::mEngine.Write(puntajeConcatenado.c_str(), 30.0f , 100.0f );
	//tiempo
	double seconds = difftime(this->TiempoActual, this->TiempoInicio);
	string tiempoconcatenado = "Tiempo: " + std::to_string(seconds);
	int indexDePunto = tiempoconcatenado.find(".");
	Partida::mEngine.Write(tiempoconcatenado.substr(0, indexDePunto + 2).c_str(), 30.0f , 200.0f);

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
				Sleep(100);
			}
			else {
				//guardo coordenadas finales
				coordFinX = mEngine.GetMouseX();
				coordFinY = mEngine.GetMouseY();
				std::cout << "click 2" << std::endl;
				tablero->moveBoard(coordIniX, coordIniY, coordFinX, coordFinY);
				secondClick = false;
				Sleep(100);
			}
		}
	}
	//else if(mEngine.GetMouseButtonUp())
	//{
	//}
}


