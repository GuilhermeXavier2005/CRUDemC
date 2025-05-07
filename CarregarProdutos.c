#include "header/header.h"

int CarregarProdutos(ListaDeProdutos *lt, const char *nomeArquivo) {
    FILE *fp =fopen(nomeArquivo, "rb"); 
    if (fp == NULL) {
      // Se o arquivo não existe (pode ser a primeira execução), não é um erro
      // fatal. A lista será inicializada como vazia (lt->qtd = 0) na main.
      printf("Aviso: Arquivo '%s' nao encontrado.\n", nomeArquivo);
      lt->qtd =
          0; // Garante que a quantidade seja 0 se o arquivo não for carregado
      return 1;
    }
  
    fread(lt, sizeof(ListaDeProdutos), 1, fp);
    fclose(fp); // Fecha o arquivo
    printf(
        "Dados carregados com sucesso do arquivo '%s'. %d produtos carregados.\n",
        nomeArquivo, lt->qtd);
    return 0; // Sucesso
  }