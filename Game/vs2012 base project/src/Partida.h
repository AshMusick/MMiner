#pragma once

#include <king/Engine.h>
#include <king/Updater.h>

#include "Tablero.h"


class Partida : public King::Updater
{

public:
	void Start();
	void Update();
	static King::Engine mEngine;

private:
	bool gameFlag = false;
	Tablero tablero;

};