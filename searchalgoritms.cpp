#include "searchalgoritms.h"

/*******************************************
*   Конструктор класу SearchAlgoritms      *
*параметри:                                *
*   s - розмір масиву                      *
*   х - шуканий елемент                    *
*******************************************/
SearchAlgoritms::SearchAlgoritms(int s, int x): WorkWithMass(s)
{
    value = x;
}

/******************************************************
*   Сетер, що встановлює значення шуканого елемента   *
*параметри:                                           *
*   р - шуканий елемент                               *
*******************************************************/
void SearchAlgoritms::setValue(int p)
{
    value = p;
}

/**************************************************************
*   Функція, що відповідає за пошук Фібоначчі                 *
*параметри:                                                   *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::fibonachii_search( unsigned& c_operations, unsigned& a_operations, unsigned& r_operations)
{
    int fibon2 = 0;
    int fibon1 = 1;
    int fibon = fibon1 + fibon2;
    a_operations++;
    c_operations++;
    while (fibon1 + fibon <= size + 1) {
        a_operations+=2;
        c_operations++;
        fibon2 = fibon1;
        fibon1 = fibon;
        fibon = fibon1 + fibon2;
        a_operations++;
    }
    a_operations+=2;
    c_operations++;
    int M = fibon1 + fibon - size - 1, i = fibon - M, p = fibon1, q = fibon2;
    a_operations+=4;
    return recurs_fibonachi_search(i, p, q, c_operations, a_operations, r_operations);

}

/**************************************************************
*   Рукурсивна функція, що відповідає за пошук Фібоначчі      *
*параметри:                                                   *
*   і - поточне число Фібоначчі                               *
*   р - попереднє число Фібоначчі                             *
*   q - число Фібоначчі перед р                               *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::recurs_fibonachi_search(int i, int p, int q, unsigned& c_operations, unsigned& a_operations, unsigned& r_operations)
{
    r_operations++;
    c_operations++;
    if (i < 0) {
        return increase_I(i, p, q, c_operations, a_operations, r_operations);
    }
    else {
        c_operations++;
        if (i>=size) {
            return reduse_I(i, p, q, c_operations, a_operations, r_operations);
        }
    }
    c_operations++;
    if (value == massive[i]) {
        return i;
    }
    else {
        c_operations++;
        if (value > massive[i]) {
            return increase_I(i, p, q, c_operations, a_operations, r_operations);
        }
        else {
            return reduse_I(i, p, q, c_operations, a_operations, r_operations);
        }
    }
}

/**************************************************************
*   Функція, що відповідає за зменшення значення і            *
*параметри:                                                   *
*   і - поточне число Фібоначчі                               *
*   р - попереднє число Фібоначчі                             *
*   q - число Фібоначчі перед р                               *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::reduse_I(int i, int p, int q, unsigned& c_operations, unsigned& a_operations, unsigned& r_operations)
{
    c_operations++;
    if (q == 0) return -1;
    a_operations+=2;
    return recurs_fibonachi_search(i - q, q, p - q, c_operations, a_operations, r_operations);
}

/**************************************************************
*   Функція, що відповідає за збільшення значення і           *
*параметри:                                                   *
*   і - поточне число Фібоначчі                               *
*   р - попереднє число Фібоначчі                             *
*   q - число Фібоначчі перед р                               *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::increase_I(int i, int p, int q, unsigned& c_operations, unsigned& a_operations, unsigned& r_operations)
{
    c_operations++;
    if (p == 1) return -1;
    a_operations+=4;
    return recurs_fibonachi_search(i + q, p - q, 2 * q - p, c_operations, a_operations, r_operations);
}

/**************************************************************
*   Функція, що відповідає за послідовний пошук               *
*параметри:                                                   *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::pos_search( unsigned& c_operations, unsigned& a_operations, unsigned& r_operations) {
    r_operations +=0;
    a_operations +=0;
    for (int i = 0; i < size; i++) {
        c_operations+=2;
        if (value == massive[i]) return i;
    }
    c_operations++;
    return -1;
}

/**************************************************************
*   Функція, що відповідає за інтерполяційний пошук           *
*параметри:                                                   *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::interpolar_search( unsigned& c_operations, unsigned& a_operations, unsigned& r_operations)
{
    return recurs_interpolar_search(0, size-1, c_operations, ++a_operations, r_operations);
}

/**************************************************************
*   Рукурсивна функція, що відповідає за інтерполяційний пошук*
*параметри:                                                   *
*   begin - початок відрізку масиву, в якому йде пошук        *
*   end - кінець відрізку масиву, в якому йде пошук           *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::recurs_interpolar_search(int begin, int end, unsigned& c_operations, unsigned& a_operations, unsigned& r_operations)
{
    r_operations++;
    c_operations+=value >= massive[begin]?2:1;
    if (begin <= end && value >= massive[begin] && value <= massive[end]) {
        c_operations++;
        c_operations++;
        if(begin == end){
            c_operations++;
            if(value == massive[begin]) return begin;
            else return -1;
        }

        int i = begin + (((double)(end-begin)/(massive[end] - massive[begin]))*(value - massive[begin]));

        a_operations += 6;
        c_operations++;
        if (value == massive[i]) {
            return i;
        }
        else {
            c_operations++;
            if(value > massive[i]) return recurs_interpolar_search(i+1, end, c_operations, ++a_operations, r_operations);
            else return recurs_interpolar_search(begin, i-1, c_operations, ++a_operations, r_operations);
        }
    }
    return -1;
}

/**************************************************************
*   Функція, що відповідає за пошук хеш-функцією              *
*параметри:                                                   *
*   c_operations - лічильник кількості порівнянь              *
*   а_operations - лічильник кількості арифметичних операцій  *
*   г_operations - лічильник кількості рекурсивних викликів   *
**************************************************************/
int SearchAlgoritms::hash_function_search( unsigned& c_operations, unsigned& a_operations, unsigned& r_operations){
    hashtable hash_table(getSize()>10?getSize()/10:getSize());
    for(int i=0;i<getSize();i++){
        hash_table.add_element(massive[i], i);
    }
    int index = hash_table.search_element(value, c_operations, a_operations, r_operations);
    return index;
}
