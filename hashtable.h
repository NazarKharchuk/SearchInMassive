#ifndef HESHTABLE_H
#define HESHTABLE_H
#include <QList>

/*****************************************************
*   Клас, що відповідає за роботу з хеш-таблицею     *
*****************************************************/
class hashtable
{
    QList<QPair<int, int>>* table;      //  Хеш-таблиця
    int table_size;                     //  Значення розміру хеш-таблиці
    int hash(int);                      //  Прототип функції, яка знаходить хеш
public:
    hashtable(int);                     //   Конструктор класу hashtable
    ~hashtable();                       //   Деструктор класу hashtable
    void add_element(int, int);         //   Прототип функції, яка додає елемент до хеш-таблиці
    int search_element(int, unsigned&, unsigned&, unsigned&);   //   Прототип функції, яка реалізує пошук хеш-функцією
};

#endif // HESHTABLE_H
