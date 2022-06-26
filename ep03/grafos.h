#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

std::vector<int>* construir_grafo_inteiros(int num_vertices, int num_arestas);

std::vector<int>* construir_grafo_aleatorio(int num_vertices, double probabilidade);

std::vector<int>* construir_grafo_palavras(int num_vertices, std::map<std::string, int> &indices_palavras);

void dfs(int vertice, std::vector<int> *adj, bool *visitados);

void bfs(int vertice, std::vector<int> *adj, bool *visitados, int *distancias);

int calcular_componentes(std::vector<int> *adj, int num_vertices);

void identificar_componentes(std::vector<int> *adj, int num_vertices);

void calcular_distancias(std::vector<int> *adj, int num_vertices); 

void imprimir_distancias(int vertice, int *distancias, int num_vertices);

void testar_erdos(std::vector<int> *adj, int num_vertices);