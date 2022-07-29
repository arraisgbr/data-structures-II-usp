#include "auxiliar_compactador.h"

int main(int argc, char **argv){

    // verificando se o nome do arquivo foi informado
    #pragma region
    if(argc < 2){
        std::cout << "Nome do arquivo não informado. " << std::endl
        return 1;
    }
    std::string nome_arquivo = argv[1];
    #pragma endregion

    // obtendo a árvore
    #pragma region
    Node *raiz = obter_arvore(nome_arquivo);
    #pragma endregion

    // criando arquivo .txt
    #pragma region
    criar_arquivo_txt(raiz, nome_arquivo);
    #pragma endregion
}