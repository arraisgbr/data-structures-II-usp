#include "grafos.h"

std::vector<int>* construir_grafo_inteiros(int v, int e){
    std::vector<int> adj[v];
    for(int i = 0 ; i < e ; i++){
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

void dfs(int vertice, std::vector<int> *adj, bool *visitados){
    visitados[vertice] = true;
    for(auto vizinho : adj[vertice]){
        if(!visitados[vizinho])
            dfs(vizinho, adj, visitados);
    }
}

void bfs(int vertice, std::vector<int> *adj, bool *visitados, int *distancias){
    std::queue<int> fila;
    fila.push(vertice);
    distancias[vertice] = 0;
    while(!fila.empty()){
        int atual = fila.front(); fila.pop();
        visitados[atual] = true;
        for(auto vizinho : adj[vertice]){
            if(!visitados[vizinho]){
                distancias[vizinho] = distancias[atual]++;
                fila.push(vizinho);
            }
        }
    }
}

int calcular_componentes(std::vector<int> *adj, int num_vertices){
    bool visitados[num_vertices]; memset(visitados, false, sizeof(visitados));
    int num_componentes = 0;
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        if(!visitados[vertice]){
            dfs(vertice, adj, visitados);
            num_componentes++;
        }
    }
    return num_componentes;
}

void calcular_distancias(std::vector<int> *adj, int num_vertices){
    bool visitados[num_vertices];
    int distancias[num_vertices];
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        memset(visitados, false, sizeof(visitados));
        memset(visitados, -1, sizeof(distancias));
        bfs(vertice, adj, visitados, distancias);
        imprimir_distancias(vertice, num_vertices, distancias);
    }
}

void imprimir_distancias(int vertice_base, int *distancias, int num_vertices){
    std::cout << "Imprimindo as distâncias dos vértices em relação ao vértice " << vertice_base << ": " << std::endl;
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        if(vertice != vertice_base) std::cout << "A distância entre " << vertice_base << " e " << vertice << " é: " << distancias[vertice] << std::endl;
    }
}