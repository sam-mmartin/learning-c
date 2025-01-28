#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nome[20];
  float preco;
  int quantidade;
} PRODUTO;

void header()
{
  printf("***********\n");
  printf("- Mercado -\n");
  printf("***********\n\n");
}

PRODUTO adicionarProduto()
{
  PRODUTO produto;

  printf("Produto: ");
  scanf("%s", produto.nome);

  printf("\nPreço unidade: ");
  scanf("%f", &(produto.preco));

  printf("\nQuantidade: ");
  scanf("%d", &produto.quantidade);

  return produto;
}

void main()
{
  int opcao = 1, n = 0, contador = 0;
  float PrecoTotal = 0;

  header();

  while (opcao != 0)
  {
    printf("Quantos produtos deseja adicionar? ");
    scanf("%d", &n);
    system("clear");

    PRODUTO produto[n];

    for (int i = 0; i < n; i++)
    {
      header();
      printf("* %d produtos adicionados *\n", contador);
      produto[i] = adicionarProduto();

      contador++;
      system("clear");
    }

    printf("============================================================\n");
    printf("|| Produto || Preço Unitário || Quantidade || Preço Total ||\n");
    printf("============================================================\n");

    for (int i = 0; i < n; i++)
    {
      PrecoTotal = produto[i].quantidade * produto[i].preco;
      printf("|| %s ", produto[i].nome);
      printf("|| R$ %6.2f ", produto[i].preco);
      printf("|| %8d ", produto[i].quantidade);
      printf("|| R$ %6.2f ||\n", PrecoTotal);
      printf("============================================================\n");
    }

    printf("1 - Continuar\n");
    printf("0 - Finalizar\n");
    scanf("%d", &opcao);
    system("clear");
  }
}