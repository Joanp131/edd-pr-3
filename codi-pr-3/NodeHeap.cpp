
#include "NodeHeap.h"

template<class Clau, class Valor>
NodeHeap<Clau, Valor>::NodeHeap()
{

}

template<class Clau, class Valor>
NodeHeap<Clau, Valor>::NodeHeap(const Clau &clau, const Valor &valor) : key(clau), value(valor)
{

}

template<class Clau, class Valor>
NodeHeap<Clau, Valor>::NodeHeap(const NodeHeap<Clau, Valor> &orig)
{
    key = orig.key;
    value = orig.value;
}

template<class Clau, class Valor>
NodeHeap<Clau, Valor>::~NodeHeap()
{

}

template<class Clau, class Valor>
Clau NodeHeap<Clau, Valor>::getKey() const
{
    return key;
}

template<class Clau, class Valor>
Valor NodeHeap<Clau, Valor>::getValue() const
{
    return value;
}

template<class Clau, class Valor>
bool NodeHeap<Clau, Valor>::operator==(const NodeHeap<Clau, Valor> &node) const
{
    return node.getKey() == this->key;
}

template
class NodeHeap<int, int>;

template
class NodeHeap<int, Movie>;