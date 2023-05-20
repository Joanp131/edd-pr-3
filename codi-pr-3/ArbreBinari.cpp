//
// Created by Joanp on 24/4/2023.
//

#include "ArbreBinari.h"

/**
 * Crea un Arbre Binari de Cerca buit
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari() {
    root = nullptr;
    _size = 0;
}

/**
 * Crea un Arbre Binari de Cerca fent una còpia
 * @tparam Clau
 * @tparam Valor
 * @param orig - ABS del qual fer la còpia
 */
template<class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(const ArbreBinari<Clau, Valor> &orig) : ArbreBinari() {
    if (!orig.isEmpty()) {
        this->root = new NodeBinari<Clau, Valor>(*orig.root);
    }
    _size = orig._size;

    cout << "\nArbre binari copiat" << endl;
}

/**
 * Destrueix la classe ArbreBinari i tots els seus nodes, començant pel root
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
ArbreBinari<Clau, Valor>::~ArbreBinari() {

    cout << "\nDestruint arbre binari" << endl;

    if (!isEmpty()) {
        delelte_rec(root);
    }

    cout << "Arbre binari destruit" << endl;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::delelte_rec(NodeBinari<Clau, Valor> *node) {

    if (node == nullptr) {
        return;
    }

    NodeBinari<Clau, Valor> *right = nullptr, *left = nullptr;

    if (node->hasLeft()) {
        left = node->getLeft();
    }

    if (node->hasRight()) {
        right = node->getRight();
    }

    delete node;

    delelte_rec(left);
    delelte_rec(right);
}

/**
 * Retorna cert si l'arbre no conté cap node
 * @tparam Clau
 * @tparam Valor
 * @return
 */
template<class Clau, class Valor>
bool ArbreBinari<Clau, Valor>::isEmpty() const {
    return root == nullptr;
}

/**
 *
 * @tparam Clau
 * @tparam Valor
 * @return
 */
template<class Clau, class Valor>
int ArbreBinari<Clau, Valor>::height() const {
    if (!isEmpty()) {
        return root->height();
    }

    return 0;
}

/**
 * Insereix un nou element a l'arbre, sempre que l'element no sigui repetit
 * @tparam Clau
 * @tparam Valor
 * @param clau - Clau del nou element
 * @param value - Valor del nou element
 * @return
 */
