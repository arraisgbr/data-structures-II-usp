#include <iostream>
#include <string.h>
#include "grafos.h"

int main(){

    int v, e; std::cin >> v >> e;
    std::vector<int> *adj = construir_grafo_inteiros(v, e);

    identificar_componentes(adj, v);
    
    // calcular_distancias(adj, v);
}