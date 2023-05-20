//
// Created by Joanp on 4/5/2023.
//

#include "CercadorMoviesAB.h"

#include <utility>

CercadorMoviesAB::CercadorMoviesAB() : ArbreBinari<int, Movie>() {

}

CercadorMoviesAB::CercadorMoviesAB(const CercadorMoviesAB &orig) : ArbreBinari<int, Movie>(orig) {
}

CercadorMoviesAB::~CercadorMoviesAB() = default;

void CercadorMoviesAB::appendMovies(string filename) {
    ifstream fitxer(filename);
    if (!fitxer.is_open()) {
        cout << "No s'ha pogut obrir el fitxer\n";
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

/**
 *
 * @param movieID
 * @param title
 * @param rating
 */
void CercadorMoviesAB::insertarMovie(int movieID, string title, float rating) {
    this->insert(movieID, Movie(movieID, title, rating));
}

string CercadorMoviesAB::mostrarMovie(int movieID) {
    Movie result = this->valueOf(movieID);
    return result.toString();
}

Movie CercadorMoviesAB::buscarMovie(int movieID) {
    Movie movie;
    try {
        movie = valueOf(movieID);
    } catch (exception ex) {
        throw out_of_range(
                "Movie CercadorMoviesAB::buscarMovie(int movieID): No s'ha trobat la Movie amb ID: " + to_string(movieID)
                );
    }
    return movie;
}

float CercadorMoviesAB::buscarRatingMovie(int movieID) {
    Movie movie = valueOf(movieID);
    return movie.getRating();
}

void CercadorMoviesAB::eliminarMinimaMovie(int n) {

    if(n <= 0) {
        return;
    }

    for (int i = 0; i < n; i ++) {
        if(!isEmpty()) {
            eliminaMinim();
        }
    }
}

int CercadorMoviesAB::height() const {
    return ArbreBinari<int, Movie>::height();
}
