#include <stdio.h>

int temploInicial(const char* itensTemploInicial[10]);
int patio(const char* itensPatio[10]);
int quarto(const char* itensQuarto[10]);
int cozinha(const char* itensCozinha[10]);
int portaoDoCastelo(const char* itensPortaoDoCastelo[10]);
int montanha(const char* itensMontanha[10]);
int pantano(const char* itensPantano[10]);
int escadaria(const char* itensEscadaria[10]);
int trilha(const char* itensTrilha[10]);
int caverna(const char* itensCaverna[10]);
int jardim(const char* itensJardim[10]);
int cidadeDoTopo(const char* itensCidadeDoTopo[10]);
int deserto(const char* itensDeserto[10]);
int escolherDirecao(int possibilidades);
void exibirItens(const char* itens[10]);
void pegarItem(const char* itens[10]);

enum State {TemploInicial = 0, Patio = 1, Quarto = 2, Cozinha = 3, PortaoDoCastelo = 4, Montanha = 5, Pantano = 6, Escadaria = 7, Trilha = 8, Caverna = 9, Jardim = 10, CidadeDoTopo = 11, Deserto = 12};

int main(){
	int forcaPersonagem, destrezaPersonagem, inteligenciaPersonagem, vitalidadePersonagem,
		idadePersonagem, escolherClasse, ultimoMovimento = 1, movimentar = 1;
	char nomePersonagem[20], generoPersonagem[20];
	const char* classePersonagem;
	const char* inventario[20];
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
	printf("\nClasses disponiveis:\n1 - Guerreiro\n2 - Mago\n3 - Assassino\n");
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
	printf("\n----- Perfil -----\nNome: %s\nGenero: %s\nClasse: %s\n", nomePersonagem, generoPersonagem, classePersonagem);
	printf("Seus atributos sao:\nForca: %d\nDestreza: %d\nInteligencia: %d\nVitalidade: %d\n", forcaPersonagem, destrezaPersonagem, inteligenciaPersonagem, vitalidadePersonagem);
	printf("\nOk, agora va procurar a saida... antes que seja tarde\n");
	while(movimentar != 0){
		switch(movimentar){
			case 1:
				switch (ultimoMovimento){
					case CidadeDoTopo:
						movimentar = escadaria(itensEscadaria);
						ultimoMovimento = Escadaria;
						break;
					case Deserto:
						movimentar = trilha(itensTrilha);
						ultimoMovimento = Trilha;
						break;
					case Escadaria:
						movimentar = montanha(itensMontanha);
						ultimoMovimento = Montanha;
						break;
					case Trilha:
						movimentar = pantano(itensPantano);
						ultimoMovimento = Pantano;
						break;
					case PortaoDoCastelo:
						movimentar = patio(itensPatio);
						ultimoMovimento = Patio;
						break;
					case Patio:
						movimentar = temploInicial(itensTemploInicial);
						ultimoMovimento = TemploInicial;
						break;
				}
				break;

			case 2:
				switch (ultimoMovimento){
					case TemploInicial:
						movimentar = patio(itensPatio);	
						ultimoMovimento = Patio;
						break;
					case Patio:
						movimentar = portaoDoCastelo(itensPortaoDoCastelo);
						ultimoMovimento = PortaoDoCastelo;
						break;
					case Montanha:
						movimentar = escadaria(itensEscadaria);
						ultimoMovimento = Escadaria;
						break;
					case Pantano:
						movimentar = trilha(itensTrilha);
						ultimoMovimento = Trilha;
						break;
					case Escadaria:
						movimentar = cidadeDoTopo(itensCidadeDoTopo);
						ultimoMovimento = CidadeDoTopo;
						break;
					case Trilha:
						movimentar = deserto(itensDeserto);
						ultimoMovimento = Deserto;
						break;
				}
				break;

			case 3:
				switch (ultimoMovimento){
					case Patio:
						movimentar = quarto(itensQuarto);
						ultimoMovimento = Quarto;
						break;
					case Cozinha:
						movimentar = patio(itensPatio);
						ultimoMovimento = Patio;
						break;
					case PortaoDoCastelo:
						movimentar = montanha(itensMontanha);
						ultimoMovimento = Montanha;
						break;
					case Pantano:
						movimentar = portaoDoCastelo(itensPortaoDoCastelo);
						ultimoMovimento = PortaoDoCastelo;
						break;
					case Caverna:
						movimentar = escadaria(itensEscadaria);
						ultimoMovimento = Escadaria;
						break;
					case Trilha:
						movimentar = jardim(itensJardim);
						ultimoMovimento = Jardim;
						break;
				}
				break;

			case 4:
				switch (ultimoMovimento){
					case Quarto:
						movimentar = patio(itensPatio);
						ultimoMovimento = Patio;
						break;
					case Patio:
						movimentar = cozinha(itensCozinha);
						ultimoMovimento = Cozinha;
						break;
					case PortaoDoCastelo:
						movimentar = pantano(itensPantano);
						ultimoMovimento = Pantano;
						break;
					case Montanha:
						movimentar = portaoDoCastelo(itensPortaoDoCastelo);
						ultimoMovimento = PortaoDoCastelo;
						break;
					case Escadaria:
						movimentar = caverna(itensCaverna);
						ultimoMovimento = Caverna;
						break;
					case Jardim:
						movimentar = trilha(itensTrilha);
						ultimoMovimento = Trilha;
						break;
				}
				break;

			default:
				break;
		}
	}
}

