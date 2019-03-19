
#include "Gemas.h"
#include "Partida.h"


Gema::Gema(float x, float y, int c)
{
	this->coordy = y;
	this->coordx = x;
	this->color = c;
	MaxAncho = this->coordx + ANCHO;
	MaxAlto = this->coordy + ALTO;
	showing = true;
}

Gema::~Gema()
{
}

void Gema::Hide()
{
	if(this->showing)
		this->showing = false;
}

void Gema::Show()
{
	if (!this->showing)
		this->showing = true;
}

//DETECTO CUANDO EL MOUSE ESTA DENTRO DEL AREA QUE OCUPO
bool Gema::insideArea(float Cx, float Cy)
{
	return ((Cx > coordx) && (Cx < MaxAncho) && (Cy > coordy) && (Cy < MaxAlto));
}

void Gema::getCoords(float &x, float &y) {
	x = this->coordx;
	y = this->coordy;
}

void Gema::setCoords(float x, float y)
{
	this->coordx = x;
	this->coordy = y;
}

void Gema::setColor(int c)
{
	this->color = c;
}

void Gema::drawGemas()
{
	King::Engine::Texture textura;

	switch (this->color) 
	{
	case 0:
		textura = King::Engine::TEXTURE_GREEN;
		break;
	case 1:
		textura = King::Engine::TEXTURE_BLUE;
		break;
	case 2:
		textura = King::Engine::TEXTURE_RED;
		break;
	case 3:
		textura = King::Engine::TEXTURE_PURPLE;
		break;
	case 4:
		textura = King::Engine::TEXTURE_YELLOW;
		break;
	}
	showing = true;
	Partida::mEngine.Render(textura, this->coordx, this->coordy);
}

