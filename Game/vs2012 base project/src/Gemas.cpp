
#include "Gemas.h"
#include "Partida.h"


void Gemas::drawGemas(float x, float y, int c)
{
	switch (c) 
	{
	case 0:
		Partida::mEngine.Render(King::Engine::TEXTURE_GREEN, x, y);
		break;
	case 1:
		Partida::mEngine.Render(King::Engine::TEXTURE_BLUE, x, y);
		break;
	case 2:
		Partida::mEngine.Render(King::Engine::TEXTURE_RED, x, y);
		break;
	case 3:
		Partida::mEngine.Render(King::Engine::TEXTURE_PURPLE, x, y);
		break;
	case 4:
		Partida::mEngine.Render(King::Engine::TEXTURE_YELLOW, x, y);
		break;
	}
}

