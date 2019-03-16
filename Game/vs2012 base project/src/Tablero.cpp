
#include "Partida.h"
#include "Tablero.h"
//#include "Gemas.h"

#include <cstdlib>
#include <ctime>

#include <iostream>


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
}
	
void Tablero::drawBoard() 
{
	//Llamado a Gemas para dibujar el tablero
	for (int j = 0; j < 8; j++) 
	{
		for (int i = 0; i < 8; i++)
		{
			if (Partida::mEngine.GetMouseButtonDown())
			{
				posX = (Partida::mEngine.GetMouseX() - 325.0f) / 45.0f;
				posY = (Partida::mEngine.GetMouseY() - 100.0f) / 45.0f;

				if (i != posX || j != posY)
				{
					gemas.drawGemas(boardX[i], boardY[j], boardC[j][i]);
				}
			}
			else
			{
				gemas.drawGemas(boardX[i], boardY[j], boardC[j][i]);
			}
		}
	}
}

bool Tablero::checkBoard()
{
	//Chequeo sin modificacion
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((boardC[j][i] == boardC[j][i+1]) && (boardC[j][i] == boardC[j][i+2])) 
			{
				return true;
			}
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((boardC[j][i] == boardC[j+1][i]) && (boardC[j][i] == boardC[j+2][i]))
			{
				return true;
			}
		}
	}
	return false;
}

void Tablero::moveBoard(float x, float y)
{
	if (clickFlag == false)
	{
		firstPosX = posX;
		firstPosY = posY;	//estas variables son asignadas en la llamada a drawBoard() hecha en el update siempre antes de moveBoard()
		std::cout << "true";
		clickFlag = true;
	}

	if ((firstPosX != posX || firstPosY != posY) && clickFlag == true)
	{
		int valX = posX;
		int valY = posY;
		boardC[posY][posX] = boardC[firstPosY][firstPosX];
		boardC[firstPosY][firstPosX] = boardC[valY][valX];

		clickFlag = false;
	}

	gemas.drawGemas(x, y, boardC[firstPosY][firstPosX]);
}

