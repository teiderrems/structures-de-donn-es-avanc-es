#include "file.h"


int main(int argc,char * argv[]){
    File* f=new File();
    std::cout<<f->is_empty()<<std::endl;
    f->print();
    f->enfiler('a');
    f->enfiler('b');
    f->enfiler('c');
    f->enfiler('d');
    f->enfiler('e');
    f->enfiler('f');
    f->enfiler('g');

    f->print();
    std::cout<<std::endl<<f->is_empty()<<std::endl;
    std::cout<<std::endl<<f->length()<<std::endl;

    std::cout<<std::endl<<"("<<f->tete->label<<","<<f->queue->label<<")"<<std::endl;
    delete f;
    return EXIT_SUCCESS;
}