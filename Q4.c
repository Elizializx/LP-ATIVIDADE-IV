#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void limpatela()
{
    system("cls");
}

struct ContaBancaria
{
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
};

void depositar(struct ContaBancaria *conta, float valor)
{
    conta -> saldo += valor;
    printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor > conta->saldo)
    {
        printf("Saldo insuficiente para saque.\n");
    }
    else
    {
        conta -> saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
    }
}

void imprimirSaldo(struct ContaBancaria conta)
{
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ContaBancaria minhaConta;

    minhaConta.numeroConta = 1234;

    strcpy(minhaConta.nomeTitular, "Elizia");

    minhaConta.saldo = 1000.0;

    strcpy(minhaConta.tipoConta, "Corrente");

    int opcao;
    float valor;
    int voltarMenu;

    do
    {
        printf("__________________________________\n");
        printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨MENU¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
        printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Imprimir Saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        limpatela();

        switch (opcao)
        {
        case 1:
            printf("Insira o valor do depósito: ");
            scanf("%f", &valor);

            limpatela();
            depositar(&minhaConta, valor);
            break;
        case 2:
            printf("Insira o valor do saque: ");
            scanf("%f", &valor);

            limpatela();
            sacar(&minhaConta, valor);
            break;
        case 3:
            imprimirSaldo(minhaConta);
            break;
        case 4:
            printf("Obrigado por utilizar nossos serviços :)!\n");
            voltarMenu = 0;
            break;
        
        default:
            printf("Opção inválida!\nTente novamente.\n");
            voltarMenu = 1;
        }

        if (opcao != 4)
        {
            printf("\nDeseja voltar para o menu?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d", &voltarMenu);

            if (voltarMenu != 1)
            {
                limpatela();
                printf("Obrigado pela preferência, volte sempre :)!");
                break;
            }
        }
        
        limpatela();

    } while (voltarMenu);

    return 0;
}
