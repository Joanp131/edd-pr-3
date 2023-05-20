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
    // O(1)
    MinHeap(); // constructor

    // O(n)
    MinHeap<Clau, Valor>(const MinHeap<Clau, Valor> &); // constructor còpia

    // O(1)
    int tamany(); // retorna el nombre d'elements que hi ha al heap

    // O(1)
    bool esBuit(); // retorna cert si és buit, fals en cas contrari

    // O(log n)
    void inserir(const Clau &clau, const Valor &valor);

    // O(1)
    Clau minim(); // retorna la key mínima

    // O(1)
    Valor valorMinim(); // retorna el value de la key mínima

    // O(log n)
    void eliminaMinim(); // elimina el node amb value minim

    // O(n)
    void imprimir(); // Imprimeix per pantalla tot el Heap, una línia per a cada nivell de l'arbre

    // O(n)
    Valor cerca(const Clau &clau); // cerca al heap una key donada

    // O(1)
    int altura() const; // retorna l'alçada del heap

private:
    vector<NodeHeap<Clau, Valor>> data;
    int mida;

    // aquí sota definiu les funcions auxiliars
    // O(1)
    int getParent(int child);

    // O(log n)
    void upheap();

    // O(log n)
    void downheap();

    // O(1)
    int getSmallestChildIndex(int node);
};


#endif //EDD_PR_3_MINHEAP_H
