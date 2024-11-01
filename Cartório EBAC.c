#include <stdio.h> // Biblioteca para entrada e saída padrão 
#include <stdlib.h> // Biblioteca para funções de alocação de memória, controle de processos e sistema
#include <locale.h> // Biblioteca para configurar a localidade do programa 
#include <string.h> // Biblioteca para manipulação de strings

// Função para registrar um usuário
int registro() {
    char arquivo[50]; // Variável que irá armazenar o nome do arquivo (CPF + .txt)
    char cpf[50]; // Variável para armazenar o CPF do usuário
    char nome[50]; // Variável para armazenar o nome do usuário
    char sobrenome[50]; // Variável para armazenar o sobrenome do usuário
    char cargo[50]; // Variável para armazenar o cargo do usuário
    char conf; // Variável para armazenar a confirmação do usuário (S/N para continuar o registro)
    int x = 0; // Variável de controle do loop

    do { // Início do loop para registro
        printf("Digite o CPF:  "); // Pede ao usuário para digitar o CPF
        scanf("%s", cpf); // Lê o CPF digitado e armazena na variável cpf
        strcpy(arquivo, cpf); // Copia o CPF para a variável arquivo (usado para criar o nome do arquivo)
        strcat(arquivo, ".txt"); // Adiciona ".txt" ao final do CPF, criando o nome do arquivo final

        FILE *file = fopen(arquivo, "w"); // Abre o arquivo para escrita (se não existir, cria um novo)
        if (file == NULL) { // Verifica se o arquivo foi criado com sucesso
            printf("Erro ao criar o arquivo.\n"); // Mensagem de erro caso não seja possível criar o arquivo
            return -1; // Retorna erro e sai da função
        }
        fprintf(file, "%s", cpf); // Escreve o CPF no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Reabre o arquivo para acrescentar mais dados
        fprintf(file, ", "); // Adiciona uma vírgula após o CPF
        fclose(file); // Fecha o arquivo

        printf("Digite o seu nome: "); // Pede o nome do usuário
        scanf("%s", nome); // Lê o nome e armazena em 'nome'
        file = fopen(arquivo, "a"); // Reabre o arquivo para adicionar o nome
        fprintf(file, "%s", nome); // Escreve o nome no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, ", "); // Adiciona uma vírgula após o nome
        fclose(file); // Fecha o arquivo

        printf("Digite o seu sobrenome: "); // Pede o sobrenome do usuário
        scanf("%s", sobrenome); // Lê o sobrenome
        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, "%s", sobrenome); // Escreve o sobrenome
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, ", "); // Adiciona uma vírgula após o sobrenome
        fclose(file); // Fecha o arquivo

        printf("Digite o seu cargo: "); // Pede o cargo do usuário
        scanf("%s", cargo); // Lê o cargo
        file = fopen(arquivo, "a"); // Reabre o arquivo
        fprintf(file, "%s\n", cargo); // Escreve o cargo no arquivo, com quebra de linha
        fclose(file); // Fecha o arquivo

        while (1) { // Loop para confirmar se o usuário deseja registrar outro
            printf("\nDeseja inserir outro usuário? (S/N): "); // Pergunta ao usuário
            getchar(); // Limpa o buffer de entrada
            scanf("%c", &conf); // Lê a confirmação

            if (conf == 's' || conf == 'S') { // Se o usuário desejar registrar outro
                printf("\nCerto, recomeçar!\n\n"); // Mensagem de reinício
                x = 0; // Define x como 0 para reiniciar o loop
                break; // Sai do loop de confirmação
            } else if (conf == 'n' || conf == 'N') { // Se o usuário não desejar registrar outro
                printf("\nObrigado pelo seu cadastro!\n\n"); // Mensagem de encerramento
                x = 1; // Define x como 1 para encerrar o loop
                break; // Sai do loop de confirmação
            } else {
                printf("Resposta inválida! Por favor, digite S para sim ou N para não.\n"); // Mensagem de erro para resposta inválida
            }
        }
        system("cls"); // Limpa a tela para organização
    } while (x != 1); // Continua o loop principal até que x seja igual a 1

    system("pause"); // Pausa para que o usuário veja a mensagem final
    return 0; // Retorna 0 para indicar sucesso
}

