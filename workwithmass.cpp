#include "workwithmass.h"
#include <QTime>

WorkWithMass::WorkWithMass(int s)
{
    size = s;
    massive = new int[size];
}

WorkWithMass::~WorkWithMass(){
    delete [] massive;
}

void WorkWithMass::setSize(int s){
    size = s;
}

void WorkWithMass::create_mass(){
    massive = new int[size];
}


void WorkWithMass::delete_mass(){
    delete [] massive;
}


void WorkWithMass::init_mass(){
    for (int i = 0; i < size; i++) {
        if (i == 0) massive[i] = rand() % 50+1;
        else massive[i] = massive[i - 1] + rand() % 50+1;
    }
}

int WorkWithMass::getSize(){
    return size;
}

int WorkWithMass::getElement(int i){
    return massive[i];
}
