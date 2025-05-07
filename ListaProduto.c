#include "header/header.h"

void lisProduto(ListaDeProdutos *lt) {
    printf("\n--- Lista de Produtos Cadastrados (%d) ---\n", lt->qtd);
    if (lt->qtd == 0) {
      printf("Nenhum produto cadastrado.\n");
      return;
    }
  
    printf("---------------------------------------------------------------------"
           "---------------\n");
    printf("| Pos | Codigo | Nome                 | Descricao                    "
           "  | Qtd | Preco R$ |\n");
    printf("---------------------------------------------------------------------"
           "---------------\n");
  
    for (int i = 0; i < lt->qtd; i++) {
      Produto *p = &lt->produtos[i];
      printf("| %-3d | %-6d | %-20.20s | %-30.30s | %-3d | %-8.2f |\n", i,
             p->codigo, p->nome, p->descricao, p->quantidade, p->preco);
    }
    printf("---------------------------------------------------------------------"
           "---------------\n");
  }