#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int forcaPersonagem, destrezaPersonagem, inteligenciaPersonagem, vitalidadePersonagem;
	char nomePersonagem[20], generoPersonagem[20], classePersonagem[];
	int idadePersonagem, classePersonagemAuxiliar;
	
	printf("CHRONOCROMANCER's RPG\n");
	printf("Voce acordou em um lugar desconhecido, explore o mapa e encontre alguma forma para escapar\n");
	printf("Sobre seu personagem, informe\n");
	printf("Nome: \n");
	scanf("%s", &nomePersonagem);
	printf("Idade: \n");
	scanf("%d", &idadePersonagem);
	printf("Genero: \n");
	scanf("%s", &generoPersonagem);
	printf("Classes disponiveis:\n1 - Guerreiro\n2 - Mago\n3 - Assassino\n");
	printf("Classe: \n");
	scanf("%d", &classePersonagemAuxiliar);
	switch(classePersonagemAuxiliar){
		case 1:
			classePersonagem[] = {"guerreiro"};
		case 2:
			classePersonagem[] = {"Mago"};
		case 3:
			classePersonagem[] = {"Assassino"};
	}
	printf("Nome: %s\nGenero: %s\nClasse: %d", nomePersonagem, generoPersonagem, classePersonagem);
	
	
	
}

//metodo olhar mostra saidas disponiveis
//coletar itens e por no inventario
//olhar itens da sala
//caracteristicas especiais kd personagem
