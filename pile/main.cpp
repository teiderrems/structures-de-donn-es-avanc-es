#include "pile.h"


int main(int argc,char *argv[]){
    Pile *p=new Pile();
    p->push('a');
    p->push('b');
    p->push('c');
    p->push('d');
    p->push('e');
    p->print();
    Sommet *s=new Sommet('2');
    p->push(s);
    p->print();
    delete p;
    return EXIT_SUCCESS;
}