// Função para consultar um usuário pelo CPF
int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Define a localidade para português
    char cpf[50]; // Variável para armazenar o CPF a ser consultado
    char arquivo[55]; // Variável para armazenar o nome do arquivo
    char conteudo[200]; // Variável para armazenar o conteúdo do arquivo

    printf("Digite o CPF a ser consultado: \n"); // Pede ao usuário o CPF
    scanf("%s", cpf); // Lê o CPF digitado

    strcpy(arquivo, cpf); // Copia o CPF para a variável arquivo
    strcat(arquivo, ".txt"); // Adiciona ".txt" ao CPF para formar o nome do arquivo

    FILE *file = fopen(arquivo, "r"); // Abre o arquivo para leitura
    if (file == NULL) { // Verifica se o arquivo existe
        printf("\nNão foi possível encontrar o arquivo, NÃO ENCONTRADO!\n\n"); // Mensagem de erro
        return -1; // Retorna erro
    }

    printf("\nEssas são as informações do usuário:\n"); // Informa que irá exibir as informações
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) { // Lê o conteúdo linha a linha
        printf("%s", conteudo); // Exibe o conteúdo
    }
    fclose(file); // Fecha o arquivo
    system("pause"); // Pausa para que o usuário veja as informações
    return 0; // Retorna 0 para indicar sucesso
}

// Função para deletar um usuário pelo CPF
int deletar() {
    setlocale(LC_ALL, "Portuguese"); // Define a localidade
    char cpf[50]; // Variável para armazenar o CPF a ser deletado
    char arquivo[55]; // Variável para o nome do arquivo
    char conf; // Variável para confirmar a operação

    while (1) { // Loop principal
        printf("Digite o CPF do usuário a ser deletado: "); // Pede o CPF
        scanf("%s", cpf); // Lê o CPF
        strcpy(arquivo, cpf); // Copia o CPF para a variável arquivo
        strcat(arquivo, ".txt"); // Adiciona ".txt" para criar o nome do arquivo

        FILE *file = fopen(arquivo, "r"); // Abre o arquivo para verificar existência
        if (file == NULL) { // Se o arquivo não existe
            printf("Arquivo não encontrado. Verifique o CPF e tente novamente.\n"); // Exibe erro
            system("pause"); // Pausa para ver a mensagem
            continue; // Volta ao início do loop
        }
        fclose(file); // Fecha o arquivo após verificação

        printf("\nTem certeza que quer deletar o usuário de CPF %s? (S/N): ", cpf); // Confirmação
        getchar(); // Limpa o buffer
        scanf(" %c", &conf); // Lê a resposta

        if (conf == 's' || conf == 'S') { // Se deseja deletar
            if (remove(arquivo) == 0) { // Tenta deletar o arquivo
                printf("\nArquivo removido com sucesso\n"); // Mensagem de sucesso
            } else {
                printf("Erro ao remover o arquivo!\n"); // Mensagem de erro
            }
            printf("Deseja deletar outro usuário? (S/N): "); // Pergunta se deseja deletar outro
            scanf(" %c", &conf); // Lê a resposta
            if (conf == 'n' || conf == 'N') { // Se não deseja deletar outro
                break; // Sai do loop
            }
        } else if (conf == 'n' || conf == 'N') { // Se cancelou a operação
            printf("Operação cancelada!\n"); // Mensagem de cancelamento
            break; // Sai do loop
        } else {
            printf("Resposta inválida! Por favor, digite S para sim ou N para não.\n"); // Mensagem para resposta inválida
        }
        system("pause"); // Pausa para ver a mensagem
    }
    return 0; // Retorna 0 para indicar sucesso
}

// Função principal
int main() {
    int x = 0; // Variável de controle para o menu
    char senha[10] = "a"; // Define a senha de acesso

    printf("\t Cartório da EBAC\n\n"); // Título do programa

    printf("\nDigite a senha de acesso: "); // Pede a senha
    scanf("%s", &senha); // Lê a senha

    if (strcmp(senha, "admin") == 0) { // Verifica se a senha está correta
        while (1) { // Loop do menu principal
            system("cls"); // Limpa a tela
            setlocale(LC_ALL, "Portuguese"); // Define a localidade
            printf("\t Cartório da EBAC\n\n"); // Título do menu

            // Exibe as opções do menu
            printf("Escolha uma das opções a seguir:\n");
            printf("\t1 - Registrar nome:\n");
            printf("\t2 - Consultar nomes:\n");
            printf("\t3 - Deletar nomes:\n");
            printf("\t4 - Sair!\n\n");

            printf("Opção: "); // Pede a opção
            scanf("%d", &x); // Lê a opção digitada
            system("cls"); // Limpa a tela

            switch (x) { // Switch para executar a opção escolhida
                case 1:
                    registro(); // Chama a função de registro
                    break;
                case 2:
                    consulta(); // Chama a função de consulta
                    break;
                case 3:
                    deletar(); // Chama a função de deletar
                    break;
                case 4:
                    printf("\nObrigado!!!\n\n"); // Mensagem de saída
                    return 0; // Sai do programa
                default:
                    printf("Opção inválida!!!\n"); // Mensagem para opção inválida
                    system("pause"); // Pausa para organização
            }
        }
    } else {
        printf("Senha incorreta !\n\n"); // Mensagem para senha incorreta
    }
    system("pause"); // Pausa para que o usuário veja a mensagem
    return 0; // Retorna 0 para indicar sucesso
}

