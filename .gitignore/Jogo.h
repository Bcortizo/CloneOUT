#pragma once
#include "libUnicornio.h"
#include "Paleta.h"
#include "Bloco.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	Paleta paleta;
	Bloco *blocos; // tipos de blocos diferentes possíveis
	int offsetH, offsetV;
	int **iBlocos;
};

