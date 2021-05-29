#ifndef HESHTABLE_H
#define HESHTABLE_H
#include <QList>

class hashtable
{
    QList<QPair<int, int>>* table;
    int table_size;
    int hash(int);
public:
    hashtable(int size);
    ~hashtable();
    void add_element(int data, int index);
    int search_element(int data, unsigned& c, unsigned& b, unsigned& r);
};

#endif // HESHTABLE_H
