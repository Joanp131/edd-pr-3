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


template <class Clau, class Valor>
class ArbreBinari {
public:
    ArbreBinari();
    ArbreBinari(const ArbreBinari<Clau, Valor>& orig);
    virtual ~ArbreBinari();

    bool isEmpty() const;
    int height() const;

    NodeBinari<Clau,Valor>* insert(const Clau& clau, const Valor& value);
    const Valor& valueOf(const Clau& clau) const;
    void imprimirPreordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
    void imprimirInordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
    void imprimirPostordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
    vector< NodeBinari<Clau,Valor>* > obteValorsRang(int k1, int k2) const;
    void imprimirCami(Clau key) const;
    void eliminaMinim();
protected:
    NodeBinari<Clau,Valor>* root;
    NodeBinari<Clau,Valor>* search(const Clau& k) const;
private:
    int _size;

    /* Mètodes auxiliars definiu aquí els que necessiteu */
    void delelte_rec(NodeBinari<Clau, Valor>* node);

    void insert_rec(NodeBinari<Clau, Valor>* pos, NodeBinari<Clau, Valor>* nou_node);

    void valueOf_rec(NodeBinari<Clau, Valor>* node, const Clau &clau);

    void preordre_rec(NodeBinari<Clau, Valor>* node) const;
    void inordre_rec(NodeBinari<Clau, Valor>* node, int *print_count) const;
    void postordre_rec(NodeBinari<Clau, Valor>* node) const;

    void obteValorsRang_rec(NodeBinari<Clau, Valor>* node, vector<NodeBinari<Clau, Valor>*>& vec, int k1, int k2) const;

    void imprimirCami_rec(NodeBinari<Clau, Valor> *node, Clau key) const;
};

#endif //EDD_PR_3_ARBREBINARI_H
