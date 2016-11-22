#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Clone de Breakout");

	paleta.inicializar();

	int nLinhas, nColunas, nBlocos;
	ifstream fase("fases/fase01.txt");

	fase >> nBlocos;
	blocos = new Bloco[nBlocos];

	for (int i = 0; i < nBlocos; i++)
	{
		int id;
		string nomeBloco;
		fase >> id;
		fase >> nomeBloco;
		blocos[i].inicializar(id, nomeBloco);
	}

	fase >> nLinhas;
	fase >> nColunas;

	// aloca dinamicamente a matriz iBlocos[nLinhas][nColunas] (definida em jogo.h como int **iBlocos)
	iBlocos = new int*[nLinhas];
	for (int linha = 0; linha < nLinhas; linha++)
	{
		iBlocos[linha] = new int[nColunas];
	}

	fase >> offsetH;
	fase >> offsetV;

	for (int linha = 0; linha < 6; linha++)
	{
		for (int col = 0; col < 10; col++)
		{
			int id;
			fase >> id;
			iBlocos[linha][col] = id;
		}
	}

	fase.close();
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		
		paleta.atualizar();
		paleta.desenhar();

		int x, y;

		for (int linha = 0; linha < 6; linha++)
		{
			for (int col = 0; col < 10; col++)
			{
				x = 200 + offsetH + blocos[0].getLargura() /2 + (blocos[0].getLargura() + offsetH) * col;
				y = 50 + offsetV + blocos[0].getAltura() / 2 + (blocos[0].getAltura() + offsetV) * linha;
				blocos[iBlocos[linha][col]].desenhar(x, y);
			}
		}

		uniTerminarFrame();
	}
}