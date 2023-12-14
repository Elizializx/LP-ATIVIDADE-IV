#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_FUNCIONARIOS 100

void menu()
{
    printf("_________________________________\n");
    printf("��������MENU FUNCION�RIOS��������\n");
    printf("���������������������������������\n");
}

void limpatela()
{
    system("cls");
}

struct Funcionario
{
    char nome[50];
    char cargo[50];
    float salario;
};

float calcularMediaSalarial(struct Funcionario *funcionarios, int numFuncionarios, char *cargo)
{
    float somaSalarios = 0;
    int contador = 0;
    int i;

    for (i = 0; i < numFuncionarios; i++)
    {
        if (strcmp(funcionarios[i].cargo, cargo) == 0)
        {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    return (contador > 0) ? (somaSalarios / contador) : 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios;
    int i;

    menu();

    printf("BEM-VINDO!");
    printf("\n\n");

    printf("Insira a quantidade de funcion�rios a serem registrados: ");
    scanf("%d", &numFuncionarios);

    limpatela();

    for (i = 0; i < numFuncionarios; i++)
    {
        printf("Insira o nome do %d� funcion�rio: ", i + 1);
        scanf("%s", funcionarios[i].nome);

        printf("Insira o cargo do funcion�rio: ", i + 1);
        scanf("%s", funcionarios[i].cargo);

        printf("Insira o sal�rio do funcion�rio: ", i + 1);
        scanf("%f", &funcionarios[i].salario);

        limpatela();
    }

    char cargoProgramador[50];

    printf("Insira o cargo que deseja calcular a m�dia salarial: ");
    scanf("%s", cargoProgramador);

    limpatela();

    float mediaSalarialProgramadores = calcularMediaSalarial(funcionarios, numFuncionarios, cargoProgramador);

    printf("Exibindo resultados.");
    sleep(1);
    limpatela();
    printf("Exibindo resultados..");
    sleep(1);
    limpatela();
    printf("Exibindo resultados...");
    sleep(1);
    limpatela();

    printf("Exibindo resultado: ");
    printf("\n\n");

    if (mediaSalarialProgramadores > 0)
    {
        printf("A m�dia salarial dos %s �: R$ %.2f\n", cargoProgramador, mediaSalarialProgramadores);
    }
    else
    {
        printf("Nenhum funcion�rio encontrado com o cargo %s.\n", cargoProgramador);
    }

    return 0;
}
