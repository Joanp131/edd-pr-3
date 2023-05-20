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


class CercadorMoviesAB : protected ArbreBinari<int, Movie> {
public:
    CercadorMoviesAB();

    CercadorMoviesAB(const CercadorMoviesAB &orig);

    virtual ~CercadorMoviesAB();

    void appendMovies(string filename);

    void insertarMovie(int movieID, string title, float rating);

    string mostrarMovie(int movieID);

    Movie buscarMovie(int movieID);

    float buscarRatingMovie(int movieID);

    void eliminarMinimaMovie(int n);

    int height() const;

private:
    // Aqui posareu tots els mètodes auxiliars
    int alcada;
};


#endif //EDD_PR_3_CERCADORMOVIESAB_H
