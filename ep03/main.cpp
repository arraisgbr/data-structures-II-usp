#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

void dfs(int vertice, vector<int>adj[], bool visited[]){
    visited[vertice] = true;
    for(auto vizinho : adj[vertice]){
        if(!visited[vizinho]){
            dfs(vizinho, adj, visited);
        }
    }
}

int main(){
    int v, e; cin >> v >> e;
    bool visited[v]; memset(visited, false, sizeof(visited));
    vector<int> adj[v];
    int componentes = 0;

    for(int i = 0 ; i < e ; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0 ; i < v ; i++){
        if(visited[i] == 0){
            dfs(i, adj, visited);
            componentes++;
        }
    }

    std::cout << "Número de Componentes Conexas: " << componentes << std::endl;
}