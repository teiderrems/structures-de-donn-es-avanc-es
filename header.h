#ifndef ___MODULE___
#define ___MODULE___
// #include "pile/pile.h"
// #include "file/file.h"
#include<iostream>
// #include "./file/file.h"
// #include "./pile/pile.h"

class Arc;
class Sommet;

class Sommet
{
public:
    char label;
    Sommet * next;
    int color;
    Arc* arcs;
    Sommet(char l):label(l),arcs(nullptr),next(nullptr),color(0){}
    ~Sommet()=default;
};

class Arc
{
public:
    Sommet * noeud;
    Arc *next;
    Arc(Sommet *s):noeud(s),next(nullptr){}
    ~Arc()=default;
};



#endif //___MODULE___