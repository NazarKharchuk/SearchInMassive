#include "hashtable.h"

/*************************************
*   Конструктор класу hashtable      *
*параметри:                          *
*   size - размір хеш-таблиці        *
*************************************/
hashtable::hashtable(int size)
{
    table_size = size;
    table = new QList<QPair<int, int>>[size];
}

/************************************
*   Деструктор класу hashtable      *
*************************************/
hashtable::~hashtable(){
    delete [] table;
}

/***************************************
*   Функція, що шукає хеш елемента     *
***************************************/
int hashtable::hash(int element){
    return element % table_size;
}

/******************************************************
*   Функція, що додає новий елемент в хеш_таблицю     *
*параметри:                                           *
*   data - значення елемента                          *
*   index - індекс елемента                           *
*******************************************************/
void hashtable::add_element(int data, int index){
    int our_hash = hash(data);
    QPair<int, int> our_pair;
    our_pair.first=data;
    our_pair.second=index;
    table[our_hash].push_back(our_pair);
}

/**************************************************************
*   Функція, що відповідає за пошук елемнта в хеш-таблиці     *
*параметри:                                                   *
*   data - значення елемента                                  *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int hashtable::search_element(int data, unsigned& c_operations, unsigned& a_operations, unsigned& r_operations){
    r_operations+=0;
    int our_hash = hash(data);
    a_operations++;
    c_operations++;
    if(table[our_hash].empty())
    {
        return -1;
    }

    auto it = table[our_hash].begin();

    while(it != table[our_hash].end())
    {
        c_operations+=2;
        if((*it).first == data)
            return (*it).second;

        it++;
    }
    return -1;
}
