#include "header/header.h"

int BuscarProdutoPorCodigo(ListaDeProdutos *lt, int codigo) {
    for (int i = 0; i < lt->qtd; i++) {
      if (lt->produtos[i].codigo == codigo) {
        return i; // Retorna o índice onde o produto foi encontrado
      }
    }
    return -1; // se o produto não for encontrado, retorna -1
  }