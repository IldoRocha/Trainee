#include <stdio.h>
#include <stdlib.h>

int temploInicial(const char* itensTemploInicial[10], const char* inverntario[20]);
int patio(const char* itensPatio[10], const char* inventario[20]);
int quarto(const char* itensQuarto[10], const char* inventario[20]);
int cozinha(const char* itensCozinha[10], const char* inventario[20]);
int portaoDoCastelo(const char* itensPortaoDoCastelo[10], const char* inventario[20]);
int montanha(const char* itensMontanha[10], const char* inventario[20]);
int pantano(const char* itensPantano[10], const char* inventario[20]);
int escadaria(const char* itensEscadaria[10], const char* inventario[20]);
int trilha(const char* itensTrilha[10], const char* inventario[20]);
int caverna(const char* itensCaverna[10], const char* inventario[20]);
int jardim(const char* itensJardim[10], const char* inventario[20]);
int cidadeDoTopo(const char* itensCidadeDoTopo[10], const char* inventario[20]);
int deserto(const char* itensDeserto[10], const char* inventario[20]);
int escolherDirecao(int possibilidades);
void exibirItens(const char* itens[10]);
void pegarItem(const char* itens[10], const char* inventario[20]);
void exibirInventario(const char* inventario[20]);

enum State {TemploInicial = 0, Patio = 1, Quarto = 2, Cozinha = 3, PortaoDoCastelo = 4, Montanha = 5, Pantano = 6, Escadaria = 7, Trilha = 8, Caverna = 9, Jardim = 10, CidadeDoTopo = 11, Deserto = 12};

