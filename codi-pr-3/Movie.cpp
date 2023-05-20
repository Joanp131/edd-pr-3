//
// Created by Joanp on 4/5/2023.
//

#include "Movie.h"

/**
 * Constructor per defecte
 */
Movie::Movie()
{

}

/**
 * Constructor còpia
 * @param orig
 */
Movie::Movie(const Movie &orig) : Movie()
{
    movieID = orig.movieID;
    rating = orig.rating;
    title = orig.title;
}

/**
 * Constructor amb paràmetres
 * @param movieID
 * @param title
 * @param rating
 */
Movie::Movie(int movieID, string title, float rating) : movieID(movieID), title(title), rating(rating)
{

}

/**
 * Retorna un string amb la informació de la pel·lícula
 * @return
 */
string Movie::toString() const
{
    return to_string(movieID) + "::" + title + "::" + to_string(rating);
}

/**
 * Retorna un string amb la informació de la pel·lícula
 * @return
 */
string Movie::print() const
{
    return to_string(movieID) + "::" + title + "::" + to_string(rating);
}

/**
 * Retorna el títol de la pel·lícula
 * @return
 */
const string &Movie::getTitle() const
{
    return title;
}

/**
 * Retorna el rating de la pel·lícula
 * @return
 */
float Movie::getRating() const
{
    return rating;
}
