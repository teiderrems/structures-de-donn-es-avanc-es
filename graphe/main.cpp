#include "graphe.h"


int main(int argc,char * argv[]){

    Graphe* g=new Graphe();
    g->addNoeud('a');
    g->addNoeud('b');
    g->addNoeud('c');
    g->addNoeud('g');
    g->addNoeud('d');
    g->addNoeud('f');
    g->addNoeud('j');
    g->addArc('a','b');
    // g->addArc('c','d');
    // g->addArc('a','c');
    g->addArc('b','c');
    g->addArc('b','d');
    g->addArc('d','g');
    // g->addArc('a','g');
    g->addArc('c','g');
    g->addArc('d','f');
    g->addArc('d','j');
    g->addArc('b','j');
    // g->addArc('f','j');
    // g->addArc('j','g');
    
    g->printGraphe();
    std::cout<<std::endl;
    std::cout<<std::endl;
    g->largeur('a')->print();
    delete g;
    return EXIT_SUCCESS;
}