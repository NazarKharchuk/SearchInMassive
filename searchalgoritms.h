#ifndef SEARCHALGORITMS_H
#define SEARCHALGORITMS_H
#include "workwithmass.h"
#include "hashtable.h"

/***************************************************
*   Клас, що містить реалізацію методів пошуку     *
***************************************************/
class SearchAlgoritms: public WorkWithMass
{
private:
    int value;
    //   Допоміжні функції, для пошуку Фібоначчі
    int recurs_fibonachi_search(int, int, int, unsigned&, unsigned&, unsigned&);    //Прототип функції рекурсивного пошуку Фібоначчі
    int reduse_I(int, int, int, unsigned&, unsigned&, unsigned&);                   //Прототип функції, яка зменшує змінну і
    int increase_I(int, int, int, unsigned&, unsigned&, unsigned&);                 //Прототип функції, яка збільшує змінну і

    //   Допоміжні функції, для інтерполяційного пошуку
    int recurs_interpolar_search(int, int, unsigned&, unsigned&, unsigned&);        //Прототип функції рекурсивного інтерполяційного пошуку

public:
    SearchAlgoritms(int s, int x);      //   Конструктор класу SearchAlgoritms
    void setValue(int p);               //   Сетер, що встановлює значення шуканого елемента

    int fibonachii_search( unsigned&, unsigned&, unsigned&);    //   Прототип функції, яка реалізує пошук Фібоначчі

    int pos_search( unsigned&, unsigned&, unsigned&);           //   Прототип функції, яка реалізує послідовний пошук

    int interpolar_search( unsigned&, unsigned&, unsigned&);    //   Прототип функції, яка реалізує інтерполяційний пошук

    int hash_function_search( unsigned&, unsigned&, unsigned&); //   Прототип функції, яка реалізує пошук хеш-функцією
};

#endif // SEARCHALGORITMS_H
