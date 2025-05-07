#include "header/header.h"

int GerarRelatorio(ListaDeProdutos *lt, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
      printf("Erro ao tentar atualizar o arquivo de relatorio '%s'.\n",
             nomeArquivo);
      perror("Detalhes do erro");
      return 1;
    }
  
    fprintf(fp, "--- Relatorio de Estoque ---\n\n");
    fprintf(fp, "Total de produtos cadastrados: %d\n\n", lt->qtd);
    fprintf(fp, "----------------------------------------------------------------"
                "------------------------\n");
    fprintf(fp, "| Codigo | Nome                 | Descricao                     "
                " | Qtd | Preco R$ | Valor Total R$ |\n");
    fprintf(fp, "----------------------------------------------------------------"
                "------------------------\n");
  
    double valor_total_geral = 0.0;
    for (int i = 0; i < lt->qtd; i++) {
      Produto *p = &lt->produtos[i];
      double valor_total_produto = (double)p->quantidade * p->preco;
      fprintf(fp, "| %-6d | %-20.20s | %-30.30s | %-3d | %-8.2f | %-14.2f |\n",
              p->codigo, p->nome, p->descricao, p->quantidade, p->preco,
              valor_total_produto);
      valor_total_geral += valor_total_produto;
    }
  
    fprintf(fp, "----------------------------------------------------------------"
                "------------------------\n");
    fprintf(fp, "\nValor Total Geral do Estoque: R$ %.2f\n", valor_total_geral);
    fprintf(fp, "----------------------------------------------------------------"
                "------------------------\n");
  
    fclose(fp);
    return 0;
  }