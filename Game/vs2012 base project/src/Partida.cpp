
#include "Partida.h"
//#include "Tablero.h"


King::Engine Partida::mEngine("./assets");	//Inicializacion del motor. Variable static

void Partida::Start() 
{
	mEngine.Start(*this);
}

void Partida::Update()
{
	//Creador de tablero
	if (gameFlag == false)
	{
		do
		{
			tablero.createBoard();
		} 
		while (tablero.checkBoard() == true);
		gameFlag = true;
	}
	
	//Render
	Partida::mEngine.Render(King::Engine::TEXTURE_BACKGROUND, 0.0f, 0.0f);
	tablero.drawBoard();
	
	//Interaccion de usuario
	if (mEngine.GetMouseButtonDown()) 
	{
		if ((mEngine.GetMouseX() > 325.0f && mEngine.GetMouseX() < 685.0f) && 
			(mEngine.GetMouseY() > 100.0f && mEngine.GetMouseY() < 460.0f))
		{
			tablero.moveBoard(mEngine.GetMouseX(), mEngine.GetMouseY());
		}
	}
}


