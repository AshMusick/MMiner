#pragma once

#include "Gemas.h"
#define MAX_LINES 8
#define MAX_COLUMNS 8

class Tablero 
{

public:

	Tablero(int Puntaje);
	~Tablero();
	void createBoard();
	void refillBoard();
	void moveBoard(float x, float y, float finx, float finy);
	bool consecutivas(Gema * origen, Gema * destino);
	int getPuntaje() { return this->Puntaje; }
	void drawBoard();
	bool checkBoard();

private:
	
	void swapGemas(Gema * origen, Gema * destino);
	Gema * getGema(float x, float y,bool esOrigen);

	Gema* gemas[MAX_LINES][MAX_COLUMNS];
	float boardX[MAX_COLUMNS] =			{ 325.0f , 370.0f , 415.0f , 460.0f , 505.0f , 550.0f , 595.0f , 640.0f };
	float boardY[MAX_LINES] =			{ 100.0f , 145.0f , 190.0f , 235.0f , 280.0f , 325.0f , 370.0f , 415.0f };
	int boardC[MAX_LINES][MAX_COLUMNS];		//Puedo hacer estas variables static, y luego ir modificando sus valores?
	float firstPosMouseX;
	float firstPosMouseY;
	float LastPosMouseX;
	float LastPosMouseY;
	int Puntaje;
	int posX;
	int posY;
	int colOrigen;
	int rengOrigen;
	int colDest;
	int rengDest;

};
