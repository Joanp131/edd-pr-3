//
// Created by Joanp on 24/4/2023.
//

#include "NodeBinari.h"

template<class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const Clau &key, const Valor &v, bool is_root) : key(key), value(v), is_root(is_root)
{
    left = nullptr;
    right = nullptr;
}

/**
 * Constructor còpia
 * @tparam Clau
 * @tparam Valor
 * @param orig
 */
template<class Clau, class Valor>
NodeBinari<Clau, Valor>::NodeBinari(const NodeBinari<Clau, Valor> &orig) : NodeBinari(orig.key, orig.value, orig.is_root)
{
    if(orig.hasLeft()) {
        this->left = new NodeBinari<Clau, Valor>(*orig.left);
    }

    if(orig.hasRight()) {
        this->right = new NodeBinari<Clau, Valor>(*orig.right);
    }
}

template<class Clau, class Valor>
NodeBinari<Clau, Valor>::~NodeBinari()
{
//    delete this->key;
//    delete this->value;

//    cout << "\tEliminat NodeBinari " << getKey() << endl;
}

template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setKey(Clau key)
{
    this->key = key;
}

template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setValue(Valor value)
{
    this->value = value;
}

template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setLeft(NodeBinari<Clau, Valor> *left)
{
    this->left = left;
}

template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setRight(NodeBinari<Clau, Valor> *right)
{
    this->right = right;
}

template<class Clau, class Valor>
const Clau &NodeBinari<Clau, Valor>::getKey() const
{
    return this->key;
}

template<class Clau, class Valor>
const Valor &NodeBinari<Clau, Valor>::getValue() const
{
    return this->value;
}

template<class Clau, class Valor>
NodeBinari<Clau, Valor> *NodeBinari<Clau, Valor>::getLeft()
{
    return this->left;
}

template<class Clau, class Valor>
NodeBinari<Clau, Valor> *NodeBinari<Clau, Valor>::getRight()
{
    return this->right;
}

template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isRoot() const
{
    return false;
}

template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasLeft() const
{
    return left != nullptr;
}

template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::hasRight() const
{
    return right != nullptr;
}

template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isExternal() const
{
    return left == nullptr && right == nullptr;
}

template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::insertValue(const Valor &v)
{
    value = v;
}

template<class Clau, class Valor>
int NodeBinari<Clau, Valor>::height() const
{
    if (this->isExternal()) {
        return 1;
    }

    int left_height = 0, right_height = 0;

    if (this->hasLeft()) {
        left_height = this->left->height() + 1;
    }

    if (this->hasRight()) {
        right_height = this->right->height() + 1;
    }

    return left_height > right_height ? left_height : right_height;
}

template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::operator==(const NodeBinari<Clau, Valor> &node) const
{
    return key == node.getKey();
}

template class NodeBinari<int, int>;
template class NodeBinari<int, Movie>;