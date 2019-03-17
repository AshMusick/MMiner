#pragma once

#define ANCHO 45
#define ALTO 45

using namespace std;

class Gema
{
	float coordx;
	float coordy;
	int color;
	float MaxAncho;
	float MaxAlto;
	bool showing;
public:
	Gema(float x, float y, int c);
	~Gema();
	void Hide();
	bool isShowing() { return this->showing; }
	bool insideArea(float , float);
	void getCoords(float &x, float &y);
	void setCoords(float, float);
	void setColor(int);
	void drawGemas();
	// Overload ~ operator
	Gema operator * (const Gema &b) {
		Gema res(0,0,0);
		res.coordx = b.coordx;
		res.coordy = b.coordy;
		return res;
	}
};
