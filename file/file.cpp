#include "file.h"


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
    while (p!=nullptr)
    {
        if (p->next==nullptr)
        {
            std::cout<<p->label<<"->"<<"NULL";
        }
        else
        {
            std::cout<<p->label<<"->";
        }
        p=p->next;
    }
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
