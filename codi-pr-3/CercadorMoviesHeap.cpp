//
// Created by Joanp on 18/5/2023.
//

#include "CercadorMoviesHeap.h"

CercadorMoviesHeap::CercadorMoviesHeap() : MinHeap<int, Movie>() {}

CercadorMoviesHeap::CercadorMoviesHeap(const CercadorMoviesHeap &orig) : MinHeap<int, Movie>(orig) {}

CercadorMoviesHeap::~CercadorMoviesHeap() {}

void CercadorMoviesHeap::appendMovies(string filename) {

    ifstream fitxer(filename);

    if (!fitxer.is_open()) {
        cout << "\nNo s'ha pogut obrir el fitxer" << endl;
        return;
    }

    while (fitxer) {
        string key_str, titol, rating_str;

        getline(fitxer, key_str, ':');
        getline(fitxer, titol, ':');
        getline(fitxer, rating_str);

        if (!key_str.empty() && !titol.empty() && !rating_str.empty()) {
            insertarMovie(stoi(key_str), titol, stof(rating_str));
        }
    }

}

void CercadorMoviesHeap::insertarMovie(int movieID, string title, float rating) {
    this->inserir(movieID, Movie(movieID, title, rating));
}

string CercadorMoviesHeap::mostrarMovie(int movieID) {
    Movie movie;
    try {
        movie = cerca(movieID);
        return movie.print();
    } catch (exception ex) {
        throw out_of_range(
                "string CercadorMoviesHeap::mostrarMovie(int movieID): No s'ha trobat la Movie indicada per l'ID donada");
    }
}

Movie CercadorMoviesHeap::buscarMovie(int movieID) {
    Movie movie;
    try {
        movie = cerca(movieID);
        return movie;
    } catch (exception ex) {
        throw out_of_range(
                "string CercadorMoviesHeap::mostrarMovie(int movieID): No s'ha trobat la Movie indicada per l'ID donada");
    }
}

float CercadorMoviesHeap::buscarRatingMovie(int movieID) {
    Movie movie;
    try {
        movie = cerca(movieID);
        return movie.getRating();
    } catch (exception ex) {
        throw out_of_range(
                "string CercadorMoviesHeap::mostrarMovie(int movieID): No s'ha trobat la Movie indicada per l'ID donada");
    }
}

void CercadorMoviesHeap::eliminarMinimaMovie(int n) {

    if(n <= 0) {
        return;
    }

    for(int i = 0; i < n; i++) {
        if (!this->esBuit()) {
            this->eliminaMinim();
        }
    }
}

int CercadorMoviesHeap::height() const {
    return MinHeap<int, Movie>::altura();
}