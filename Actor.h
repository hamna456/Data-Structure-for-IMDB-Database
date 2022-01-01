#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>
#include <forward_list>
#include <map>
#include <unordered_map>
#include "Movie.h"
#include "AVL.h"

// forward declaration
class Movie;
class ActorAVL;

using namespace std;
class Actor
{
public:
    string name;
    int fbLikesForActor;
    map<string, forward_list<Movie *>> movieList; //sorted chronologically

    static unordered_map<string, ActorAVL *> allActors; // avl sorted on actor name

    //constructor
    Actor();
    Actor(string);
    Actor(string, int);

    //setters
    void setName(string);
    void setLikes(int);
    void addMovie(Movie *);

    //getters
    string getName();
    int getLikes();
    map<string, forward_list<Movie *>> getMovie();

    // add to main map
    void addActor(Actor *);

    // methods related to actors specified in document provided
    static Actor *searchActor(string, bool);
    static void displayActorProfile(Actor *);
    void getCoActors(string);
    void getUniqueCoActors(string);
    void getCoActorsOfCoActors(string);
    bool isCoActor(string, string);
};

#endif