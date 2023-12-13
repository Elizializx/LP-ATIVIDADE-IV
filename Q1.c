#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_CONTATOS 3
#define MAX_CARACTERES 200

void cabecalho()
{
    printf("---------------CONTATOS---------------\n");
}

void menu()
{
    printf("---------------MENU---------------");
}

void limpatela()
{
    system("cls");
}

struct contato_dados
{
    char nome[MAX_CARACTERES];
    char telefone[MAX_CARACTERES];
    char email[MAX_CARACTERES];
};

void procurar_contato(struct contato_dados *contato, char *procurar)
{
    int i;

    cabecalho();
   
    for (i = 0; i < MAX_CONTATOS; i++)
    {
        if (strcmp(procurar, contato[i].nome) == 0)
        {
            printf("\n");
            printf("Nome: %s \n", contato[i].nome);
            printf("Telefone: %s \n", contato[i].telefone);
         return;
        }
    }

    printf("Contato não encontrado ou não existente.\n");

    int opcao3;
    int opcao4;

    printf("\nDeseja voltar ao menu?\n ");
    printf("1 - Sim\n");
    printf(" 2 - Não\n");
    scanf("%d", &opcao3);

    limpatela();

    switch (opcao3)
    {
    case 1:
        menu();

        printf("\n\n");
        printf("1 - Procurar contato.\n");
        printf("2 - Sair\n");
        scanf("%d", &opcao4);

        fflush(stdin);

        switch (opcao4)
        {
        case 1:
            limpatela();

            printf("Insira o nome do contato: ");
            fgets(procurar, MAX_CARACTERES, stdin);

            limpatela();

            procurar_contato(contato, procurar);
            break;

        default:
            break;
        }

    default:
        return 0;
        limpatela();
        printf("Contatos salvos e finalizado.");
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct contato_dados contato[MAX_CONTATOS];

    int opcao1;
    int opcao2;
    char procurar[MAX_CARACTERES];

    menu();

    printf("\n\nDeseja cadastrar/salvar algum contato?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &opcao1);

    limpatela();

    int i;

    switch (opcao1)
    {
    case 1:
        printf("\nCadastre 3 contatos abaixo.\n");
        sleep(1);

        printf("\n");
        for (i = 0; i < MAX_CONTATOS; i++)
        {
            fflush(stdin);

            printf("Nome do %dº contato : ", i + 1);
            fgets(contato[i].nome, MAX_CARACTERES, stdin);

            printf("Telefone: ");
            fgets(contato[i].telefone, MAX_CARACTERES, stdin);

            printf("Email: ");
            fgets(contato[i].email, MAX_CARACTERES, stdin);

            limpatela();
        }

        limpatela();
        break;

    case 2:
        return 0;
        break;

    default:
        printf("Opção inválida!");
        break;
    }

    fflush(stdin);

    printf("Deseja procurar algum contato?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &opcao2);

    fflush(stdin);
    limpatela();

    switch (opcao2)
    {
    case 1:
        printf("Insira o nome do contato: ");
        fgets(procurar, MAX_CARACTERES, stdin);

        limpatela();

        procurar_contato(contato, procurar);
        break;

    case 2:
        return 0;
        break;

    default:
        printf("Opção inválida!\n");
        break;
    }

    return 0;
}
