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
ArbreBinari<Clau, Valor>::ArbreBinari()
{
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
ArbreBinari<Clau, Valor>::ArbreBinari(const ArbreBinari<Clau, Valor> &orig) : ArbreBinari()
{
    if (!orig.isEmpty())
    {
        // Fem la còpia recursiva de tots els nodes
        this->root = new NodeBinari<Clau, Valor>(*orig.root);
    }
    else
    {
        root = nullptr;
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
ArbreBinari<Clau, Valor>::~ArbreBinari()
{

    cout << "\nDestruint arbre binari" << endl;

    if (!isEmpty())
    {
        delelte_rec(root);
    }

    cout << "Arbre binari destruit" << endl;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::delelte_rec(NodeBinari<Clau, Valor> *node)
{

    if (node == nullptr)
    {
        return;
    }

    NodeBinari<Clau, Valor> *right = nullptr, *left = nullptr;

    if (node->hasLeft())
    {
        left = node->getLeft();
    }

    if (node->hasRight())
    {
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
bool ArbreBinari<Clau, Valor>::isEmpty() const
{
    return root == nullptr;
}

/**
 * Retorna l'alçada de l'arbre, la distància del root a la fulla més llunyana
 * @tparam Clau
 * @tparam Valor
 * @return
 */
template<class Clau, class Valor>
int ArbreBinari<Clau, Valor>::height() const
{
    if (!isEmpty())
    {
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
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::insert(const Clau &clau, const Valor &value)
{

    // Si l'arbre és buit, el node que volem afegir serà el root
    if (isEmpty())
    {
        NodeBinari<Clau, Valor> *new_root = new NodeBinari<Clau, Valor>(clau, value, true);
        root = new_root;
        _size++;
    }

        // Si l'arbre no està buit, afegim el node de manera recursiva
    else
    {
        NodeBinari<Clau, Valor> *nou_node = new NodeBinari<Clau, Valor>(clau, value, false);
        insert_rec(root, nou_node);
    }
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::insert_rec(NodeBinari<Clau, Valor> *pos, NodeBinari<Clau, Valor> *nou_node)
{

    // Comprovem que no existeixi ja el node a l'arbre
    if (pos == nou_node)
    {
        delete nou_node;
        return;
    }

    // Inserim el node cap a l'esquerra
    if (nou_node->getKey() < pos->getKey())
    {
        if (!pos->hasLeft())
        {
            pos->setLeft(nou_node);
            _size++;
        }
        else
        {
            insert_rec(pos->getLeft(), nou_node);
        }
    }
        // Inserim el node cap a la dreta
    else
    {
        if (!pos->hasRight())
        {
            pos->setRight(nou_node);
            _size++;
        }
        else
        {
            insert_rec(pos->getRight(), nou_node);
        }
    }
}

/**
 * Busca un node amb una clasu donada en tot l'arbre.
 * Si el node no està, retorna un error
 * @tparam Clau
 * @tparam Valor
 * @param clau
 * @return
 */
template<class Clau, class Valor>
const Valor &ArbreBinari<Clau, Valor>::valueOf(const Clau &clau) const
{
    NodeBinari<Clau, Valor> *resultat = search(clau);

    if (resultat == nullptr)
    {
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
void ArbreBinari<Clau, Valor>::imprimirPreordre(const NodeBinari<Clau, Valor> *n) const
{

    if (_size == 0)
    {
        cout << "Preordre = {}" << endl;
        return;
    }

    if (n == nullptr)
    {
        n = root;
    }

    cout << "\nPreOrdre = {";
    preordre_rec((NodeBinari<Clau, Valor> *) n);
    cout << "\b\b}" << endl;

}

/**
 * Funció auxiliar per imprimir el preordre
 * @tparam Clau
 * @tparam Valor
 * @param node
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::preordre_rec(NodeBinari<Clau, Valor> *node) const
{
    cout << node->getKey() << ", ";

    if (node->hasLeft())
    {
        preordre_rec(node->getLeft());
    }
    if (node->hasRight())
    {
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
void ArbreBinari<Clau, Valor>::imprimirInordre(const NodeBinari<Clau, Valor> *n) const
{
    if (_size == 0)
    {
        cout << "Inordre = {}" << endl;
        return;
    }

    if (n == nullptr)
    {
        n = root;
    }

    cout << "\nInOrdre = {";

    int count = 0, *print_count = &count;
    inordre_rec((NodeBinari<Clau, Valor> *) n, print_count);
    cout << "\n}" << endl;
}

/**
 * Funció auxiliar per imprimir l'inordre. Cada 40 nodes impresos
 * pregunta a l'usuari si cal seguir imprimint
 * @tparam Clau
 * @tparam Valor
 * @param node
 * @param print_count
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::inordre_rec(NodeBinari<Clau, Valor> *node, int *print_count) const
{

    // Explorem el node de l'esquerra
    if (node->hasLeft())
    {
        inordre_rec(node->getLeft(), print_count);
        if (*print_count == -1) return;
    }

    // Imprimim la informació del node
    // Si portem 40 línies impreses, preguntem a l'usuari si vol seguir imprimint
    if (*print_count > 0 && *print_count % 40 == 0)
    {
        int cont;
        cout << "\n\tContinuar imprimint? (0/1): ";
        cin >> cont;
        if (!cont)
        {
            // No volem seguir imprimint
            *print_count = -1;
            return;
        }
    }
    cout << "\n\t" << node->getKey() << ",";
    (*print_count)++;

    // Explorem el node de la dreta
    if (node->hasRight())
    {
        inordre_rec(node->getRight(), print_count);
        if (*print_count == -1) return;
    }

}

/**
 *
 * @tparam Clau
 * @tparam Valor
 * @param n
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPostordre(const NodeBinari<Clau, Valor> *n) const
{

    if (_size == 0)
    {
        cout << "Postordre = {}" << endl;
        return;
    }

    if (n == nullptr)
    {
        n = root;
    }

    cout << "\nPostOrdre = {";
    postordre_rec((NodeBinari<Clau, Valor> *) n);
    cout << "\b\b}" << endl;
}

/**
 * Funció auxiliar per imprimir el postordre
 * @tparam Clau
 * @tparam Valor
 * @param node
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::postordre_rec(NodeBinari<Clau, Valor> *node) const
{

    if (node->hasLeft())
    {
        postordre_rec(node->getLeft());
    }

    if (node->hasRight())
    {
        postordre_rec(node->getRight());
    }

    cout << node->getKey() << ", ";
}

/**
 * Obté tots els nodes de l'arbre que la seva clau està entre k1 i k2,
 * ambdós inclosos. Retorna tots els nodes que compleixin la condició dins
 * un vector
 * @tparam Clau
 * @tparam Valor
 * @param k1 - Clau petita
 * @param k2 - Clau gran
 * @return
 */
template<class Clau, class Valor>
vector<NodeBinari<Clau, Valor> *> ArbreBinari<Clau, Valor>::obteValorsRang(int k1, int k2) const
{

    vector<NodeBinari<Clau, Valor> *> vect{};

    if (!isEmpty())
    {
        obteValorsRang_rec(root, vect, k1, k2);
    }

    return vect;
}

/**
 * Funció auxiliar per obtenir tots els nodes amb clau dins un rang
 * @tparam Clau
 * @tparam Valor
 * @param node - Node que explorem actualment
 * @param vec - Vector amb tots els nodes
 * @param k1 - Clau petita
 * @param k2 - Clau gran
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::obteValorsRang_rec(NodeBinari<Clau, Valor> *node, vector<NodeBinari<Clau, Valor> *> &vec,
                                                  int k1, int k2) const
{

    if (node->hasLeft())
    {
        obteValorsRang_rec(node->getLeft(), vec, k1, k2);
    }

    if (node->getKey() >= k1 && node->getKey() <= k2)
    {
        vec.push_back(node);
    }

    if (node->hasRight())
    {
        obteValorsRang_rec(node->getRight(), vec, k1, k2);
    }
}

/**
 * Donada una clau, imprimeix el camí des del root fins al
 * node amb la clau donada
 * @tparam Clau
 * @tparam Valor
 * @param key - Clau del node que volem trobar
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami(Clau key) const
{

    cout << "\nImprimirCami = {";
    if (!isEmpty())
    {
        imprimirCami_rec(root, key);
    }
    cout << "\b\b}" << endl;
}

/**
 * Funció auxiliar per imprimir el camí fins a un node
 * @tparam Clau
 * @tparam Valor
 * @param node - Node que estem explorant al moment
 * @param key - Clau que volem trobar
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami_rec(NodeBinari<Clau, Valor> *node, Clau key) const
{
    cout << node->getKey() << ", ";

    // Si el node és una fulla, hem acabat la cerca
    if (node->isExternal())
    {
        return;
    }

    if (key < node->getKey() && node->hasLeft())
    {
        imprimirCami_rec(node->getLeft(), key);
    }
    else if (key > node->getKey() && node->hasRight())
    {
        imprimirCami_rec(node->getRight(), key);
    }
}

/**
 * Elimina el node que té la clau més petita de l'arbre. Retorna un error si l'arbre és buit
 * @tparam Clau
 * @tparam Valor
 */
template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminaMinim()
{
    // El mínim mai tindrà dos fills, sinó el de l'esquerra seria més petit.
    // Per tant, només ens cal assignar el node fill a l'esquerra del pare del que eliminem

    NodeBinari<Clau, Valor> *pare = nullptr, *eliminar = nullptr;

    if (isEmpty())
    {
        throw length_error(
                "void ArbreBinari<Clau, Valor>::eliminaMinim(): No es poden eliminar nodes ja que l'arbre és buit");
    }

    // root és l'element més petit
    if (!root->hasLeft())
    {
        eliminar = root;
        root = root->getRight();
    }
    else
    {

        // Si el root no és l'element més petit, busquem recorrent tots els nodes cap a l'esquerra
        eliminar = root;
        while (eliminar->getLeft() != nullptr)
        {
            pare = eliminar;
            eliminar = eliminar->getLeft();
        }

        // Si el node que volem eliminar té nodes a la dreta, 
        // els posem a l'esquerra del seu pare
        if (eliminar->hasRight())
        {
            pare->setLeft(eliminar->getRight());
        }
        else
        {
            pare->setLeft(nullptr);
        }
    }

    _size--;

    cout << "Node " << eliminar->getKey() << " eliminat" << endl;
    delete eliminar;
}

/**
 * Cerca un node a l'arbre que tingui la clau donada. Cerca iterativament.
 * Retorna nullptr si no s'ha trobat el node
 * @tparam Clau
 * @tparam Valor
 * @param k - Clau del node que volem trobar
 * @return
 */
template<class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::search(const Clau &k) const
{
    // Si l'arbre és buit retornem nullptr
    if (isEmpty())
    {
        return nullptr;
    }

    NodeBinari<Clau, Valor> *current = root;
    while (current != nullptr)
    {

        int current_key = current->getKey();

        // Hem trobat el node
        if (current_key == k)
        {
            return current;
        }

        // Explorem a l'esquerra
        if (k <= current_key)
        {
            current = current->getLeft();
        }

        // Explorem a la dreta
        if (k > current_key)
        {
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