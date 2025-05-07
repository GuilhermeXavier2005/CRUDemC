#include "header/header.h"

int main() {
    ListaDeProdutos lista_estoque; 
    int codigo_retorno;            
    int opcao;                     

    do {
            menu();
        while (scanf("%d", &opcao) != 1) { 
             printf("Digite um numero entre as opções");
             // Limpa o buffer de entrada em caso de erro
             while(getchar() != '\n');
        }
        getchar(); // Consome o caractere '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                codigo_retorno = NovoProduto(&lista_estoque);
                break;
            case 2:
                codigo_retorno = RegistrarEntrada(&lista_estoque);
                break;
            case 3:
                codigo_retorno = RegistrarSaida(&lista_estoque);
                break;
            case 4:
                    lisProduto(&lista_estoque);
                break;
            case 5:
                 codigo_retorno = consulProduto(&lista_estoque);
                 break;
            case 6:
                 codigo_retorno = AlterarProduto(&lista_estoque);
                 break;
            case 7:
                codigo_retorno = DeletarProduto(&lista_estoque);
                break;
            case 8:
                 MostrarRelatorio(RelatorioEstoque);
                 break;
            case 0:
                printf("\nSaindo do programa...\n");
            default:
                printf("\nOpcao invalida.\n");
                break;
        }

        // Pausa opcional para o usuário ver a saída antes do menu reaparecer
        if (opcao != 0) {
             printf("\nPressione Enter para continuar...");
             getchar(); // Espera o usuário pressionar Enter
        }


    } while (opcao != 0); 

    // Salva os dados no arquivo binário antes de finalizar o programa
    codigo_retorno = cadastrarProduto(&lista_estoque, Estoque);
    if (codigo_retorno == 0) {
        printf("Dados salvos com sucesso em '%s'.\n", Estoque);
    } else {
        printf("Erro ao salvar os dados no arquivo '%s'.\n", Estoque);
    }

    printf("Programa finalizado.\n");

    return 0;
}