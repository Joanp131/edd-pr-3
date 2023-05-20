//
// Creat per Joan Pau Condal Marco el dia 16/5/2023.
//

#ifndef EDD_PR_3_MINHEAP_H
#define EDD_PR_3_MINHEAP_H

#include <vector>
#include <exception>
#include <cmath>
#include <algorithm>
#include "NodeHeap.h"

using namespace std;

template<class Clau, class Valor>
class MinHeap
{
public:
    MinHeap(); // constructor
    MinHeap<Clau, Valor>(const MinHeap<Clau, Valor> &); // constructor còpia
    int tamany(); // retorna el nombre d'elements que hi ha al heap
    bool esBuit(); // retorna cert si és buit, fals en cas contrari
    void inserir(const Clau &clau, const Valor &valor);

    Clau minim(); // retorna la key mínima
    Valor valorMinim(); // retorna el value de la key mínima
    void eliminaMinim(); // elimina el node amb value minim
    void imprimir(); // Imprimeix per pantalla tot el Heap, una línia per a cada nivell de l'arbre
    Valor cerca(const Clau &clau); // cerca al heap una key donada
    int altura() const; // retorna l'alçada del heap

private:
    vector<NodeHeap<Clau, Valor>> data;
    int mida;

    // aquí sota definiu les funcions auxiliars
    int getParent(int child);

    void upheap();

    void downheap();

    int getSmallestChildIndex(int node);


};


#endif //EDD_PR_3_MINHEAP_H
