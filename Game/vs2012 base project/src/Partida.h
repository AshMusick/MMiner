#pragma once

#include <king/Engine.h>
#include <king/Updater.h>

#include "Tablero.h"


class Partida : public King::Updater
{

public:
	Partida();
	~Partida();
	void Start();
	void Update();
	static King::Engine mEngine;

private:
	float coordIniX;
	float coordIniY;
	float coordFinX;
	float coordFinY;
	bool secondClick;
	bool gameFlag = false;
	Tablero *tablero;

};