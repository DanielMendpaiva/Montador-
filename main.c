#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <errno.h>  // Para errno
#include "biblioteca.h"

#define MAX_TAMANHO_LINHA 256
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *arquivo_assembly;
    char linha[MAX_TAMANHO_LINHA];
    const char *Assembly = "Assembly.txt";

    // (Mais tarde, você poderá pegar o nome do arquivo de entrada
    //  dos argumentos da linha de comando (argv), como especificado no projeto.
    //  Por enquanto, vamos usar "Assembly.txt" diretamente.)

    printf("Tentando abrir o arquivo: %s\n", Assembly);

    // Abre o arquivo Assembly.txt no modo de leitura ("r")
    arquivo_assembly = fopen(Assembly, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo_assembly == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo '%s'.\n", Assembly); // exibe uma mensagem de erro do sistema
        
        return EXIT_FAILURE; // Termina o programa indicando um erro
    }

    printf("\nConteúdo do arquivo '%s':\n", Assembly);
    printf("--------------------------------------------------\n");

    // Lê o arquivo linha por linha até o final (EOF - End Of File)
    // ou até ocorrer um erro.
    // fgets lê até MAX_TAMANHO_LINHA-1 caracteres, ou até uma nova linha,
    // ou até o fim do arquivo. A nova linha é incluída na string 'linha' se couber.
    while (fgets(linha, sizeof(linha), arquivo_assembly) != NULL) {
        // Imprime a linha que foi lida
        printf("%s", linha);
    }

    printf("--------------------------------------------------\n");
    printf("Leitura do arquivo concluída.\n\n");

    // Fecha o arquivo
   if (fclose(arquivo_assembly) != 0) {
    // A variável 'errno' é definida pelo sistema quando ocorre um erro em chamadas de sistema ou funções de biblioteca.
    // strerror(errno) retorna uma string descrevendo esse erro.
    fprintf(stderr, "Erro ao fechar o arquivo de entrada: %s\n", strerror(errno));
    return EXIT_FAILURE;
	}


    // Programação principal do montador virá aqui nas próximas etapas

    return EXIT_SUCCESS; // Termina o programa indicando sucesso
}