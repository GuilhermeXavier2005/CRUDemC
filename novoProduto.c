#include "header/header.h"

int NovoProduto(ListaDeProdutos *lt) {
  char escolha;
  if (lt->qtd >= TotalProdutos) {
    printf("\nLista de produtos cheia.");
    return 1;
  }

  Produto *p = &lt->produtos[lt->qtd];

  printf("\n--- Cadastro de Novo Produto ---\n");

  // Solicita e lê o código
  printf("Digite o codigo do produto: ");
  while (scanf("%d", &p->codigo) != 1 || p->codigo <= 0) {
    printf("Codigo invalido. Digite um numero inteiro positivo: ");
    while (getchar() != '\n')
      ; // Limpa o buffer de entrada
  }
  getchar(); // Consome o '\n' deixado pelo scanf

  // Verifica se o código já existe
  if (BuscarProdutoPorCodigo(lt, p->codigo) != -1) {
    printf("Erro: Codigo de produto ja existente.\n");
    return 2; // Código duplicado
  }

  // Solicita e lê o nome
  printf("Digite o nome do produto: ");
  fgets(p->nome, sizeof(p->nome), stdin);
  p->nome[strcspn(p->nome, "\n")] = '\0';

  // Solicita e lê a descrição
  printf("Digite a descricao do produto: ");
  fgets(p->descricao, sizeof(p->descricao), stdin);
  p->descricao[strcspn(p->descricao, "\n")] = '\0';

  // Solicita e lê a quantidade inicial
  printf("Digite a quantidade inicial em estoque: ");
  while (scanf("%d", &p->quantidade) != 1 || p->quantidade < 0) {
    printf("Digite um numero válido: ");
    while (getchar() != '\n')
      ; // Limpa buffer
  }
  getchar(); // Consome o '\n'

  // lê o preço unitário
  printf("Digite o preco unitario do produto (ex: 10.50): ");
  while (scanf("%f", &p->preco) != 1 || p->preco < 0) {
    printf("Preco invalido. Digite um numero nao negativo: ");
    while (getchar() != '\n')
      ; // Limpa buffer
  }
  getchar(); // Consome o '\n'

  lt->qtd++; // Incrementa a quantidade de produtos cadastrados
  printf("Produto cadastrado com sucesso!\n");
  GerarRelatorio(lt, RelatorioEstoque);
}