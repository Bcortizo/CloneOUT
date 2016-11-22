#include "libUnicornio.h"
#pragma once
class Paleta
{
public:
	Paleta();
	~Paleta();

	void inicializar();
	void resetar();
	void atualizar();
	void desenhar();

	float getX();
	float getY();

private:
	float x, y, velocidade;
	Sprite sprite;
};

