//
// Creat per Joan Pau Condal Marco el dia 16/5/2023.
//

#include "MinHeap.h"

/**
 * Constructor per defecte, crea un min heap buit
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap() {
    mida = 0;
    data = vector < NodeHeap < Clau, Valor >> ();
}

/**
 * Constructor còpia
 * @tparam Clau
 * @tparam Valor
 * @param orig - MinHeap del qual fer la còpia
 */
template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap(const MinHeap<Clau, Valor> &orig) : MinHeap() {

}

/**
 * Retorna el nombre de nodes del heap
 * @tparam Clau
 * @tparam Valor
 * @return
 */
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::tamany() {
    return mida;
}

/**
 * Comprova si el Heap és buit
 * @tparam Clau
 * @tparam Valor
 * @return
 */
template<class Clau, class Valor>
bool MinHeap<Clau, Valor>::esBuit() {
    return mida == 0;
}

/**
 * Insereix un nou element al Heap, conservant l'ordre
 * @tparam Clau
 * @tparam Valor
 * @param clau
 * @param valor
 */
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::inserir(const Clau &clau, const Valor &valor) {

    // Inserim un nou node al final del vector
    NodeHeap <Clau, Valor> nou_node = NodeHeap<Clau, Valor>(clau, valor);
    data.push_back(nou_node);

    // Cridem la funció upheap per reordenar el heap
    upheap();
    mida++;
}

/**
 * Retorna la clau del menor node del Heap
 * @tparam Clau
 * @tparam Valor
 * @return Valor
 */
template<class Clau, class Valor>
Clau MinHeap<Clau, Valor>::minim() {
    return data[0].getKey();
}

/**
 * Retorna el valor del menor node del Heap
 * @tparam Clau
 * @tparam Valor
 * @return Valor
 */
template<class Clau, class Valor>
Valor MinHeap<Clau, Valor>::valorMinim() {
    return data[0].getValue();
}

/**
 * Elimina el node mínim del heap i restableix l'ordre si és necessari
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::eliminaMinim() {
    if (mida == 0) {
        throw out_of_range("void MinHeap<Clau, Valor>::eliminaMinim(): El vector data no conté cap element");
    }

    // Intercanviem el primer element amb l'últim
    NodeHeap <Clau, Valor> ultim, minim;

    // Guardem l'element mínim
    minim = data[0];

    // Passem l'últim element al principi i reduïm la mida del vector
    data[0] = data[mida - 1];
    data.pop_back();
    mida--;

    // Restablim l'ordre del heap
    downheap();
}

/**
 * Imprimeix la clau de tots els nodes del heap, una línia per nivell
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::imprimir() {
    int line_break = 2;
    cout << endl;
    for (int i = 0; i < mida; i++) {
        cout << "key: " << data[i].getKey() << "\t";
        if (i + 2 == line_break) {
            cout << endl;
            line_break *= 2;
        }
    }
    cout << endl;
}

/**
 * Cerca un node en el Heap amb una clau donada
 * @tparam Clau
 * @tparam Valor
 * @param clau
 * @return
 */
template<class Clau, class Valor>
Valor MinHeap<Clau, Valor>::cerca(const Clau &clau) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i].getKey() == clau) {
            return data[i].getValue();
        }
    }

    throw out_of_range(
            "Valor MinHeap<Clau, Valor>::cerca(const Clau &clau): No s'ha trobat el node amb la clau donada");
}

/**
 * Retorna l'altura del heap
 * @tparam Clau
 * @tparam Valor
 * @return
 */
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::altura() const {
    if (mida == 0) {
        return 0;
    }

    return (int) log2(mida) + 1;
}

/**
 * Funció auxiliar.
 * Donat un node, retorna l'índex del seu pare en el vector de dades
 * @tparam Clau
 * @tparam Valor
 * @param child
 * @return
 */
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::getParent(int child) {

    if (child <= 0) {
        throw invalid_argument("int MinHeap<Clau, Valor>::getParent(int child): El node 0 no té node pare");
    }

    // Fill en un node amb key parell
    if (!(child % 2)) {
        return (child - 2) / 2;
    }

    // Fill en un node amb key senar
    return (child - 1) / 2;
}

/**
 * Funció auxiliar per inserir nodes en el Heap.
 * Un cop inserit el nou node, restableix l'ordre del heap si és necessari
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::upheap() {

    int child = data.size() - 1;

    // Si el heap només té un node, no cal fer cap reordenació
    if (child == 0) {
        return;
    }

    // Si l'index del fill és més petit que el del pare, els intercanviem
    int parent = getParent(child);
    while (child > 0 && data[child].getKey() < data[parent].getKey()) {
        NodeHeap <Clau, Valor> aux = data[parent];
        data[parent] = data[child];
        data[child] = aux;

        // Actualitzem els índex del nou node i del seu pare
        child = parent;
        if (child != 0) {
            parent = getParent(child);
        }
    }

}

/**
 * Funció auxiliat per eliminar nodes del Heap.
 * Restableix l'ordre del heap si és necessari
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::downheap() {
    int node = 0, child = getSmallestChildIndex(node);

    // Mentre el node tingui algun fill de clau més petita, els intercanviem
    while (child != -1 && data[node].getKey() > data[child].getKey()) {
        NodeHeap <Clau, Valor> aux = data[node];

        data[node] = data[child];
        data[child] = aux;

        // Actualitzem els índexs
        node = child;
        child = getSmallestChildIndex(node);
    }
}

/**
 * Funció auxiliar.
 * Donat un node, retorna l'índex del node fill que té menor clau. Si el node donat no té
 * cap fill, retorna -1
 * @tparam Clau
 * @tparam Valor
 * @param node - Índex del node
 * @return int
 */
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::getSmallestChildIndex(int node) {

    int child_l, child_r;

    child_l = 2 * node + 1;
    child_r = 2 * node + 2;

    // Si té dos fills, retornem l'índex del node que té clau més petita
    if (child_l < mida && child_r < mida) {
        return data[child_r].getKey() < data[child_l].getKey() ? child_r : child_l;
    }
        // Si només té un fill, retornem aquest
    else if (child_l < mida) {
        return child_l;
    } else if (child_r < mida) {
        return child_r;
    }

    // Si el node no té cap fill, retornem -1
    return -1;
}

template
class MinHeap<int, int>;

template
class MinHeap<int, Movie>;
