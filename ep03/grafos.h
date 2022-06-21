#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

std::vector<int>* construir_grafo_inteiros(int v, int e);

void dfs(int vertice, std::vector<int> *adj, bool *visitados);

void bfs(int vertice, std::vector<int> *adj, bool *visitados, int *distancias);

int calcular_componentes(std::vector<int> *adj, int num_vertices);

void calcular_distancias(std::vector<int> *adj, int num_vertices); 

void imprimir_distancias(int vertice, int num_vertices, int *distancias);