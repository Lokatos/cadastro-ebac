#include <stdio.h> // Biblioteca para entrada e sa�da padr�o 
#include <stdlib.h> // Biblioteca para fun��es de aloca��o de mem�ria, controle de processos e sistema
#include <locale.h> // Biblioteca para configurar a localidade do programa 
#include <string.h> // Biblioteca para manipula��o de strings

// Fun��o para registrar um usu�rio
int registro() {
    char arquivo[50]; // Vari�vel que ir� armazenar o nome do arquivo (CPF + .txt)
    char cpf[50]; // Vari�vel para armazenar o CPF do usu�rio
    char nome[50]; // Vari�vel para armazenar o nome do usu�rio
    char sobrenome[50]; // Vari�vel para armazenar o sobrenome do usu�rio
    char cargo[50]; // Vari�vel para armazenar o cargo do usu�rio
    char conf; // Vari�vel para armazenar a confirma��o do usu�rio (S/N para continuar o registro)
    int x = 0; // Vari�vel de controle do loop

    do { // In�cio do loop para registro
        printf("Digite o CPF:  "); // Pede ao usu�rio para digitar o CPF
        scanf("%s", cpf); // L� o CPF digitado e armazena na vari�vel cpf
        strcpy(arquivo, cpf); // Copia o CPF para a vari�vel arquivo (usado para criar o nome do arquivo)
        strcat(arquivo, ".txt"); // Adiciona ".txt" ao final do CPF, criando o nome do arquivo final

        FILE *file = fopen(arquivo, "w"); // Abre o arquivo para escrita (se n�o existir, cria um novo)
        if (file == NULL) { // Verifica se o arquivo foi criado com sucesso
            printf("Erro ao criar o arquivo.\n"); // Mensagem de erro caso n�o seja poss�vel criar o arquivo
            return -1; // Retorna erro e sai da fun��o
        }
        fprintf(file, "%s", cpf); // Escreve o CPF no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Reabre o arquivo para acrescentar mais dados
        fprintf(file, ", "); // Adiciona uma v�rgula ap�s o CPF
        fclose(file); // Fecha o arquivo

        printf("Digite o seu nome: "); // Pede o nome do usu�rio
        scanf("%s", nome); // L� o nome e armazena em 'nome'
        file = fopen(arquivo, "a"); // Reabre o arquivo para adicionar o nome
        fprintf(file, "%s", nome); // Escreve o nome no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, ", "); // Adiciona uma v�rgula ap�s o nome
        fclose(file); // Fecha o arquivo

        printf("Digite o seu sobrenome: "); // Pede o sobrenome do usu�rio
        scanf("%s", sobrenome); // L� o sobrenome
        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, "%s", sobrenome); // Escreve o sobrenome
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, ", "); // Adiciona uma v�rgula ap�s o sobrenome
        fclose(file); // Fecha o arquivo

        printf("Digite o seu cargo: "); // Pede o cargo do usu�rio
        scanf("%s", cargo); // L� o cargo
        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, "%s\n", cargo); // Escreve o cargo no arquivo, com quebra de linha
        fclose(file); // Fecha o arquivo

        while (1) { // Loop para confirmar se o usu�rio deseja registrar outro
            printf("\nDeseja inserir outro usu�rio? (S/N): "); // Pergunta ao usu�rio
            getchar(); // Limpa o buffer de entrada
            scanf("%c", &conf); // L� a confirma��o

            if (conf == 's' || conf == 'S') { // Se o usu�rio desejar registrar outro
                printf("\nCerto, recome�ar!\n\n"); // Mensagem de rein�cio
                x = 0; // Define x como 0 para reiniciar o loop
                break; // Sai do loop de confirma��o
            } else if (conf == 'n' || conf == 'N') { // Se o usu�rio n�o desejar registrar outro
                printf("\nObrigado pelo seu cadastro!\n\n"); // Mensagem de encerramento
                x = 1; // Define x como 1 para encerrar o loop
                break; // Sai do loop de confirma��o
            } else {
                printf("Resposta inv�lida! Por favor, digite S para sim ou N para n�o.\n"); // Mensagem de erro para resposta inv�lida
            }
        }
        system("cls"); // Limpa a tela para organiza��o
    } while (x != 1); // Continua o loop principal at� que x seja igual a 1

    system("pause"); // Pausa para que o usu�rio veja a mensagem final
    return 0; // Retorna 0 para indicar sucesso
}

