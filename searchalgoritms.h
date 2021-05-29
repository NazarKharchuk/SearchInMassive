#ifndef SEARCHALGORITMS_H
#define SEARCHALGORITMS_H
#include "workwithmass.h"
#include "hashtable.h"

class SearchAlgoritms: public WorkWithMass
{
private:
    int value;
    //
    int recurs_fibonachi_search(int i, int p, int q, unsigned&, unsigned&, unsigned&);
    int reduse_I(int i, int p, int q, unsigned&, unsigned&, unsigned&);
    int increase_I(int i, int p, int q, unsigned&, unsigned&, unsigned&);
    //
    int recurs_interpolar_search(int begin, int end, unsigned&, unsigned&, unsigned&);
    //
public:
    SearchAlgoritms(int s, int x);
    void setValue(int p);
    //void show_mass();

    int fibonachii_search( unsigned&, unsigned&, unsigned&);

    int pos_search( unsigned&, unsigned&, unsigned&);

    int interpolar_search(unsigned&, unsigned&, unsigned&);

    int hash_function_search( unsigned&, unsigned&, unsigned&);
};

#endif // SEARCHALGORITMS_H
