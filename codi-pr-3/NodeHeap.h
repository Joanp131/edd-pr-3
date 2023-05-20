#ifndef NODE_HEAP_H
#define NODE_HEAP_H

#include "Movie.h"

template<class Clau, class Valor>
class NodeHeap
{
public:
    NodeHeap();

    NodeHeap(const Clau &clau, const Valor &valor);

    NodeHeap(const NodeHeap<Clau, Valor> &orig);

    virtual ~NodeHeap();

    Clau getKey() const;

    Valor getValue() const;

    bool operator==(const NodeHeap<Clau, Valor> &node) const;

private:
    Clau key;
    Valor value;
};

#endif