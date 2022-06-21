#include <iostream>
#include <string.h>
#include "grafos.h"

int main(){

    int v, e; cin >> v >> e;
    std::vector<int> *adj = construir_grafo_inteiros(v, e);

    int num_componentes_conexas = calcular_componentes(&adj);
    std::cout << "Número de Componentes Conexas: " << componentes << std::endl;
    
    calcular_distancias(&adj);

}