#ifndef SEARCHALGORITMS_H
#define SEARCHALGORITMS_H
#include "workwithmass.h"
#include "hashtable.h"

class SearchAlgoritms: public WorkWithMass
{
private:
    int value;
    //
    int recurs_fibonachi_search(int i, int p, int q);
    int reduse_I(int i, int p, int q);
    int increase_I(int i, int p, int q);
    //
    int recurs_interpolar_search(int begin, int end);
    //
public:
    SearchAlgoritms(int s, int x);
    void setValue(int p);
    //void show_mass();

    int fibonachii_search();

    int pos_search();

    int interpolar_search();

    int hash_function_search();
};

#endif // SEARCHALGORITMS_H
