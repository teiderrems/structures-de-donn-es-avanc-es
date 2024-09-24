#include "graphe.h"

File *Graphe::largeur(char l)
{
    Sommet* s = this->findNoeud(l);
    File* f = nullptr;
    File* result = nullptr;

    if (s != nullptr) {
        result = new File();
        f = new File();
        char c;
        s->color = 1; // 1 = gris (en cours de traitement)
        f->enfiler(s); // Enfile le sommet de départ
        // delete s;
        while (!f->is_empty()){
            f->print();
            s = f->defiler(); // On défile le sommet en cours de traitement
            Arc* arc = s->arcs; // On commence par examiner la liste d'arcs du sommet actuel
            while (arc != nullptr && arc->noeud->color==0) {
                Sommet* voisin = arc->noeud;
                // Si le voisin n'est pas encore visité
                if (voisin->color == 0) { // 0 = blanc (non visité)
                    voisin->color = 1; // Marque comme gris (en cours de traitement)
                    f->enfiler(voisin); // Enfile le voisin
                }
                arc = arc->next; // Passe à l'arc suivant
            }
            s->color = 2; // 2 = noir (traité complètement)
            result->enfiler(s); // Ajoute le sommet traité à la liste des résultats
            result->print();
            scanf("%c",&c);
        }

        return result;
    }
    return nullptr;
}


// File *Graphe::profondeur(char l)
// {
//     Sommet * s=this->findNoeud(l);
//     Pile * p=nullptr;
//     File *result=nullptr;
//     if (s!=nullptr)
//     {
//         p=new Pile();
//         result=new File();
//         s->color=1;
//         p->push(s);
//         char c;
//         while (!p->is_empty())
//         {
//             p->print();
//             scanf("%c",&c);
//             s=p->sommet;
//             Sommet * current=s->next;
//             while (current!=nullptr && current->color==0)
//             {
//                 if (current->color==0)
//                 {
//                     current->color=1;
//                     p->push(current);
//                 }
//                 current=current->next;
//             }
//             // delete c;
//             s=p->pop();
//             s->color=2;
//             result->enfiler(s);
//             result->print();
//             scanf("%c",&c);
//         }
//         // delete s;
//         return result;
//     }
//     return nullptr;
// }


// File *Graphe::profondeur(char l)
// {
//     Sommet *s = this->findNoeud(l);  // Find the starting node
//     Pile *p = nullptr;               // Stack to help with DFS
//     File *result = nullptr;          // Result to store DFS traversal

//     if (s != nullptr)
//     {
//         p = new Pile();
//         result = new File();
        
//         s->color = 1;                // Mark the starting node as visited (gray)
//         p->push(s);                  // Push the starting node onto the stack
        
//         while (!p->is_empty())
//         {
//             p->print();
//             s = p->sommet;           // Get the top node from the stack without popping it
//             Sommet *current = s->next;
//             bool hasUnvisited = false;

//             while (current != nullptr && current->color==0)
//             {
//                 if (current->color == 0)  // Check if the neighbor is unvisited
//                 {
//                     current->color = 1;   // Mark neighbor as visited (gray)
//                     p->push(current);     // Push neighbor onto stack
//                     hasUnvisited = true;
//                     break;                // Stop to process the newly discovered node
//                 }
//                 current = current->next;
//             }

//             if (!hasUnvisited)  // If no unvisited neighbors are found
//             {
//                 s = p->pop();   // Pop from the stack
//                 s->color = 2;   // Mark it as fully explored (black)
//                 result->enfiler(s); // Add it to the result
//                 result->print();
//             }
//         }

//         delete p;     // Free the memory used by the stack
//         return result;
//     }
    
//     return nullptr;
// }


void Graphe::addNoeud(char label)
{
    if (this->noeud==nullptr)
    {
        this->noeud=new Sommet(label);
    }
    else
    {
        Sommet* p=this->noeud;
        while (p->next!=nullptr)
        {
            p=p->next;
        }
        p->next=new Sommet(label);
    }
}

void Graphe::addArc(char l1, char l2)
{
    Sommet * s1=findNoeud(l1);
    Sommet * s2=findNoeud(l2);
    Arc * arc=new Arc(s2);
    if (s1->arcs==nullptr)
    {
        s1->arcs=arc;
    }
    else{
        Arc* current=s1->arcs;
        while (current->next!=nullptr)
        {
            current=current->next;
        }
        current->next=arc;
    }
    arc=new Arc(s1);
    if (s2->arcs==nullptr)
    {
        s2->arcs=arc;
    }
    else{
        Arc* current=s2->arcs;
        while (current->next!=nullptr)
        {
            current=current->next;
        }
        current->next=arc;
    }
}

