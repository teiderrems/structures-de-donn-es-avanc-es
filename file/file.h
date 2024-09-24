#ifndef ___FILE___
#define ___FILE___
#include "../header.h"

// typedef struct Element
// {
//     char label;
//     Element *next;
//     Element(char l):label(l),next(nullptr){}
// } Element;

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
// class File
// {
// public:
//     Element * tete;
//     Element * queue;
//     File():tete(nullptr),queue(nullptr){};
//     void enfiler(char);
//     bool is_empty();
//     int length();
//     void print();
//     Element *  defiler();
//     ~File();
// };





#endif //___FILE___