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
    CercadorMoviesHeap();

    CercadorMoviesHeap(const CercadorMoviesHeap &orig);

    virtual ~CercadorMoviesHeap();

    void appendMovies(string filename);

    void insertarMovie(int movieID, string title, float rating);

    string mostrarMovie(int movieID);

    Movie buscarMovie(int movieID);

    float buscarRatingMovie(int movieID);

    void eliminarMinimaMovie(int n);

    int height() const;

private:
};


#endif //EDD_PR_3_CERCADORMOVIESHEAP_H
