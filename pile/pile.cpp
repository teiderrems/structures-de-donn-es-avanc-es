#include "pile.h"


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
