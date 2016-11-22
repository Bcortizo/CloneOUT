#pragma once
#include "libUnicornio.h"
class Bloco
{
public:
	Bloco();
	~Bloco();

	void inicializar(int id, string nomeBloco);
	void resetar();
	void atualizar();
	void desenhar(float x, float y);

	float getLargura();
	float getAltura();

private:
	Sprite sprite;
	int ID;
};