int main(){
	int forcaPersonagem, destrezaPersonagem, inteligenciaPersonagem, vitalidadePersonagem,
		idadePersonagem, escolherClasse, ultimoMovimento = 1, movimentar = 1, start;
	char nomePersonagem[20], generoPersonagem[20];
	const char* classePersonagem;
	const char* inventario[20] = {"Pocao de vida"};
	const char* itensTemploInicial[10] = {"Espada", "Arco", "Adaga", "Varinha", "Escudo"};
	const char* itensPatio[10] = {"Pocao de vida"};
	const char* itensQuarto[10] = {"Peitoral", "Elmo", "Escarpes", "Grevas", "Manopla"};
	const char* itensCozinha[10] = {"Faca", "Cantil"};
	const char* itensPortaoDoCastelo[10] = {"Corda"};
	const char* itensMontanha[10] = {"Prata"};
	const char* itensPantano[10] = {"Veneno"};
	const char* itensEscadaria[10] = {"Lasca afiada"};
	const char* itensTrilha[10] = {"Lanca de madeira"};
	const char* itensCaverna[10] = {"Veneno de cobra"};
	const char* itensJardim[10] = {"Tesoura"};
	const char* itensCidadeDoTopo[10] = {"lanca de metal"};
	const char* itensDeserto[10] = {"Agua"};
	printf("CHRONOCROMANCER's RPG\n");
	printf("Voce acordou em um lugar desconhecido, explore o mapa e encontre alguma forma para escapar\n");
	printf("\nSobre seu personagem, informe\n");
	printf("Nome: \n");
	scanf("%s", &nomePersonagem);
	printf("Idade: \n");
	scanf("%d", &idadePersonagem);
	printf("Genero: \n");
	scanf("%s", &generoPersonagem);
	system("cls");
	printf("Classes disponiveis:\n1 - Guerreiro\n2 - Mago\n3 - Assassino\n");
	printf("\nClasse: \n");
	scanf("%d", &escolherClasse);
	switch(escolherClasse){
		case 1:
			classePersonagem = "Guerreiro";
			forcaPersonagem = 10, destrezaPersonagem = 4, inteligenciaPersonagem = 2, vitalidadePersonagem = 10;
			break;
		case 2:
			classePersonagem = "Mago";
			forcaPersonagem = 2, destrezaPersonagem = 7, inteligenciaPersonagem = 10, vitalidadePersonagem = 7;
			break;
		case 3:
			classePersonagem = "Assassino";
			forcaPersonagem = 10, destrezaPersonagem = 10, inteligenciaPersonagem = 4, vitalidadePersonagem = 2;
			break;
		default:
			printf("Insira uma opcao valida!");
	}
	system("cls");
	printf("----- Perfil -----\nNome: %s\nGenero: %s\nClasse: %s\n", nomePersonagem, generoPersonagem, classePersonagem);
	printf("Seus atributos sao:\nForca: %d\nDestreza: %d\nInteligencia: %d\nVitalidade: %d\n", forcaPersonagem, destrezaPersonagem, inteligenciaPersonagem, vitalidadePersonagem);
	printf("\nOk, agora va procurar a saida... antes que seja tarde\n");
	printf("\n1 - Iniciar\n2 - Sair\n");
	scanf("%d", &start);
	switch(start){
		case 1:
			break;
		case 2:
			movimentar = 0;
			break;
		default:
			break;
	}
	while(movimentar != 0){
		switch(movimentar){
			case 1:
				switch (ultimoMovimento){
					case CidadeDoTopo:
						movimentar = escadaria(itensEscadaria, inventario);
						ultimoMovimento = Escadaria;
						break;
					case Deserto:
						movimentar = trilha(itensTrilha, inventario);
						ultimoMovimento = Trilha;
						break;
					case Escadaria:
						movimentar = montanha(itensMontanha, inventario);
						ultimoMovimento = Montanha;
						break;
					case Trilha:
						movimentar = pantano(itensPantano, inventario);
						ultimoMovimento = Pantano;
						break;
					case PortaoDoCastelo:
						movimentar = patio(itensPatio, inventario);
						ultimoMovimento = Patio;
						break;
					case Patio:
						movimentar = temploInicial(itensTemploInicial, inventario);
						ultimoMovimento = TemploInicial;
						break;
				}
				break;

			case 2:
				switch (ultimoMovimento){
					case TemploInicial:
						movimentar = patio(itensPatio, inventario);	
						ultimoMovimento = Patio;
						break;
					case Patio:
						movimentar = portaoDoCastelo(itensPortaoDoCastelo, inventario);
						ultimoMovimento = PortaoDoCastelo;
						break;
					case Montanha:
						movimentar = escadaria(itensEscadaria, inventario);
						ultimoMovimento = Escadaria;
						break;
					case Pantano:
						movimentar = trilha(itensTrilha, inventario);
						ultimoMovimento = Trilha;
						break;
					case Escadaria:
						movimentar = cidadeDoTopo(itensCidadeDoTopo, inventario);
						ultimoMovimento = CidadeDoTopo;
						break;
					case Trilha:
						movimentar = deserto(itensDeserto, inventario);
						ultimoMovimento = Deserto;
						break;
				}
				break;

			case 3:
				switch (ultimoMovimento){
					case Patio:
						movimentar = quarto(itensQuarto, inventario);
						ultimoMovimento = Quarto;
						break;
					case Cozinha:
						movimentar = patio(itensPatio, inventario);
						ultimoMovimento = Patio;
						break;
					case PortaoDoCastelo:
						movimentar = montanha(itensMontanha, inventario);
						ultimoMovimento = Montanha;
						break;
					case Pantano:
						movimentar = portaoDoCastelo(itensPortaoDoCastelo, inventario);
						ultimoMovimento = PortaoDoCastelo;
						break;
					case Caverna:
						movimentar = escadaria(itensEscadaria, inventario);
						ultimoMovimento = Escadaria;
						break;
					case Trilha:
						movimentar = jardim(itensJardim, inventario);
						ultimoMovimento = Jardim;
						break;
				}
				break;

			case 4:
				switch (ultimoMovimento){
					case Quarto:
						movimentar = patio(itensPatio, inventario);
						ultimoMovimento = Patio;
						break;
					case Patio:
						movimentar = cozinha(itensCozinha, inventario);
						ultimoMovimento = Cozinha;
						break;
					case PortaoDoCastelo:
						movimentar = pantano(itensPantano, inventario);
						ultimoMovimento = Pantano;
						break;
					case Montanha:
						movimentar = portaoDoCastelo(itensPortaoDoCastelo, inventario);
						ultimoMovimento = PortaoDoCastelo;
						break;
					case Escadaria:
						movimentar = caverna(itensCaverna, inventario);
						ultimoMovimento = Caverna;
						break;
					case Jardim:
						movimentar = trilha(itensTrilha, inventario);
						ultimoMovimento = Trilha;
						break;
				}
				break;

			default:
				break;
		}
	}
}

