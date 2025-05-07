#include "header/header.h"

int RegistrarSaida(ListaDeProdutos *lt) {
    if (lt->qtd == 0) {
      printf("Erro: Nao ha produtos cadastrados.\n");
      return 1; // Lista vazia
    }
  
    lisProduto(lt); // Mostra produtos para facilitar a escolha
  
    int codigo_produto;
    printf("\n insira o codigo do produto: ");
    while (scanf("%d", &codigo_produto) != 1) {
      printf("Entrada invalida. Digite um numero: ");
      while (getchar() != '\n')
        ; // Limpa buffer
    }
    getchar(); // Consome o '\n'
  
    int pos = BuscarProdutoPorCodigo(lt, codigo_produto);
  
    if (pos == -1) {
      printf("codigo %d nao encontrado.\n", codigo_produto);
      return 2; // Produto não encontrado
    }
  
    Produto *p = &lt->produtos[pos];
    int quantidade_saida;
    printf("Produto encontrado: %s (Estoque atual: %d)\n", p->nome,
           p->quantidade);
    printf("Digite a quantidade de svenda: ");
    while (scanf("%d", &quantidade_saida) != 1 || quantidade_saida <= 0) {
      printf("Quantidade invalida. Digite um numero inteiro positivo: ");
      while (getchar() != '\n')
        ; // Limpa buffer
    }
    getchar(); // Consome o '\n'
  
    if (quantidade_saida > p->quantidade) {
      printf("Erro: Estoque insuficiente para registrar a saida.\n");
      printf("Quantidade solicitada: %d, Estoque disponivel: %d\n",
             quantidade_saida, p->quantidade);
      return 4; // Estoque insuficiente
    }
  
    p->quantidade -= quantidade_saida; // Subtrai a quantidade do estoque
    printf("Saida registrada com sucesso! Novo estoque de '%s': %d\n", p->nome,
           p->quantidade);
    GerarRelatorio(lt, RelatorioEstoque);
    return 0; // Sucesso
  }