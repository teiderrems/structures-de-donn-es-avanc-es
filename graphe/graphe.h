#ifndef ___GRAPHE___
#define ___GRAPHE___
#include<iostream>



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

class Pile
{
public:
    Sommet* sommet;
    void push(char);
    void push(Sommet *);
    Sommet * pop();
    bool is_empty();
    Pile():sommet(nullptr){}
    void print();
    ~Pile();
};

class File
{
public:
    Sommet * tete;
    Sommet * queue;
    File():tete(nullptr),queue(nullptr){};
    void enfiler(char);
    void enfiler(Sommet *);
    bool is_empty();
    int length();
    void print();
    Sommet *  defiler();
    ~File();
};


class Graphe
{
public:
    Sommet *noeud;
    Graphe():noeud(nullptr){}
    File * largeur(char);
    File * profondeur(char);
    void addNoeud(char label);
    void addArc(char,char);
    Sommet * findNoeud(char);
    void printGraphe();
    ~Graphe();
};








#endif //___GRAPHE___