int temploInicial(const char* itensTemploInicial[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Templo Inicial\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensTemploInicial);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensTemploInicial);
						break;
					case 2:
						localEscolhido = escolherDirecao(1);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(1);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int patio(const char* itensPatio[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Patio\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensPatio);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensPatio);
						break;
					case 2:
						localEscolhido = escolherDirecao(7);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(7);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int quarto(const char* itensQuarto[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Quarto\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensQuarto);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensQuarto);
						break;
					case 2:
						localEscolhido = escolherDirecao(3);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(3);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int cozinha(const char* itensCozinha[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Cozinha\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensCozinha);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensCozinha);
						break;
					case 2:
						localEscolhido = escolherDirecao(2);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(2);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int portaoDoCastelo(const char* itensPortaoDoCastelo[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Portao do castelo\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensPortaoDoCastelo);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensPortaoDoCastelo);
						break;
					case 2:
						localEscolhido = escolherDirecao(4);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(4);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int montanha(const char* itensMontanha[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Montanha\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensMontanha);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensMontanha);
						break;
					case 2:
						localEscolhido = escolherDirecao(8);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(8);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int pantano(const char* itensPantano[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Pantano\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensPantano);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensPantano);
						break;
					case 2:
						localEscolhido = escolherDirecao(9);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(9);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int escadaria(const char* itensEscadaria[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Escadaria\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensEscadaria);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensEscadaria);
						break;
					case 2:
						localEscolhido = escolherDirecao(5);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(5);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int trilha(const char* itensTrilha[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Trilha\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensTrilha);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensTrilha);
						break;
					case 2:
						localEscolhido = escolherDirecao(6);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(6);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int caverna(const char* itensCaverna[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Caverna\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensCaverna);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensCaverna);
						break;
					case 2:
						localEscolhido = escolherDirecao(2);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(2);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int jardim(const char* itensJardim[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Jardim\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensJardim);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensJardim);
						break;
					case 2:
						localEscolhido = escolherDirecao(3);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(3);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int cidadeDoTopo(const char* itensCidadeDoTopo[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Cidade do topo\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensCidadeDoTopo);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensCidadeDoTopo);
						break;
					case 2:
						localEscolhido = escolherDirecao(0);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(0);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}
int deserto(const char* itensDeserto[10]){
	int loop = 1, pegar = 0, localEscolhido;
	printf("\nLocalizacao atual: Deserto\n");
	while(loop != 0){
		printf("\nO que deseja fazer?\n1 - Inspecionar local\n2 - Continuar andando\n");
		scanf("%d", &loop);
		switch(loop){
			case 1:
				exibirItens(itensDeserto);
				printf("\n1 - pegar objeto\n2 - Continuar andando\n");
				scanf("%d", &pegar);
				switch(pegar){
					case 1:
						pegarItem(itensDeserto);
						break;
					case 2:
						localEscolhido = escolherDirecao(0);
						break;
					default:
						printf("Insira uma opcao valida");
				}
				break;
			case 2:
				localEscolhido = escolherDirecao(0);
				break;
			default:
				printf("\nInsira uma opcao valida\n");
		}
		return localEscolhido;
	}
}

int escolherDirecao(int possibilidades){
	int localEscolhido = 0;
	switch(possibilidades){
		case 0:
			printf("\nPara onde deseja ir?\n1 Norte\n");
			scanf("%d", &localEscolhido);
			break;
		case 1:
			printf("\nPara onde deseja ir?\n1 sul\n");
			scanf("%d", &localEscolhido);
			localEscolhido = 2;
			break;
		case 2:
			printf("\nPara onde deseja ir?\n1 Leste\n");
			scanf("%d", &localEscolhido);
			localEscolhido = 3;
			break;
		case 3:
			printf("\nPara onde deseja ir?\n1 Oeste\n");
			scanf("%d", &localEscolhido);
			localEscolhido = 4;
			break;
		case 4:
			printf("\nPara onde deseja ir?\n1 Norte\n2 Leste\n3 Oeste\n");
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
			printf("\nPara onde deseja ir?\n1 Norte\n2 Sul\n3 Oeste\n");
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
			printf("\nPara onde deseja ir?\n1 Norte\n2 Sul\n3 Leste\n");
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
			printf("\nPara onde deseja ir?\n1 Norte\n2 Sul\n3 Leste\n4 Oeste\n");
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
			printf("\nPara onde deseja ir?\n1 Sul\n2 Oeste\n");
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
			printf("\nPara onde deseja ir?\n1 Sul\n2 Leste\n");
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
	int i, j;
	printf("\nVoce encontrou: \n");
	for(i=0; i<sizeof(itens); i++){
		printf("%s\n", itens[i]);
	}
}

void pegarItem(const char* itens[10]){
	int i, j, itemRemovido;
	printf("\nQual item deseja pegar?\n");
	scanf("%d", &itemRemovido);
	for(i = itemRemovido-1; i < 10 - 1; i++) {
		itens[i] = itens[i+1];
	}
}