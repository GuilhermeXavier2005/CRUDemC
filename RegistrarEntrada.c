#include "header/header.h"

int RegistrarEntrada(ListaDeProdutos *lt) {
    if (lt->qtd == 0) {
      printf("Erro: Nao ha produtos cadastrados.\n");
      return 1; // Lista vazia
    }
  
    lisProduto(lt); // Mostra produtos para facilitar a escolha
  
    int codigo_produto;
    printf("\nDigite o CODIGO do produto para registrar entrada: ");
    while (scanf("%d", &codigo_produto) != 1) {
      printf("Entrada invalida. Digite um numero: ");
      while (getchar() != '\n')
        ; // Limpa buffer
    }
    getchar(); // Consome o '\n'
  
    int pos = BuscarProdutoPorCodigo(lt, codigo_produto);
  
    if (pos == -1) {
      printf("Produto nao foi encontrado.\n");
      return 2; // Produto não encontrado
    }
  
    Produto *p = &lt->produtos[pos];
    int quantidade_entrada;
    printf("Produto encontrado: %s (Estoque atual: %d)\n", p->nome,
           p->quantidade);
    printf("Digite as entradas e compras: ");
    while (scanf("%d", &quantidade_entrada) != 1 || quantidade_entrada <= 0) {
      printf("Quantidade invalida. Digite um numero inteiro positivo: ");
      while (getchar() != '\n')
        ; // Limpa buffer
    }
    getchar(); // Consome o '\n'
  
    p->quantidade += quantidade_entrada; // Adiciona a quantidade ao estoque
    printf("Entrada registrada com sucesso! Novo estoque de '%s': %d\n", p->nome,
           p->quantidade);
    GerarRelatorio(lt, RelatorioEstoque);
    return 0; // Sucesso
  }