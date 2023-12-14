#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_FUNCIONARIOS 100

void menu()
{
    printf("_________________________________\n");
    printf("¨¨¨¨¨¨¨¨MENU FUNCIONÁRIOS¨¨¨¨¨¨¨¨\n");
    printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
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

    printf("Insira a quantidade de funcionários a serem registrados: ");
    scanf("%d", &numFuncionarios);

    limpatela();

    for (i = 0; i < numFuncionarios; i++)
    {
        printf("Insira o nome do %dº funcionário: ", i + 1);
        scanf("%s", funcionarios[i].nome);

        printf("Insira o cargo do funcionário: ", i + 1);
        scanf("%s", funcionarios[i].cargo);

        printf("Insira o salário do funcionário: ", i + 1);
        scanf("%f", &funcionarios[i].salario);

        limpatela();
    }

    char cargoProgramador[50];

    printf("Insira o cargo que deseja calcular a média salarial: ");
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
        printf("A média salarial dos %s é: R$ %.2f\n", cargoProgramador, mediaSalarialProgramadores);
    }
    else
    {
        printf("Nenhum funcionário encontrado com o cargo %s.\n", cargoProgramador);
    }

    return 0;
}
