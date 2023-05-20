#ifndef NODE_HEAP_H
#define NODE_HEAP_H

#include "Movie.h"

template<class Clau, class Valor>
class NodeHeap
{
public:
    // O(1)
    NodeHeap();

    // O(1)
    NodeHeap(const Clau &clau, const Valor &valor);

    // O(1)
    NodeHeap(const NodeHeap<Clau, Valor> &orig);

    // O(1)
    virtual ~NodeHeap();

    // O(1)
    Clau getKey() const;

    // O(1)
    Valor getValue() const;

    // O(1)
    bool operator==(const NodeHeap<Clau, Valor> &node) const;

private:
    Clau key;
    Valor value;
};

#endif