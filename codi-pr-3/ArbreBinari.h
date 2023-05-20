//
// Created by Joanp on 24/4/2023.
//

#ifndef EDD_PR_3_ARBREBINARI_H
#define EDD_PR_3_ARBREBINARI_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "NodeBinari.h"

using namespace std;


template<class Clau, class Valor>
class ArbreBinari
{
public:
    // O(1)
    ArbreBinari();

    // O(n)
    ArbreBinari(const ArbreBinari<Clau, Valor> &orig);

    // O(n)
    virtual ~ArbreBinari();

    // O(1)
    bool isEmpty() const;

    // O(n)
    int height() const;

    // O(n)
    NodeBinari<Clau, Valor> *insert(const Clau &clau, const Valor &value);

    // O(n)
    const Valor &valueOf(const Clau &clau) const;

    // O(n)
    void imprimirPreordre(const NodeBinari<Clau, Valor> *n = nullptr) const;

    // O(n)
    void imprimirInordre(const NodeBinari<Clau, Valor> *n = nullptr) const;

    // O(n)
    void imprimirPostordre(const NodeBinari<Clau, Valor> *n = nullptr) const;

    // O(n)
    vector<NodeBinari<Clau, Valor> *> obteValorsRang(int k1, int k2) const;

    // O(n)
    void imprimirCami(Clau key) const;

    // O(n)
    void eliminaMinim();

protected:
    NodeBinari<Clau, Valor> *root;

    // O(n)
    NodeBinari<Clau, Valor> *search(const Clau &k) const;

private:
    int _size;

    /* Mètodes auxiliars definiu aquí els que necessiteu */

    // O(n)
    void delelte_rec(NodeBinari<Clau, Valor> *node);

    // O(n)
    void insert_rec(NodeBinari<Clau, Valor> *pos, NodeBinari<Clau, Valor> *nou_node);

    // O(n)
    void preordre_rec(NodeBinari<Clau, Valor> *node) const;

    // O(n)
    void inordre_rec(NodeBinari<Clau, Valor> *node, int *print_count) const;

    // O(n)
    void postordre_rec(NodeBinari<Clau, Valor> *node) const;

    // O(n)
    void
    obteValorsRang_rec(NodeBinari<Clau, Valor> *node, vector<NodeBinari<Clau, Valor> *> &vec, int k1, int k2) const;

    // O(n)
    void imprimirCami_rec(NodeBinari<Clau, Valor> *node, Clau key) const;
};

#endif //EDD_PR_3_ARBREBINARI_H
