#include "Bloco.h"



Bloco::Bloco()
{
	ID = 0;
}


Bloco::~Bloco()
{
}

void Bloco::inicializar(int id, string nomeBloco)
{
	ID = id;

	// seta o sprite "nomeBloco" já com o caminho de arquivo certo
	if (!gRecursos.carregouSpriteSheet(nomeBloco))
	{
		gRecursos.carregarSpriteSheet(nomeBloco, "imagens/" + nomeBloco + ".png");
	}

	sprite.setSpriteSheet(nomeBloco);
}


void Bloco::desenhar(float x, float y)
{
	if (ID != 0)
	{
		sprite.desenhar(x, y);
	}
}

float Bloco::getLargura()
{
	return sprite.getLargura();
}

float Bloco::getAltura()
{
	return sprite.getAltura();
}
