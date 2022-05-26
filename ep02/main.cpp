#include<iostream>
#include "HT.h"
#include "VO.h"
#include "ABB.h"
#include "TR.h"
#include "ARN.h"
#include "A23.h"

using namespace std;

int main(){

    HT<std::string, int> *ht;

    string type; cin >> type; // tipo de estrutura a ser utilizada

    if(type == "VO") ht = new VO<string, int>();
    else if(type == "ABB") ht = new ABB<string, int>();
    else if(type == "TR") ht = new TR<string, int>();
    else if(type == "ARN") ht = new ARN<string, int>();
    else ht = new A23<string, int>();

    int numberWords; cin >> numberWords; // número de palavras
    string *words = new string[numberWords];

    // leitura das palavras
    for(int i = 0 ; i < numberWords ; i++)
        cin >> words[i];

    int currentWord = 0; // palavra atual
    int numberOperations; cin >> numberOperations;
    for(int i = 0 ; i < numberOperations ; i++){
        int operation; string parameter;
        switch(operation){
            case 1:
                parameter = stoi(parameter);
                for(int i = 0 ; i < parameter ; i++){
                    ht->add(words[currentWord], 1);
                    currentWord++;
                }
                break;
            case 2:
                cout << ht->value(parameter);
                break;
            case 3:
                cout << ht->rank(parameter);
                break;
            case 4:
                cout << ht->select(parameter);
                break;
        }
    }
}