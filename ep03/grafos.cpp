#include "grafos.h"

std::vector<int>* construir_grafo_inteiros(int num_vertices, int num_arestas){
    std::vector<int> *adj = new std::vector<int>[num_vertices];
    
    for(int i = 0 ; i < num_vertices ; i++){
        adj[i] = std::vector<int>();
    }

    for(int i = 0 ; i < num_arestas ; i++){
        std::cout << "Digite uma aresta do grafo no formato \"vertice_1 vertice_2\": ";
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

std::vector<int>* construir_grafo_aleatorio(int num_vertices, double probabilidade){
    std::vector<int> *adj = new std::vector<int>[num_vertices];

    for(int i = 0 ; i < num_vertices ; i++){
        adj[i] = std::vector<int>();
    }

    srand(time(0));

    for(int u = 0 ; u < num_vertices ; u++){
        for(int v = u + 1 ; v < num_vertices ; v++){
            double aleatorio = rand() / (RAND_MAX + 1.0);
            if(aleatorio <= probabilidade){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    return adj;
}

// toDo
std::vector<int>* construir_grafo_palavras(int num_vertices, std::map<std::string, int> &indices_palavras){
}

void dfs(int vertice, std::vector<int> *adj, int *visitados, int componente){
    visitados[vertice] = componente;
    for(auto vizinho : adj[vertice]){
        if(visitados[vizinho] == -1)
            dfs(vizinho, adj, visitados, componente);
    }
}

int bfs(int vertice, std::vector<int> *adj, int num_vertices, bool *visitados, int *distancias){
    memset(visitados, false, num_vertices * sizeof(bool));
    memset(distancias, -1, num_vertices * sizeof(int));
    int maior_distancia = 0;
    std::queue<int> fila;
    fila.push(vertice);
    visitados[vertice] = true;
    distancias[vertice] = 0;
    while(!fila.empty()){
        int atual = fila.front(); fila.pop();
        for(auto vizinho : adj[atual]){
            if(!visitados[vizinho]){
                visitados[vizinho] = true;
                distancias[vizinho] = distancias[atual] + 1;
                maior_distancia = std::max(maior_distancia, distancias[vizinho]);
                fila.push(vizinho);
            }
        }
    }

    return maior_distancia;
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

int* identificar_componentes(std::vector<int> *adj, int num_vertices, int &num_componentes){
    int *visitados = new int[num_vertices]; memset(visitados, -1, num_vertices * sizeof(int));
    num_componentes = calcular_componentes(adj, visitados, num_vertices);
    int *tamanho_componentes = new int[num_componentes]; memset(tamanho_componentes, 0, num_componentes * sizeof(int));

    for(int i = 0 ; i < num_vertices ; i++)
        tamanho_componentes[visitados[i]]++;

    return tamanho_componentes;
}

void calcular_distancias(std::vector<int> *adj, int num_vertices){
    bool *visitados = new bool[num_vertices];
    int *distancias = new int [num_vertices];
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        bfs(vertice, adj, num_vertices, visitados, distancias);
        imprimir_distancias(vertice, distancias, num_vertices);
    }
}

void imprimir_distancias(int vertice_base, int *distancias, int num_vertices){
    std::cout << "Imprimindo as dist??ncias dos v??rtices em rela????o ao v??rtice " << vertice_base << ": " << std::endl;
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        if(vertice != vertice_base) std::cout << "A dist??ncia entre " << vertice_base << " e " << vertice << " ??: " << distancias[vertice] << std::endl;
    }
}

void testar_erdos(std::vector<int> *adj, int num_vertices, double probabilidade, int *tamanho_componentes, int num_componentes){
    double np = num_vertices * probabilidade;
    double e = 1e-2;
    double logN = log(num_vertices);
    double n23 = pow(num_vertices, 2./3);

    std::sort(tamanho_componentes, tamanho_componentes + num_componentes);

    if(np < 1 - e){
        std::cout << "\"Como n*p < 1, o grafo quase certamente n??o ter?? componentes conexas de tamanho maior que logN.\"\n";
        if(tamanho_componentes[num_componentes - 1] > logN)
            std::cout << "Propriedade desrespeitada!\n";
        else
            std::cout << "Propriedade respeitada!\n";
        std::cout << "A maior componente possui " << tamanho_componentes[num_componentes - 1] << " v??rtices.\n";
    }
    else if(np > 1 + e){
        std::cout << "\"Como n*p > 1, o grafo quase certamente conter?? uma componente gigante e todas as componentes conter??o menos que logN v??rtices.\"\n";
        bool ok = true;
        for(int i = 0 ; i < num_componentes - 1 && ok ; i++) 
            if(tamanho_componentes[i] > logN) ok = false;
        if(ok)
            std::cout << "O grafo possui uma componente gigante, propriedade respeitada!\n";
        else
            std::cout << "O grafo n??o possui uma componente gigante, propriedade desrespeitada!\n";
        std::cout << "A maior componente possui " << tamanho_componentes[num_componentes - 1] << " v??rtices.\n";
    }
    else{
        std::cout << "\"Como n*p pr??ximo de 1, ent??o o grafo quase certamente ter?? uma componente maior de tamanho n??(2/3).\"\n";
        if(tamanho_componentes[num_componentes - 1] >= n23)
            std::cout << "Propriedade respeitada!\n";
        else
            std::cout << "Propriedade desrespeitada!\n";
        std::cout << "A maior componente possui " << tamanho_componentes[num_componentes - 1] << " v??rtices.\n";
    }
}

void testar_separacao(std::vector<int> *adj, int num_vertices){
    int num_componentes;
    int *visitadosDFS = new int[num_vertices]; memset(visitadosDFS, -1, num_vertices * sizeof(int));
    num_componentes = calcular_componentes(adj, visitadosDFS, num_vertices);
    if(num_componentes > 1){
        std::cout << "N??o h?? uma conex??o v??lida entre uma pessoa e qualquer outra nesse grafo.\n";
        std::cout << "Seis graus de separa????o n??o respeitados.\n";
        return;
    }
    int maior_distancia = 0;  
    bool *visitados = new bool[num_vertices];
    int *distancias = new int[num_vertices];
    for(int vertice = 0 ; vertice < num_vertices ; vertice++){
        maior_distancia = std::max(maior_distancia, bfs(vertice, adj, num_vertices, visitados, distancias));
        if(maior_distancia > 6){
            std::cout << "Seis graus de separa????o n??o respeitados, tente aumentar o n??mero de v??rtices ou a probabilidade de duas pessoas se conhecerem.\n";
            return;
        }
    }
    std::cout << "Seis graus de separa????o respeitados. A maior dist??ncia entre duas pessoas no grafo ?? menor ou igual a 6!\n";
    std::cout << "Maior dist??ncia entre duas pessoas ??: " << maior_distancia << std::endl;
}

// toDo
void testar_palavras(std::vector<int> *adj, int num_vertices, std::map<int, std::string> *vertices){
}