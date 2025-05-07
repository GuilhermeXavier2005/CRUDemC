#include "header/header.h"

void MostrarRelatorio(const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r"); // Abre para leitura de texto ('r')
    if (fp == NULL) {
      // informa a possibilidade da inexistencia do arquivo
      printf("\n '%s' nao encontrado.\n", nomeArquivo);
      printf("O relatorio e gerado/atualizado automaticamente apos qualquer "
             "alteracao no estoque.\n");
      return;
    }
  
    printf("\n--- Conteudo do Relatorio de Estoque (%s) ---\n\n", nomeArquivo);
    char linha[256]; // Cria um buffer para armazenar cada linha lida
  
    // Lê o arquivo linha por linha até o final (EOF)
    while (fgets(linha, sizeof(linha), fp) != NULL) {
      printf(
          "%s",
          linha); // Imprime a linha lida (fgets já inclui o \n no final da linha)
    }
  
    printf("\n--- Fim do Relatorio ---\n");
  
    fclose(fp); // Fecha o arquivo
  }