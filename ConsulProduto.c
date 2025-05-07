#include "header/header.h"

int consulProduto(ListaDeProdutos *lt) {
    if (lt->qtd == 0) {
      printf("Erro: Nao ha produtos cadastrados para consultar.\n");
      return 1; // Lista vazia
    }
  
    int opcao;
    printf("\n--- Consultar Produto ---\n");
    printf("Consultar por:\n");
    printf("1. Codigo\n");
    printf("2. Nome\n");
    printf("Escolha uma opcao: ");
    while (scanf("%d", &opcao) != 1 || (opcao != 1 && opcao != 2)) {
      printf("Opcao invalida");
      while (getchar() != '\n')
        ; // Limpa buffer
    }
    getchar(); // Consome o '\n'
  
    int encontrados = 0;
  
    if (opcao == 1) { // Consultar por Código
      int codigo_busca;
      printf("Digite o codigo do produt: ");
      while (scanf("%d", &codigo_busca) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        while (getchar() != '\n')
          ; // Limpa buffer
      }
      getchar(); // Consome o '\n'
  
      printf("\n--- Resultado da Busca por Codigo (%d) ---\n", codigo_busca);
      int pos = BuscarProdutoPorCodigo(lt, codigo_busca);
      if (pos != -1) {
        Produto *p = &lt->produtos[pos];
        printf("Pos: %d | Codigo: %d | Nome: %s | Descricao: %s | Qtd: %d | "
               "Preco: R$%.2f\n",
               pos, p->codigo, p->nome, p->descricao, p->quantidade, p->preco);
        encontrados++;
      }
  
    } else { // Consultar por Nome
      char nome_busca[50];
      printf("Digite o nome do produt: ");
      fgets(nome_busca, sizeof(nome_busca), stdin);
      nome_busca[strcspn(nome_busca, "\n")] = '\0';
  
      printf("\n--- Resultado da Busca (\"%s\") ---\n", nome_busca);
      for (int i = 0; i < lt->qtd; i++) {
        // strstr verifica se nome_busca é uma substring de lt->produtos[i].nome
        if (strstr(lt->produtos[i].nome, nome_busca) != NULL) {
          Produto *p = &lt->produtos[i];
          printf("Pos: %d | Codigo: %d | Nome: %s | Descricao: %s | Qtd: %d | "
                 "Preco: R$%.2f\n",
                 i, p->codigo, p->nome, p->descricao, p->quantidade, p->preco);
          encontrados++;
        }
      }
    }
  
    if (encontrados == 0) {
      printf("Nenhum produto encontrado com o criterio informado.\n");
    } else {
      printf("------------------------------------------\n");
      printf("%d produto(s) encontrado(s).\n", encontrados);
    }
  
    return 0; // Consulta realizada
  }