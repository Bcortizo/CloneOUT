#include "Jogo.h"
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0));

	setlocale(LC_ALL, "ptb");

	Jogo jogo;
	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();

	return 0;
}