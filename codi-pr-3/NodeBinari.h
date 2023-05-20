//
// Created by Joanp on 24/4/2023.
//

#ifndef EDD_PR_3_NODEBINARI_H
#define EDD_PR_3_NODEBINARI_H

#include "iostream"
#include "Movie.h"
using namespace std;

template <class Clau, class Valor >
class NodeBinari {
public:
    NodeBinari(const Clau &key, const Valor &v, bool is_root);
    NodeBinari(const NodeBinari<Clau,Valor >& orig);
    virtual ~NodeBinari();

    /* Modificadors */
    // declareu aquí els modificadors (setters) dels atributs que necessiteu
    void setKey(Clau key);
    void setValue(Valor value);
    void setLeft(NodeBinari<Clau, Valor>* left);
    void setRight(NodeBinari<Clau, Valor>* right);

    /* Consultors */
    const Clau& getKey() const;
    const Valor& getValue() const;

    NodeBinari<Clau, Valor> *getLeft();
    NodeBinari<Clau, Valor> *getRight();
    // declareu aquí els consultors (getters) dels atributs que necessiteu

    /* Operacions */
    bool isRoot() const;
    bool hasLeft() const;
    bool hasRight() const;
    bool isExternal() const;
    void insertValue(const Valor & v);
    int height() const;
    bool operator==(const NodeBinari<Clau,Valor >& node) const;


private:
    Clau key;
    Valor value;
    // afegiu aquí els atributs que falten

    NodeBinari<Clau, Valor>* left;
    NodeBinari<Clau, Valor>* right;

    bool is_root;
};


#endif //EDD_PR_3_NODEBINARI_H
