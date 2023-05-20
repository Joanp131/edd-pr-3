//
// Created by Joanp on 18/5/2023.
//

#ifndef EDD_PR_3_CERCADORMOVIESHEAP_H
#define EDD_PR_3_CERCADORMOVIESHEAP_H

#include <iostream>
#include <fstream>
#include "MinHeap.h"

using namespace std;

class CercadorMoviesHeap : protected MinHeap<int, Movie>
{
public:
    // O(1)
    CercadorMoviesHeap();

    // O(n)
    CercadorMoviesHeap(const CercadorMoviesHeap &orig);

    // O(n)
    virtual ~CercadorMoviesHeap();

    // O(n log n) - n nombre de linies al fitxer
    void appendMovies(string filename);

    // O(log n)
    void insertarMovie(int movieID, string title, float rating);

    // O(n)
    string mostrarMovie(int movieID);

    // O(n)
    Movie buscarMovie(int movieID);

    // O(n)
    float buscarRatingMovie(int movieID);

    // O(log n · m), n nombre de nodes al heap i m nombre de nodes que volem eliminar
    void eliminarMinimaMovie(int n);

    // O(n)
    void imprimir();

    // O(1)
    int height() const;

private:
};


#endif //EDD_PR_3_CERCADORMOVIESHEAP_H
