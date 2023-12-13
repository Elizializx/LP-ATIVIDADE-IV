#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void limpatela()
{
    system("cls");
}

struct Produto
{
    char nome[50];
    float preco;
    int quantidade;
};

float calcularValorTotal(struct Produto produto)
{
    return produto.preco * produto.quantidade;
}

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;

    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    limpatela();

    if (quantidadeCompra > 0)
    {
        produto -> quantidade += quantidadeCompra;
        
        printf("Compra realizada com sucesso!\n");
        printf("\n");

        int opcao2;

        printf("Deseja voltar para o menu?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        scanf("%d", &opcao2);

        switch (opcao2)
        {
        case 1:
            limpatela();
            break;

        default:
        limpatela();
            printf("Obrigado pela preferência :)!\n");
            exit(0);
            break;
        }
    }
    else
    {
        printf("Quantidade inválida!\n");
    }
}

void consultarEstoque(struct Produto produto)
{
    printf("\nNome do Produto: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em Estoque: %d\n", produto.quantidade);
    printf("Valor Total em Estoque: R$ %.2f\n\n", calcularValorTotal(produto));

    int opcao2;

    printf("Deseja voltar para o menu?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &opcao2);

    switch (opcao2)
    {
    case 1:
        limpatela();
        break;

    default:
    limpatela();
        printf("Obrigado pela preferência :)!\n");
        exit(0);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Produto meuProduto = {"Produto", 10.5, 20};

    int opcao;

    do
    {
        printf("__________________________________\n");
        printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨MENU¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
        printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair\n");
        printf("Insira a opção desejada: ");
        scanf("%d", &opcao);

        limpatela();

        switch (opcao)
        {
        case 1:
            realizarCompra(&meuProduto);
            break;
        case 2:
            consultarEstoque(meuProduto);
            break;
        case 3:
            printf("Volte sempre :)!\n");
            break;

        default:
            printf("Opção inválida!\nInsira novamente.\n");
            break;
        }
    } while (opcao != 3);

    return 0;
}
