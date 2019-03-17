
#include "Partida.h"
#include "Tablero.h"
//#include "Gemas.h"

#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <iostream>


Tablero::Tablero()
{
	//aca tendria q cargar las coordenadas
}

Tablero::~Tablero()
{
	for (size_t i = 0; i < MAX_LINES; i++)
	{
		for (size_t j = 0; j < MAX_COLUMNS; j++)
		{
			delete gemas[i][j];
		}
	}
}

void Tablero::createBoard()
{
	//Creacion de tablero aleatorio
	srand(time(0));
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			boardC[j][i] = (0 + (rand() % 4));
		}
	}

	//Chequeo y modificacion
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((boardC[j][i] == boardC[j][i + 1]) && (boardC[j][i] == boardC[j][i + 2]))
			{
				boardC[j][i+1] = (0 + (rand() % 4));
			}
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((boardC[j][i] == boardC[j + 1][i]) && (boardC[j][i] == boardC[j + 2][i]))
			{
				boardC[j+1][i] = (0 + (rand() % 4));
			}
		}
	}
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			gemas[j][i] = new Gema(boardX[i], boardY[j], boardC[j][i]);
		}
	}
}

void Tablero::refillBoard()
{
	std::cout << __func__ <<  std::endl;
	//Llamado a Gemas para dibujar el tablero
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (!gemas[j][i]->isShowing())

				gemas[j][i]->setColor((0 + (rand() % 4)));
		}
	}
}
	
void Tablero::drawBoard() 
{
	//Llamado a Gemas para dibujar el tablero
	for (int j = 0; j < 8; j++) 
	{
		for (int i = 0; i < 8; i++)
		{
			if(gemas[j][i]->isShowing())
				gemas[j][i]->drawGemas();
		}
	}
}

bool Tablero::checkBoard()
{
	std::cout << __func__ << std::endl;
	//Chequeo sin modificacion
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((gemas[j][i]->getColor() == gemas[j][i+1]->getColor()) && (gemas[j][i]->getColor() == gemas[j][i+2]->getColor()))
			{
				std::cout << __func__ << "Encontre MATCH horizontal !" << std::endl;
				gemas[j][i]->Hide();
				gemas[j][i+1]->Hide();
				gemas[j][i+2]->Hide();
				return true;
			}
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((gemas[j][i]->getColor() == gemas[j+1][i]->getColor()) && (gemas[j][i]->getColor() == gemas[j+2][i]->getColor()))
			{
				std::cout << __func__ <<"Encontre MATCH vertical !" << std::endl;
				gemas[j][i]->Hide();
				gemas[j + 1][i]->Hide();
				gemas[j + 2][i]->Hide();
				return true;
			}
		}
	}
	return false;
}

void Tablero::moveBoard(float inix, float iniy, float finx, float finy)
{

	if((inix != finx) || (iniy != finy)){
		firstPosMouseX = inix;
		firstPosMouseY = iniy;
		LastPosMouseX = finx;
		LastPosMouseY = finy;
		Gema *origen = getGema(firstPosMouseX, firstPosMouseY, true);
		Gema *destino = getGema(LastPosMouseX, LastPosMouseY, false);

		if ((origen != nullptr) && (destino != nullptr)) {

			swapGemas(origen, destino);
			
			//hay alguna ocurrencia??
			if (checkBoard()) {
				drawBoard();
				Sleep(500);
				//vuelvo a llenar las vacias
				refillBoard();
				drawBoard();
			}
			else {
				//vuelvo atras el movimiento
				swapGemas(destino,origen);
				drawBoard();
			}
		}
		else
			std::cout << __func__ << " gemas nulas " << std::endl;

	}

	//gemas.drawGemas(x, y, boardC[firstPosY][firstPosX]);
}

bool Tablero::consecutivas(Gema * origen, Gema * destino) {
	float auxOX, auxOY, auxDX, auxDY;

	origen->getCoords(auxOX, auxOY);
	destino->getCoords(auxDX, auxDY);

	return ((abs(auxOX - auxDX) <= ANCHO) && (abs(auxOY - auxDY) <= ALTO));
}

void Tablero::swapGemas(Gema * origen, Gema * destino) {
	std::cout << __func__ << std::endl;
	
	float auxOX, auxOY, auxDX, auxDY;

	if (consecutivas(origen, destino)) {
		destino->getCoords(auxDX, auxDY);
		origen->getCoords(auxOX, auxOY);
		destino->setCoords(auxOX, auxOY);
		origen->setCoords(auxDX, auxDY);
		Gema * aux = gemas[this->rengOrigen][this->colOrigen];
		gemas[this->rengOrigen][this->colOrigen] = gemas[this->rengDest][this->colDest];
		gemas[this->rengDest][this->colDest] = aux;
	}
	else
		std::cout << __func__ << " No hago el swap, porque no son consecutivas" << std::endl;
}

Gema * Tablero::getGema(float x, float y, bool esOrigen)
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (gemas[j][i]->insideArea(x, y)) {
				if (esOrigen) {
					this->colOrigen = i;
					this->rengOrigen = j;
				}
				else {
					this->colDest = i;
					this->rengDest = j;
				}

				return gemas[j][i];
			}
		}
	}
	return nullptr;
}