// Fun��o para consultar um usu�rio pelo CPF
int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para portugu�s
    char cpf[50]; // Vari�vel para armazenar o CPF a ser consultado
    char arquivo[55]; // Vari�vel para armazenar o nome do arquivo
    char conteudo[200]; // Vari�vel para armazenar o conte�do do arquivo

    printf("Digite o CPF a ser consultado: \n"); // Pede ao usu�rio o CPF
    scanf("%s", cpf); // L� o CPF digitado

    strcpy(arquivo, cpf); // Copia o CPF para a vari�vel arquivo
    strcat(arquivo, ".txt"); // Adiciona ".txt" ao CPF para formar o nome do arquivo

    FILE *file = fopen(arquivo, "r"); // Abre o arquivo para leitura
    if (file == NULL) { // Verifica se o arquivo existe
        printf("\nN�o foi poss�vel encontrar o arquivo, N�O ENCONTRADO!\n\n"); // Mensagem de erro
        return -1; // Retorna erro
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n"); // Informa que ir� exibir as informa��es
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) { // L� o conte�do linha a linha
        printf("%s", conteudo); // Exibe o conte�do
    }
    fclose(file); // Fecha o arquivo
    system("pause"); // Pausa para que o usu�rio veja as informa��es
    return 0; // Retorna 0 para indicar sucesso
}

// Fun��o para deletar um usu�rio pelo CPF
int deletar() {
    setlocale(LC_ALL, "Portuguese"); // Define a localidade
    char cpf[50]; // Vari�vel para armazenar o CPF a ser deletado
    char arquivo[55]; // Vari�vel para o nome do arquivo
    char conf; // Vari�vel para confirmar a opera��o

    while (1) { // Loop principal
        printf("Digite o CPF do usu�rio a ser deletado: "); // Pede o CPF
        scanf("%s", cpf); // L� o CPF
        strcpy(arquivo, cpf); // Copia o CPF para a vari�vel arquivo
        strcat(arquivo, ".txt"); // Adiciona ".txt" para criar o nome do arquivo

        FILE *file = fopen(arquivo, "r"); // Abre o arquivo para verificar exist�ncia
        if (file == NULL) { // Se o arquivo n�o existe
            printf("Arquivo n�o encontrado. Verifique o CPF e tente novamente.\n"); // Exibe erro
            system("pause"); // Pausa para ver a mensagem
            continue; // Volta ao in�cio do loop
        }
        fclose(file); // Fecha o arquivo ap�s verifica��o

        printf("\nTem certeza que quer deletar o usu�rio de CPF %s? (S/N): ", cpf); // Confirma��o
        getchar(); // Limpa o buffer
        scanf(" %c", &conf); // L� a resposta

        if (conf == 's' || conf == 'S') { // Se deseja deletar
            if (remove(arquivo) == 0) { // Tenta deletar o arquivo
                printf("\nArquivo removido com sucesso\n"); // Mensagem de sucesso
            } else {
                printf("Erro ao remover o arquivo!\n"); // Mensagem de erro
            }
            printf("Deseja deletar outro usu�rio? (S/N): "); // Pergunta se deseja deletar outro
            scanf(" %c", &conf); // L� a resposta
            if (conf == 'n' || conf == 'N') { // Se n�o deseja deletar outro
                break; // Sai do loop
            }
        } else if (conf == 'n' || conf == 'N') { // Se cancelou a opera��o
            printf("Opera��o cancelada!\n"); // Mensagem de cancelamento
            break; // Sai do loop
        } else {
            printf("Resposta inv�lida! Por favor, digite S para sim ou N para n�o.\n"); // Mensagem para resposta inv�lida
        }
        system("pause"); // Pausa para ver a mensagem
    }
    return 0; // Retorna 0 para indicar sucesso
}

// Fun��o principal
int main() {
    int x = 0; // Vari�vel de controle para o menu
    char senha[10] = "a"; // Define a senha de acesso

    printf("\t Cart�rio da EBAC\n\n"); // T�tulo do programa

    printf("\nDigite a senha de acesso: "); // Pede a senha
    scanf("%s", &senha); // L� a senha

    if (strcmp(senha, "admin") == 0) { // Verifica se a senha est� correta
        while (1) { // Loop do menu principal
            system("cls"); // Limpa a tela
            setlocale(LC_ALL, "Portuguese"); // Define a localidade
            printf("\t Cart�rio da EBAC\n\n"); // T�tulo do menu

            // Exibe as op��es do menu
            printf("Escolha uma das op��es a seguir:\n");
            printf("\t1 - Registrar nome:\n");
            printf("\t2 - Consultar nomes:\n");
            printf("\t3 - Deletar nomes:\n");
            printf("\t4 - Sair!\n\n");

            printf("Op��o: "); // Pede a op��o
            scanf("%d", &x); // L� a op��o digitada
            system("cls"); // Limpa a tela

            switch (x) { // Switch para executar a op��o escolhida
                case 1:
                    registro(); // Chama a fun��o de registro
                    break;
                case 2:
                    consulta(); // Chama a fun��o de consulta
                    break;
                case 3:
                    deletar(); // Chama a fun��o de deletar
                    break;
                case 4:
                    printf("\nObrigado!!!\n\n"); // Mensagem de sa�da
                    return 0; // Sai do programa
                default:
                    printf("Op��o inv�lida!!!\n"); // Mensagem para op��o inv�lida
                    system("pause"); // Pausa para organiza��o
            }
        }
    } else {
        printf("Senha incorreta !\n\n"); // Mensagem para senha incorreta
    }
    system("pause"); // Pausa para que o usu�rio veja a mensagem
    return 0; // Retorna 0 para indicar sucesso
}

