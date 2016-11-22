#include "Paleta.h"



Paleta::Paleta()
{
}


Paleta::~Paleta()
{
}

void Paleta::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("barra"))
	{
		gRecursos.carregarSpriteSheet("barra", "imagens/barra.png");
	}
	sprite.setSpriteSheet("barra");

	x = gJanela.getLargura() / 2;
	y = gJanela.getAltura() - sprite.getAltura() / 2;
	velocidade = 3.5;
}

void Paleta::atualizar()
{
	if (gTeclado.segurando[TECLA_ESQ] || gTeclado.segurando[TECLA_A])
	{
		if (x > sprite.getLargura() / 2)
		{
			x -= velocidade;
		}
	}

	if (gTeclado.segurando[TECLA_DIR] || gTeclado.segurando[TECLA_D])
	{
		if (x < gJanela.getLargura() -  sprite.getLargura() / 2)
		{
			x += velocidade;
		}
	}
}

void Paleta::desenhar()
{
	sprite.desenhar(x, y);
}

float Paleta::getX()
{
	return x;
}

float Paleta::getY()
{
	return y;
}