template<class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::insert(const Clau &clau, const Valor &value) {

    // Si l'arbre és buit, el node que volem afegir serà el root
    if (isEmpty()) {
        NodeBinari<Clau, Valor> *new_root = new NodeBinari<Clau, Valor>(clau, value, true);
        root = new_root;
        _size++;
    }

        // Si l'arbre no està buit, afegim el node de manera recursiva
    else {
        NodeBinari<Clau, Valor> *nou_node = new NodeBinari<Clau, Valor>(clau, value, false);
        insert_rec(root, nou_node);
    }
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::insert_rec(NodeBinari<Clau, Valor> *pos, NodeBinari<Clau, Valor> *nou_node) {

    // Comprovem que no existeixi ja el node a l'arbre
    if (pos == nou_node) {
        delete nou_node;
        return;
    }

    if (nou_node->getKey() < pos->getKey()) {
        if (!pos->hasLeft()) {
            pos->setLeft(nou_node);
            _size++;
        } else {
            insert_rec(pos->getLeft(), nou_node);
        }
    } else {
        if (!pos->hasRight()) {
            pos->setRight(nou_node);
            _size++;
        } else {
            insert_rec(pos->getRight(), nou_node);
        }
    }
}

/**
 *
 * @tparam Clau
 * @tparam Valor
 * @param clau
 * @return
 */
template<class Clau, class Valor>
const Valor &ArbreBinari<Clau, Valor>::valueOf(const Clau &clau) const {
    NodeBinari<Clau, Valor> *resultat = search(clau);

    if (resultat == nullptr) {
        throw out_of_range(
                "const Valor &ArbreBinari<Clau, Valor>::valueOf(const Clau &clau) const: No s'ha trobat el node indicat");
    }

    return resultat->getValue();
}

/**
 *
 * @tparam Clau
 * @tparam Valor
 * @param n
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPreordre(const NodeBinari<Clau, Valor> *n) const {

    if (n == nullptr) {
        n = root;
    }

    cout << "\nPreOrdre = {";
    preordre_rec((NodeBinari<Clau, Valor> *) n);
    cout << "\b\b}" << endl;

}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::preordre_rec(NodeBinari<Clau, Valor> *node) const {
    cout << node->getKey() << ", ";

    if (node->hasLeft()) {
        preordre_rec(node->getLeft());
    }
    if (node->hasRight()) {
        preordre_rec(node->getRight());
    }
}

/**
 *
 * @tparam Clau
 * @tparam Valor
 * @param n
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirInordre(const NodeBinari<Clau, Valor> *n) const {

    if (n == nullptr) {
        n = root;
    }

    cout << "\nInOrdre = {";

    int count = 0, *print_count = &count;
    inordre_rec((NodeBinari<Clau, Valor> *) n, 0);
    cout << "\b\b}" << endl;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::inordre_rec(NodeBinari<Clau, Valor> *node, int *print_count) const {

    if (node->hasLeft()) {
        inordre_rec(node->getLeft(), print_count);
    }

    if (*print_count > 0 && *print_count % 40 == 0) {
        int cont;
        cout << "Continuar imprimint? (0/1): ";
        cin >> cont;
        if (!cont) {
            return;
        }
    }
    cout << node->getKey() << ", ";
    (*print_count)++;

    if (node->hasRight()) {
        inordre_rec(node->getRight(), print_count);
    }
}

/**
 *
 * @tparam Clau
 * @tparam Valor
 * @param n
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPostordre(const NodeBinari<Clau, Valor> *n) const {

    if (n == nullptr) {
        n = root;
    }

    cout << "\nPostOrdre = {";
    postordre_rec((NodeBinari<Clau, Valor> *) n);
    cout << "\b\b}" << endl;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::postordre_rec(NodeBinari<Clau, Valor> *node) const {

    if (node->hasLeft()) {
        postordre_rec(node->getLeft());
    }

    if (node->hasRight()) {
        postordre_rec(node->getRight());
    }

    cout << node->getKey() << ", ";
}

template<class Clau, class Valor>
vector<NodeBinari<Clau, Valor> *> ArbreBinari<Clau, Valor>::obteValorsRang(int k1, int k2) const {

    vector<NodeBinari<Clau, Valor> *> vect{};

    if (!isEmpty()) {
        obteValorsRang_rec(root, vect, k1, k2);
    }

    return vect;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::obteValorsRang_rec(NodeBinari<Clau, Valor> *node, vector<NodeBinari<Clau, Valor> *> &vec,
                                                  int k1, int k2) const {


    if (node->hasLeft()) {
        obteValorsRang_rec(node->getLeft(), vec, k1, k2);
    }

    if (node->getKey() >= k1 && node->getKey() <= k2) {
        vec.push_back(node);
    }

    if (node->hasRight()) {
        obteValorsRang_rec(node->getRight(), vec, k1, k2);
    }
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami(Clau key) const {

    cout << "\nImprimirCami = {";
    if (!isEmpty()) {
        imprimirCami_rec(root, key);
    }
    cout << "\b\b}" << endl;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami_rec(NodeBinari<Clau, Valor> *node, Clau key) const {
    cout << node->getKey() << ", ";

    // Si el node és una fulla, hem acabat la cerca
    if (node->isExternal()) {
        return;
    }

    if (key < node->getKey() && node->hasLeft()) {
        imprimirCami_rec(node->getLeft(), key);
    } else if (key > node->getKey() && node->hasRight()) {
        imprimirCami_rec(node->getRight(), key);
    }
}


template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminaMinim() {
    // El mínim mai tindrà dos fills, sinó el de l'esquerra seria més petit.
    // Per tant, només ens cal assignar el node fill a l'esquerra del pare del que eliminem

    NodeBinari<Clau, Valor> *pare = nullptr, *eliminar = nullptr;

    if (isEmpty()) {
        throw length_error(
                "void ArbreBinari<Clau, Valor>::eliminaMinim(): No es poden eliminar nodes ja que l'arbre és buit");
    }

    // root és l'element més petit
    if (!root->hasLeft()) {
        eliminar = root;
        root = root->getRight();
    } else {

        // Si el root no és l'element més petit, busquem recorrent tots els nodes cap a l'esquerra
        eliminar = root;
        while (eliminar->getLeft() != nullptr) {
            pare = eliminar;
            eliminar = eliminar->getLeft();
        }

        // Si el node que volem eliminar té nodes a la dreta, 
        // els posem a l'esquerra del seu pare
        if (eliminar->hasRight()) {
            pare->setLeft(eliminar->getRight());
        } else {
            pare->setLeft(nullptr);
        }
    }

    _size--;

    cout << "\nNode " << eliminar->getKey() << " eliminat" << endl;
    delete eliminar;
}

template<class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::search(const Clau &k) const {
    // Si l'arbre és buit retornem nullptr
    if (isEmpty()) {
        return nullptr;
    }

    NodeBinari<Clau, Valor> *current = root;
    while (current != nullptr) {

        int current_key = current->getKey();

        if (current_key == k) {
            return current;
        }

        if (k <= current_key) {
            current = current->getLeft();
        }

        if (k > current_key) {
            current = current->getRight();
        }
    }

    // No hem trobat el node amb la clau indicada
    return nullptr;
}

template
class ArbreBinari<int, int>;

template
class ArbreBinari<int, Movie>;