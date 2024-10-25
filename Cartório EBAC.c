#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //
#include <string.h> // Biblioteca responsável por cuidar das strings

int registro(){
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o CPF:  ");
	scanf("%s", cpf);
	strcpy(arquivo, cpf);  // Copia o CPF para o nome do arquivo
	
	strcat(arquivo, ".txt");  // Adiciona a extensão .txt
		
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo para escrita, w é para escrita
	fprintf(file,cpf); // salvo o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// Abre o arquivo para acrescentar dados-A é de atualização
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o seu nome: ");
	scanf("%s",nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o seu sobrenome: ");
	scanf("%s",sobrenome);
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o seu cargo: ");
	scanf("%s",cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n\n");
	system("pause");
	return 0;
	
}

int consulta(){
    setlocale(LC_ALL, "Portuguese");  // Definição da Linguagem
    char cpf[50];
    char arquivo[55];  // Tamanho ajustado para incluir ".txt"
    char conteudo[200];

    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    strcat(arquivo, ".txt");  // Adiciona a extensão .txt para abrir o arquivo correto
	
	FILE *file;
	file=fopen(arquivo,"r");// Abre o arquivo
	
	if(file == NULL){
		printf("\nNão foi possivel encotrar o arquivo, NÃO ENCONTRADO! \n\n");
	}	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	return 0;
}

int deletar(){
	setlocale(LC_ALL, "Portuguese");
	char cpf[50];
	char arquivo[50];
	char conf;
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo , cpf);
	strcat(arquivo, ".txt");
	
	//solicitar a confirmação.
	printf("\nTem certeza que quer deletar o usuário de CPF %s ?\n\n",cpf);
	printf("Digite S para sim ou n para não: ");
	scanf(" %c", &conf);
	if(conf == 's'|| conf == 'S'){
		
		if(remove(arquivo) == 0){
			printf("\n Arquivo removido com sucesso\n");
		}
		else{
			printf("Operação cancelada!");
		}
	}
	else{
		
		printf("Operação cancelada!");
	}
	system ("pause");
	return 0;
}

int main(){	
	int x=0;//Armazenamento do valor inicial da letra X
	int y=1;
	
	for(y=1;y=1;){
		system("cls"); //cls é para limpar as mensagens
		setlocale(LC_ALL, "Portuguese");//Definição da Linguage		
		printf("\t Cartório da EBAC\n\n ");//Iníocio do menu
		printf("Escolha uma das opções a seguir:\n");
		printf("\t1 - Registrar nome:\n");
		printf("\t2 - Cosultar nomes:\n");
		printf("\t3 - deletar nomes:\n");
		
		printf("Opção: ");//fim do menu
		scanf("%d",&x);//Armazenamento do valor digitado pelo usuário
		system("CLS");

		switch(x){
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Opção invalida !!! \n ");//fim da seleção
			system("pause");//pausar o sistema, deixa mais organizado
		}//fim da seleção
	}
	return 0;		
}
