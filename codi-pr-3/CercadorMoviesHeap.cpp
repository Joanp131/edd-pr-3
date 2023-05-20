//
// Created by Joanp on 18/5/2023.
//

#include "CercadorMoviesHeap.h"

/**
 * Constructor per defecte
 */
CercadorMoviesHeap::CercadorMoviesHeap() : MinHeap<int, Movie>() {}

/**
 * Constructor còpia
 * @param orig
 */
CercadorMoviesHeap::CercadorMoviesHeap(const CercadorMoviesHeap &orig) : MinHeap<int, Movie>(orig) {}

/**
 * Destructor per defecete
 */
CercadorMoviesHeap::~CercadorMoviesHeap() {}

/**
 * Llegeix un fitxer i per cada línia insereix un nou node al heap
 * @param filename
 */
void CercadorMoviesHeap::appendMovies(string filename)
{

    ifstream fitxer(filename);

    if (!fitxer.is_open())
    {
        cout << "\nNo s'ha pogut obrir el fitxer" << endl;
        return;
    }

    while (fitxer)
    {
        string key_str, titol, rating_str;

        getline(fitxer, key_str, ':');
        getline(fitxer, titol, ':');
        getline(fitxer, rating_str);

        if (!key_str.empty() && !titol.empty() && !rating_str.empty())
        {
            insertarMovie(stoi(key_str), titol, stof(rating_str));
        }
    }

}

/**
 * Inserex un nou node al heap
 * @param movieID
 * @param title
 * @param rating
 */
void CercadorMoviesHeap::insertarMovie(int movieID, string title, float rating)
{
    this->inserir(movieID, Movie(movieID, title, rating));
}

/**
 * Donada una ID, busca una pel·lícula i retorna la seva informació. Retorna error si no hi és
 * @param movieID
 * @return
 */
string CercadorMoviesHeap::mostrarMovie(int movieID)
{
    Movie movie;
    try
    {
        movie = cerca(movieID);
        return movie.print();
    } catch (exception ex)
    {
        throw out_of_range(
                "string CercadorMoviesHeap::mostrarMovie(int movieID): No s'ha trobat la Movie indicada per l'ID donada");
    }
}

/**
 * Donada una ID, busca una pel·lícula i retorna l'objecte. Retorna error si no hi és
 * @param movieID
 * @return
 */
Movie CercadorMoviesHeap::buscarMovie(int movieID)
{
    Movie movie;
    try
    {
        movie = cerca(movieID);
        return movie;
    } catch (exception ex)
    {
        throw out_of_range(
                "string CercadorMoviesHeap::mostrarMovie(int movieID): No s'ha trobat la Movie indicada per l'ID donada");
    }
}

/**
 * Donada una ID, busca una pel·lícula i retorna el seu rating. Retorna error si no hi és
 * @param movieID
 * @return
 */
float CercadorMoviesHeap::buscarRatingMovie(int movieID)
{
    Movie movie;
    try
    {
        movie = cerca(movieID);
        return movie.getRating();
    } catch (exception ex)
    {
        throw out_of_range(
                "string CercadorMoviesHeap::mostrarMovie(int movieID): No s'ha trobat la Movie indicada per l'ID donada");
    }
}

/**
 * Elimina les n pel·lícules que tenen el rating més petit
 * @param n
 */
void CercadorMoviesHeap::eliminarMinimaMovie(int n)
{

    if (n <= 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!this->esBuit())
        {
            this->eliminaMinim();
        }
    }
}

/**
 * Retorna l'alçada del heap
 * @return
 */
int CercadorMoviesHeap::height() const
{
    return MinHeap::altura();
}

/**
 * Imprimeix totes les ID del heap, una línia per nivell
 */
void CercadorMoviesHeap::imprimir()
{
    MinHeap::imprimir();
}
