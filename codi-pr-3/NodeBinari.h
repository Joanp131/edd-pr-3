//
// Created by Joanp on 24/4/2023.
//

#ifndef EDD_PR_3_NODEBINARI_H
#define EDD_PR_3_NODEBINARI_H

#include "iostream"
#include "Movie.h"

using namespace std;

template<class Clau, class Valor>
class NodeBinari
{
public:
    // O(1)
    NodeBinari(const Clau &key, const Valor &v, bool is_root);

    // O(n)
    NodeBinari(const NodeBinari<Clau, Valor> &orig);

    // O(1)
    virtual ~NodeBinari();

    /* Modificadors */

    // O(1)
    void setLeft(NodeBinari<Clau, Valor> *left);

    // O(1)
    void setRight(NodeBinari<Clau, Valor> *right);

    /* Consultors */
    // O(1)
    const Clau &getKey() const;

    // O(1)
    const Valor &getValue() const;

    // O(1)
    NodeBinari<Clau, Valor> *getLeft();

    // O(1)
    NodeBinari<Clau, Valor> *getRight();
    // declareu aquí els consultors (getters) dels atributs que necessiteu

    /* Operacions */
    // O(1)
    bool isRoot() const;

    // O(1)
    bool hasLeft() const;

    // O(1)
    bool hasRight() const;

    // O(1)
    bool isExternal() const;

    // O(1)
    void insertValue(const Valor &v);

    // O(n)
    int height() const;

    // O(n)
    bool operator==(const NodeBinari<Clau, Valor> &node) const;


private:
    Clau key;
    Valor value;
    // afegiu aquí els atributs que falten

    NodeBinari<Clau, Valor> *left;
    NodeBinari<Clau, Valor> *right;

    bool is_root;
};


#endif //EDD_PR_3_NODEBINARI_H
