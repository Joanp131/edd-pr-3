//
// Created by Joanp on 4/5/2023.
//

#include "Movie.h"


Movie::Movie() {

}

Movie::Movie(const Movie &orig) : Movie()
{
    movieID = orig.movieID;
    rating = orig.rating;
    title = orig.title;
}

Movie::Movie(int movieID, string title, float rating) : movieID(movieID), title(title), rating(rating)
{

}

string Movie::toString() const
{
    return to_string(movieID) + "::" + title + "::" + to_string(rating);
}

string Movie::print() const
{
    return to_string(movieID) + "::" + title + "::" + to_string(rating);
}

const string &Movie::getTitle() const
{
    return title;
}

float Movie::getRating() const
{
    return rating;
}
