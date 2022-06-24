#include "grafos.h"

std::vector<int>* construir_grafo_inteiros(int v, int e){
    std::vector<int> *adj = new std::vector<int>[v];
    
    for(int i = 0 ; i < v ; i++){
        adj[i] = std::vector<int>();
    }

    for(int i = 0 ; i < e ; i++){
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

void dfs(int vertice, std::vector<int> *adj, int *visitados, int componente){
    visitados[vertice] = componente;
    for(auto vizinho : adj[vertice]){
        if(visitados[vizinho] == -1)
            dfs(vizinho, adj, visitados, componente);
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
                distancias[vizinho] = distancias[atual] + 1;
                fila.push(vizinho);
            }
        }
    }
}

int calcular_componentes(std::vector<int> *adj, int *visitados, int num_vertices){
    int num_componentes = 0;
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        if(visitados[vertice] == -1){
            dfs(vertice, adj, visitados, num_componentes);
            num_componentes++;
        }
    }
    return num_componentes;
}

void identificar_componentes(std::vector<int> *adj, int num_vertices){
    int *visitados = new int[num_vertices]; memset(visitados, -1, num_vertices * sizeof(int));
    int *tamanho_componentes = new int[num_vertices]; memset(tamanho_componentes, 0, num_vertices * sizeof(int));

    int num_componentes = calcular_componentes(adj, visitados, num_vertices);

    for(int i = 0 ; i < num_vertices ; i++)
        tamanho_componentes[visitados[i]]++;

    std::cout << "Número de componentes conexas: " << num_componentes << std::endl;

    for(int i = 0 ; i < num_componentes ; i++)
        std::cout << "Tamanho da componente " << i+1 << ": " << tamanho_componentes[i] << std::endl;
}

void calcular_distancias(std::vector<int> *adj, int num_vertices){
    bool *visitados = new bool[num_vertices];
    int *distancias = new int [num_vertices];
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        memset(visitados, false, num_vertices * sizeof(bool));
        memset(distancias, -1, num_vertices * sizeof(distancias));
        bfs(vertice, adj, visitados, distancias);
        imprimir_distancias(vertice, distancias, num_vertices);
    }
}

void imprimir_distancias(int vertice_base, int *distancias, int num_vertices){
    std::cout << "Imprimindo as distâncias dos vértices em relação ao vértice " << vertice_base << ": " << std::endl;
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        if(vertice != vertice_base) std::cout << "A distância entre " << vertice_base << " e " << vertice << " é: " << distancias[vertice] << std::endl;
    }
}