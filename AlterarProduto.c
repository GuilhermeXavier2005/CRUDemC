#include "header/header.h"

int AlterarProduto(ListaDeProdutos *lt) {
  if (lt->qtd == 0) {
    printf("Erro: Nao ha produtos cadastrados para alterar.\n");
    return 1; // Lista vazia
  }

  lisProduto(lt); // Mostra os produtos

  int pos;
  printf("\nDigite o NUMERO (posicao na lista acima, comecando em 0) do "
         "produto que deseja alterar: ");
  while (scanf("%d", &pos) != 1) {
    printf("Entrada invalida. Digite um numero: ");
    while (getchar() != '\n')
      ; // Limpa buffer
  }
  getchar(); // Consome o '\n'

  if ( pos >= lt->qtd|| pos < 0) {
    printf("Erro: Posicao invalida.\n");
    return 2; // Posição inválida
  }

  Produto *p = &lt->produtos[pos]; // Ponteiro para o produto a ser alterado

  printf("\n--- Alterando Produto (Codigo: %d) ---\n", p->codigo);
  printf("Nome atual: %s\n", p->nome);
  printf("Descricao atual: %s\n", p->descricao);
  printf("Quantidade atual: %d\n", p->quantidade);
  printf("Preco atual: %.2f\n", p->preco);

  char opcao;

  // Alterar Nome
  printf("\nDeseja alterar o nome? (s/n): ");
  scanf(" %c", &opcao);
  getchar();
  if (opcao == 's') {
    printf("Digite o novo nome: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';
  }

  // Alterar Descrição
  printf("Deseja alterar a descricao? (s/n): ");
  scanf(" %c", &opcao);
  getchar();
  if (opcao == 's') {
    printf("Digite a nova descricao: ");
    fgets(p->descricao, sizeof(p->descricao), stdin);
    p->descricao[strcspn(p->descricao, "\n")] = '\0';
  }

  // Alterar Quantidade
  printf("Deseja alterar a quantidade? (s/n): ");
  scanf(" %c", &opcao);
  getchar();
  if (opcao == 's') {
    printf("Digite a nova quantidade: ");
    while (scanf("%d", &p->quantidade) != 1 || p->quantidade < 0) {
      printf("Quantidade invalida. Digite um numero nao negativo: ");
      while (getchar() != '\n')
        ;
    }
    getchar();
  }

  // Alterar Preço
  printf("Deseja alterar o preco? (s/n): ");
  scanf(" %c", &opcao);
  getchar();
  if (opcao == 's') {
    printf("Digite o novo preco: ");
    while (scanf("%f", &p->preco) != 1 || p->preco < 0) {
      printf("Preco invalido. Digite um numero nao negativo: ");
      while (getchar() != '\n')
        ;
    }
    getchar();
  }

  printf("Produto alterado com sucesso!\n");
  GerarRelatorio(lt, RelatorioEstoque);
  return 0; // Sucesso
}