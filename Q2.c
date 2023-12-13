#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define NUM_ALUNOS 5
#define MAX_NOME 50

void cabecalho()
{
    printf("_________________________\n");
    printf("��������SENAI DEN��������\n");
    printf("�������������������������\n");
}

void limpatela()
{
    system("cls");
}

void tempo()
{
    sleep(1);
}

struct aluno 
{
    char nome[MAX_NOME];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(float nota1, float nota2) 
{

    return (nota1 + nota2)/2;
}

void verificarAprovacao(float media) 
{
    if (media >= 7) 
    {
        printf("Parab�ns, APROVADOOOOOO :)!\n");
    } 
    else 
    {
        printf("Complicado, reprovado :(!\n");
    }
}

int main(){
    setlocale(LC_ALL, "portuguese");
    
    struct aluno alunos[NUM_ALUNOS];

    int i;  

    for (i = 0; i < NUM_ALUNOS; i++) 
    {
        cabecalho();

        printf("Insira o nome do %d� aluno : ", i + 1);
        fgets(alunos[i].nome, MAX_NOME, stdin);

        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        do 
        {
            printf("Insira a 1� nota do aluno : ", i + 1);
            scanf("%f", &alunos[i].nota1);

            if (alunos[i].nota1 < 0 || alunos[i].nota1 > 10) 
            {
                printf("Nota inv�lida!\nInsira novamente.\n");
            }
        } while (alunos[i].nota1 < 0 || alunos[i].nota1 > 10);

        getchar();

        do 
        {
            printf("Insira a 2� nota do aluno : ", i + 1);
            scanf("%f", &alunos[i].nota2);

            if (alunos[i].nota2 < 0 || alunos[i].nota2 > 10) 
            {
                printf("Nota inv�lida!\nInsira novamente.\n");
            }
        } while (alunos[i].nota2 < 0 || alunos[i].nota2 > 10);

        limpatela();
        getchar(); 

        alunos[i].media = calcularMedia(alunos[i].nota1, alunos[i].nota2);
    }
    
    printf("Calculando e gerando informa��es.");
    tempo();
    limpatela();
    printf("Calculando e gerando informa��es..");
    tempo();
    limpatela();
    printf("Calculando e gerando informa��es...");
    tempo(); 
    limpatela();

    cabecalho();

    printf("\nM�dia de cada aluno:\n");
    
    for (i = 0; i < NUM_ALUNOS; i++) 
    {
        printf("%s: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    printf("\nSitua��o dos alunos:\n");

    for (i = 0; i < NUM_ALUNOS; i++)
    {
        printf("%s: ", alunos[i].nome);
        verificarAprovacao(alunos[i].media);
    }

    return 0;
}