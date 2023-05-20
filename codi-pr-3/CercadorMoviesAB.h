//
// Created by Joanp on 4/5/2023.
//

#ifndef EDD_PR_3_CERCADORMOVIESAB_H
#define EDD_PR_3_CERCADORMOVIESAB_H

#include <iostream>
#include <fstream>
#include <exception>
#include "Movie.h"
#include "ArbreBinari.h"

using namespace std;


class CercadorMoviesAB : protected ArbreBinari<int, Movie>
{
public:
    // O(1)
    CercadorMoviesAB();

    // O(n)
    CercadorMoviesAB(const CercadorMoviesAB &orig);

    // O(n)
    virtual ~CercadorMoviesAB();

    // O(n) - n nombre de linies al fitxer
    void appendMovies(string filename);

    // O(n)
    void insertarMovie(int movieID, string title, float rating);

    // O(n)
    string mostrarMovie(int movieID);

    // O(n)
    Movie buscarMovie(int movieID);

    // O(n)
    float buscarRatingMovie(int movieID);

    // O(n · m), n nombre de nodes de l'arbre, m nombre de nodes que volem eliminar
    void eliminarMinimaMovie(int n);

    // O(n)
    int height() const;

    // O(n)
    void imprimirInordre();

private:
    // Aqui posareu tots els mètodes auxiliars
};


#endif //EDD_PR_3_CERCADORMOVIESAB_H
