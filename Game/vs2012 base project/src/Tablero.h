#pragma once

#include "Gemas.h"

class Tablero 
{

public:
	void createBoard();
	void drawBoard();
	bool checkBoard();
	void moveBoard(float x, float y);

private:
	Gemas gemas;
	float boardX[8] = { 325.0f , 370.0f , 415.0f , 460.0f , 505.0f , 550.0f , 595.0f , 640.0f };
	float boardY[8] = { 100.0f , 145.0f , 190.0f , 235.0f , 280.0f , 325.0f , 370.0f , 415.0f };
	int boardC[8][8];		//Puedo hacer estas variables static, y luego ir modificando sus valores?
	bool clickFlag = false;
	int firstPosX;
	int firstPosY;
	int posX;
	int posY;

};