Sommet * Graphe::findNoeud(char l)
{
    if (this->noeud!=nullptr)
    {
        Sommet * p=this->noeud;
        while (p!=nullptr && p->label!=l)
        {
            p=p->next;
        }
        if (p!=nullptr)
        {
            return p;
        }
    }
    return nullptr;
}

void Graphe::printGraphe()
{
    if (this->noeud==nullptr)
    {
        return;
    }
    else
    {
        Sommet* p=this->noeud;
        while (p!=nullptr)
        {
            std::cout<<p->label<<"->";
            if (p->arcs!=nullptr)
            {
                Arc * ar=p->arcs;
                while (ar!=nullptr)
                {
                    std::cout<<ar->noeud->label<<"->";
                    ar=ar->next;
                }
            }
            std::cout<<std::endl;
            p=p->next;
        }
    }
       
}

Graphe::~Graphe()
{
    if (this->noeud==nullptr)
    {
        return;
    }
    else
    {
        Sommet *p=this->noeud;
        while (p!=nullptr)
        {
            Arc* ac=p->arcs;
            while (ac!=nullptr)
            {
                Arc* e=ac;
                ac=e->next;
                delete e;
            }
            Sommet * e=p;
            p=e->next;
            delete e;
        }
    }
}

void Pile::push(char l)
{
    if (sommet==nullptr)
    {
        sommet=new Sommet(l);
    }
    else
    {
        Sommet* e=new Sommet(l);
        e->next=sommet;
        sommet=e;
    }
}

void Pile::push(Sommet * s)
{
    if (sommet==nullptr)
    {
        sommet=s;
    }
    else
    {
        s->next=sommet;
        sommet=s;
    }
}

Sommet * Pile::pop()
{
    if (sommet==nullptr)
    {
        return nullptr;
    }
    else
    {
        Sommet *e=sommet;
        sommet=e->next;
        return e;
    }
}

bool Pile::is_empty()
{
    return sommet==nullptr;
}

void Pile::print()
{
    if (sommet==nullptr)
    {
        return;
    }
    else
    {
        Sommet * p=sommet;
        while (p!=nullptr)
        {
            std::cout<<p->label<<"->";
            p=p->next;
        }
        std::cout<<std::endl;
    }
}

Pile::~Pile()
{
    if (sommet==nullptr)
    {
        return;
    }
    else
    {
        while (sommet!=nullptr)
        {
            Sommet* e=sommet;
            sommet=e->next;
            delete e;
        }
    }
}


void File::enfiler(char label){

    if (tete==nullptr)
    {
        tete=new Sommet(label);
        queue=tete;
    }
    else
    {
        Sommet * e=new Sommet(label);
        queue->next=e;
        queue=e;
    }
}

void File::enfiler(Sommet * s)
{
    if (tete==nullptr)
    {
        tete=s;
        queue=s;
    }
    else
    {
        queue->next=s;
        queue=s;
    }
}

bool File::is_empty()
{
    if (tete==nullptr)
    {
        return true;
    }
    return false;
}

int File::length()
{
    int nb=0;
    if (tete==nullptr)
    {
        return 0;
    }
    else
    {
       Sommet * p=tete;
       while (p!=nullptr)
       {
            nb++;
            p=p->next;
       }
        return nb;
    }
}

void File::print()
{
    if (tete==nullptr)
    {
        return;
    }
    Sommet *p=tete;
    std::cout<<std::endl;
    while (p!=nullptr)
    {
        if (p->next==nullptr)
        {
            std::cout<<"("<<p->label<<","<<p->color<<")"<<"->"<<"NULL";
        }
        else
        {
            std::cout<<"("<<p->label<<","<<p->color<<")"<<"->";
        }
        p=p->next;
    }
    std::cout<<std::endl;
}

Sommet * File::defiler(){

    if (tete==nullptr)
    {
       return nullptr;
    }
    else
    {
        Sommet * e=tete;
        tete=e->next;
        return e;
    }
}

File::~File()
{
    if (tete==nullptr)
    {
        return;
    }
    else
    {
        Sommet * p=tete;
        while (p!=nullptr)
        {
            Sommet * e=p;
            p=e->next;
            delete e;
        }
    }
}

