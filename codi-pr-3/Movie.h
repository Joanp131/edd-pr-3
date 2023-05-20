//
// Created by Joanp on 4/5/2023.
//

#ifndef EDD_PR_3_MOVIE_H
#define EDD_PR_3_MOVIE_H

#include <iostream>

using namespace std;

class Movie
{
public:
    // O(1)
    Movie();

    // O(1)
    Movie(const Movie &orig);

    // O(1)
    Movie(int movieID, string title, float rating);

    // Getters
    // O(1)
    const string &getTitle() const;

    // O(1)
    float getRating() const;

    // Setters

    // O(1)
    string toString() const;

    // O(1)
    string print() const;

private:
    int movieID;
    string title;
    float rating;
};


#endif //EDD_PR_3_MOVIE_H