int temploInicial(const char* itensTemploInicial[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Templo Inicial\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensTemploInicial);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensTemploInicial, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(1);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(1);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int patio(const char* itensPatio[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Patio\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensPatio);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensPatio, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(7);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(7);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int quarto(const char* itensQuarto[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Quarto\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensQuarto);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensQuarto, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(3);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(3);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int cozinha(const char* itensCozinha[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Cozinha\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensCozinha);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensCozinha, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(2);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(2);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int portaoDoCastelo(const char* itensPortaoDoCastelo[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Portao do castelo\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensPortaoDoCastelo);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensPortaoDoCastelo, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(4);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(4);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int montanha(const char* itensMontanha[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Montanha\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensMontanha);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensMontanha, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(8);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(8);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int pantano(const char* itensPantano[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Pantano\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensPantano);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensPantano, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(9);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(9);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int escadaria(const char* itensEscadaria[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Escadaria\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensEscadaria);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensEscadaria, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(5);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(5);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int trilha(const char* itensTrilha[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Trilha\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensTrilha);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensTrilha, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(6);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(6);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int caverna(const char* itensCaverna[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Caverna\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensCaverna);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensCaverna, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(2);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(2);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int jardim(const char* itensJardim[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Jardim\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensJardim);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensJardim, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(3);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(3);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int cidadeDoTopo(const char* itensCidadeDoTopo[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Cidade do topo\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensCidadeDoTopo);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensCidadeDoTopo, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(0);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(0);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}
int deserto(const char* itensDeserto[10], const char* inventario[20]){
	int loop = 1, pegar = 0, localEscolhido;
	system("cls");
	printf("Localizacao atual: Deserto\n\n");
	while(loop != 0){
		printf("O que deseja fazer?\n1 - Inspecionar local\n2 - Olhar inventario\n3 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensDeserto);
				printf("\n1 - pegar objeto\n2 - Olhar inventario\n3 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensDeserto, inventario);
						break;
					case 2:
						exibirInventario(inventario);
						break;
					case 3:
						localEscolhido = escolherDirecao(0);
						loop = 0;
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				exibirInventario(inventario);
				break;
			case 3:
				localEscolhido = escolherDirecao(0);
				loop = 0;
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
	}
	return localEscolhido;
}

int escolherDirecao(int possibilidades){
	int localEscolhido = 0;
	switch(possibilidades){
		case 0:
			system("cls");
			printf("Para onde deseja ir?\n1 Norte\n");
			scanf("%d", &localEscolhido);
			break;
		case 1:
			system("cls");
			printf("Para onde deseja ir?\n1 sul\n");
			scanf("%d", &localEscolhido);
			localEscolhido = 2;
			break;
		case 2:
			system("cls");
			printf("Para onde deseja ir?\n1 Leste\n");
			scanf("%d", &localEscolhido);
			localEscolhido = 3;
			break;
		case 3:
			system("cls");
			printf("Para onde deseja ir?\n1 Oeste\n");
			scanf("%d", &localEscolhido);
			localEscolhido = 4;
			break;
		case 4:
			system("cls");
			printf("Para onde deseja ir?\n1 Norte\n2 Leste\n3 Oeste\n");
			scanf("%d", &localEscolhido);
			switch(localEscolhido){
				case 2:
					localEscolhido = 3;
					break;
				case 3:
					localEscolhido = 4;
					break;
			}
			break;
		case 5:
			system("cls");
			printf("Para onde deseja ir?\n1 Norte\n2 Sul\n3 Oeste\n");
			scanf("%d", &localEscolhido);
			switch(localEscolhido){
				case 1:
					localEscolhido = 1;
					break;
				case 2:
					localEscolhido = 2;
					break;
				case 3:
					localEscolhido = 4;
					break;
			}
			break;
		case 6:
			system("cls");
			printf("Para onde deseja ir?\n1 Norte\n2 Sul\n3 Leste\n");
			scanf("%d", &localEscolhido);
			switch(localEscolhido){
				case 1:
					localEscolhido = 1;
					break;
				case 2:
					localEscolhido = 2;
					break;
				case 3:
					localEscolhido = 3;
					break;
			}
			break;
		case 7:
			system("cls");
			printf("Para onde deseja ir?\n1 Norte\n2 Sul\n3 Leste\n4 Oeste\n");
			scanf("%d", &localEscolhido);
			switch(localEscolhido){
				case 1:
					localEscolhido = 1;
					break;
				case 2:
					localEscolhido = 2;
					break;
				case 3:
					localEscolhido = 3;
					break;
				case 4:
					localEscolhido = 4;
			}
			break;
		case 8:
			system("cls");
			printf("Para onde deseja ir?\n1 Sul\n2 Oeste\n");
			scanf("%d", &localEscolhido);
			switch(localEscolhido){
				case 1:
					localEscolhido = 2;
					break;
				case 2:
					localEscolhido = 4;
					break;
			}
			break;
		case 9:
			system("cls");
			printf("Para onde deseja ir?\n1 Sul\n2 Leste\n");
			scanf("%d", &localEscolhido);
			switch(localEscolhido){
				case 1:
					localEscolhido = 2;
					break;
				case 2:
					localEscolhido = 3;
					break;
			}
			break;
		default:
			break;
	}
	return localEscolhido;
}

void exibirItens(const char* itens[10]){
	int i, nulos = 0;
	for(i=0; i<sizeof(itens); i++){
		if(itens[i] == NULL){
			nulos++;
		}
	}
	system("cls");
	printf("Voce encontrou: \n");
	for(i=0; i<sizeof(itens)-nulos; i++){
		printf("%d - %s\n", i+1, itens[i]);
	}
}

void pegarItem(const char* itens[10], const char* inventario[20]){
	int i, itemRemovido;
	printf("\nQual item deseja pegar?\n");
	scanf("%d", &itemRemovido);
	for(i=19; i>0; i--){
		inventario[i] = inventario[i-1];
	}
	inventario[0] = itens[itemRemovido-1];
	for(i = itemRemovido-1; i < (9); i++) {
		itens[i] = itens[i+1];
	}
	system("cls");
}

void exibirInventario(const char* inventario[20]){
	int i;
	system("cls");
	printf("Voce possui: \n");
	for(i=0; i<sizeof(inventario); i++){
		printf("%s\n", inventario[i]);
	}
	printf("\n");
}
