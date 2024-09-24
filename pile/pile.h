#ifndef ___PILE___
#define ___PILE___
#include "../header.h"

// typedef struct Element
// {
//     char label;
//     Element *next;
//     Element(char l):label(l),next(nullptr){}
// } Element;


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
// class Pile
// {
// public:
//     Element* sommet;
//     void push(char);
//     Element * pop();
//     bool is_empty();
//     Pile():sommet(nullptr){}
//     void print();
//     ~Pile();
// };




#endif //___PILE___