//
// Created by Joanp on 4/5/2023.
//

#ifndef EDD_PR_3_MOVIE_H
#define EDD_PR_3_MOVIE_H

#include <iostream>
using namespace std;

class Movie {
public:
    Movie();
    Movie(const Movie &orig);
    Movie(int movieID, string title, float rating);

    // Getters
    const string &getTitle() const;

    float getRating() const;

    // Setters

    string toString() const;
    string print() const;

private:
    int movieID;
    string title;
    float rating;
};


#endif //EDD_PR_3_MOVIE_H
