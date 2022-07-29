#include <iostream>
#include <queue>
#include "auxiliar_compactador.h"

int main(int argc, char **argv){

    // verificando se o nome do arquivo foi informado
    if(argc < 2){
        std::cout << "Nome do arquivo não informado." << std::endl;
        return 1;
    }

    // lendo arquivo
    std::string nome_arquivo = argv[1];
    std::string conteudo = "";
    ler_arquivo(nome_arquivo, &conteudo);
                std::cout << conteudo << std::endl;

    // montando tabela de frequencias dos caracteres
    unsigned int frequencias[MAX];
    montar_frequencia(conteudo, frequencias);
                for(int i = 0 ; i < MAX ; i++){
                    if(frequencias[i] > 0)
                        std::cout << "Caractere " << (char)i << ": " << frequencias[i] << std::endl;
                }
}