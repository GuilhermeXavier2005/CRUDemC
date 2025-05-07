#include "header/header.h"

int DeletarProduto(ListaDeProdutos *lt) {
    if (lt->qtd == 0) {
      printf("Erro: Nao ha produtos cadastrados para deletar.\n");
      return 1; // Lista vazia
    }
  
    lisProduto(lt); // Mostra os produtos para o usuário escolher qual deletar
  
    int pos;
    printf("\n insira o numero do produto para deletar: ");
    while (scanf("%d", &pos) != 1) {
      printf("Entrada invalida. Digite um numero: ");
      while (getchar() != '\n')
        ; // Limpa buffer
    }
    getchar();
  
    if (pos >= lt->qtd || pos < 0) {
      printf("Erro: Posicao invalida.\n");
      return 2;
    }
  
    for (int i = pos; i < lt->qtd - 1; i++) {
      lt->produtos[i] = lt->produtos[i + 1];
    }
  
    lt->qtd--; // Decrementa a quantidade de produtos
    printf("Produto deletado com sucesso!\n");
    GerarRelatorio(lt, RelatorioEstoque);
    return 0; // Sucesso
  }