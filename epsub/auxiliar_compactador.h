#pragma once

#define MAX 256

void ler_arquivo(std::string nome_arquivo, std::string *conteudo);

void montar_frequencia(std::string conteudo, unsigned int *frequencias);