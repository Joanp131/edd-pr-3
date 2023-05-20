//
// Created by Joanp on 4/5/2023.
//

#include "CercadorMoviesAB.h"

#include <utility>

/**
 * Constructor per defecte
 */
CercadorMoviesAB::CercadorMoviesAB() : ArbreBinari<int, Movie>()
{

}

/**
 * Constructor còpia
 * @param orig
 */
CercadorMoviesAB::CercadorMoviesAB(const CercadorMoviesAB &orig) : ArbreBinari<int, Movie>(orig)
{
}

/**
 * Destructor per defecte
 */
CercadorMoviesAB::~CercadorMoviesAB() = default;

/**
 * Llegeix la informació d'un fitxer i, per cada línia, insereix una nova pel·lícula a l'arbre
 * @param filename
 */
void CercadorMoviesAB::appendMovies(string filename)
{
    // Obrim el fitxer
    ifstream fitxer(filename);
    if (!fitxer.is_open())
    {
        cout << "No s'ha pogut obrir el fitxer\n";
    }

    while (fitxer)
    {
        string key_str, titol, rating_str;

        // Llegim la clau, el títol i el rating
        getline(fitxer, key_str, ':');
        getline(fitxer, titol, ':');
        getline(fitxer, rating_str);

        // Si hem llegit correctament, inserim un nou node a l'arbre
        if (!key_str.empty() && !titol.empty() && !rating_str.empty())
        {
            insertarMovie(stoi(key_str), titol, stof(rating_str));
        }
    }
}

/**
 * Insereix un nou node a l'arbre
 * @param movieID
 * @param title
 * @param rating
 */
void CercadorMoviesAB::insertarMovie(int movieID, string title, float rating)
{
    this->insert(movieID, Movie(movieID, title, rating));
}

/**
 * Donada una ID, busca una pel·lícula amb aquella ID i retorna la seva informació
 * @param movieID - ID que volem trobar
 * @return
 */
string CercadorMoviesAB::mostrarMovie(int movieID)
{
    Movie result = this->valueOf(movieID);
    return result.toString();
}

/**
 * Donada una ID, busca una pel·lícula amb aquella ID i retorna l'objecte Movie.
 * Retorna error si no s'ha trobat.
 * @param movieID - ID que volem trobar
 * @return
 */
Movie CercadorMoviesAB::buscarMovie(int movieID)
{
    Movie movie;
    try
    {
        movie = valueOf(movieID);
    } catch (exception ex)
    {
        throw out_of_range(
                "Movie CercadorMoviesAB::buscarMovie(int movieID): No s'ha trobat la Movie amb ID: " +
                to_string(movieID)
        );
    }
    return movie;
}

/**
 * Donada una ID, busca una pel·lícula amb aquella ID i retorna el seu rating
 * @param movieID - ID que volem trobar
 * @return
 */
float CercadorMoviesAB::buscarRatingMovie(int movieID)
{
    Movie movie = valueOf(movieID);
    return movie.getRating();
}

/**
 * Elimina les n pel·lícules amb ID més petita. Si n és més gran que el nombre
 * de nodes de l'arbre, l'arbre queda buit.
 * @param n
 */
void CercadorMoviesAB::eliminarMinimaMovie(int n)
{

    if (n <= 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isEmpty())
        {
            eliminaMinim();
        }
    }
}

/**
 * Retorna l'alçada de l'arbre
 * @return
 */
int CercadorMoviesAB::height() const
{
    return ArbreBinari<int, Movie>::height();
}

/**
 * Imprimeix tots els nodes per ID creixent
 */
void CercadorMoviesAB::imprimirInordre()
{
    ArbreBinari::imprimirInordre();
}
