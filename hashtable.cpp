#include "hashtable.h"

hashtable::hashtable(int size)
{
    table_size = size;
    table = new QList<QPair<int, int>>[size];
}

hashtable::~hashtable(){
    delete [] table;
}

int hashtable::hash(int element){
    return element % table_size;
}

void hashtable::add_element(int data, int index){
    int our_hash = hash(data);
    QPair<int, int> our_pair;
    our_pair.first=data;
    our_pair.second=index;
    table[our_hash].push_back(our_pair);
}

int hashtable::search_element(int data, unsigned& c, unsigned& b, unsigned& r){
    int our_hash = hash(data);
    b++;
    c++;
    if(table[our_hash].empty())
    {
        return -1;
    }

    auto it = table[our_hash].begin();

    while(it != table[our_hash].end())
    {
        c++;
        if((*it).first == data)
            return (*it).second;

        it++;
    }
    return -1;
}
