#include "searchalgoritms.h"

SearchAlgoritms::SearchAlgoritms(int s, int x): WorkWithMass(s)
{
    value = x;
}

void SearchAlgoritms::setValue(int p)
{
    value = p;
}

int SearchAlgoritms::fibonachii_search(unsigned& c, unsigned& b, unsigned& r)
{
    int fibon2 = 0;
    int fibon1 = 1;
    int fibon = fibon1 + fibon2;
    b++;
    c++;
    while (fibon1 + fibon <= size + 1) {
        c++;
        fibon2 = fibon1;
        fibon1 = fibon;
        fibon = fibon1 + fibon2;
        b++;
    }
    int M = fibon1 + fibon - size - 1, i = fibon - M, p = fibon1, q = fibon2;
    b+=4;
    return recurs_fibonachi_search(i, p, q, c, b, r);

}

int SearchAlgoritms::recurs_fibonachi_search(int i, int p, int q, unsigned& c, unsigned& b, unsigned& r)
{
    r++;
    c++;
    if (i < 0) {
        return increase_I(i, p, q, c, b, r);
    }
    else {
        c++;
        if (i>=size) {
            return reduse_I(i, p, q, c, b, r);
        }
    }
    c++;
    if (value == massive[i]) {
        return i;
    }
    else {
        c++;
        if (value > massive[i]) {
            return increase_I(i, p, q, c, b, r);
        }
        else {
            return reduse_I(i, p, q, c, b, r);
        }
    }
}

int SearchAlgoritms::reduse_I(int i, int p, int q, unsigned& c, unsigned& b, unsigned& r)
{
    c++;
    if (q == 0) return -1;
    return recurs_fibonachi_search(i - q, q, p - q, c, b, r);
}

int SearchAlgoritms::increase_I(int i, int p, int q, unsigned& c, unsigned& b, unsigned& r)
{
    c++;
    if (p == 1) return -1;
    return recurs_fibonachi_search(i + q, p - q, 2 * q - p, c, b, r);
}

int SearchAlgoritms::pos_search(unsigned& c, unsigned& b, unsigned& r) {
    for (int i = 0; i < size; i++) {
        c++;
        if (value == massive[i]) return i;
    }
    return -1;
}

int SearchAlgoritms::interpolar_search(unsigned& c, unsigned& b, unsigned& r)
{
    return recurs_interpolar_search(0, size-1, c, ++b, r);
}

int SearchAlgoritms::recurs_interpolar_search(int begin, int end, unsigned& c, unsigned& b, unsigned& r)
{
    r++;
    c++;
    if (begin <= end && value >= massive[begin] && value <= massive[end]) {
        c+=2;
        int i;
        c++;
        i = begin != end ? begin + ((end - begin) * (value - massive[begin])) / (massive[end] - massive[begin]): begin;
        c++;
        if (value == massive[i]) {
            return i;
        }
        else {
            c++;
            if(value > massive[i]) return recurs_interpolar_search(i+1, end, c, ++b, r);
            else return recurs_interpolar_search(begin, i-1, c, ++b, r);
        }
    }
    return -1;
}

int SearchAlgoritms::hash_function_search(unsigned& c, unsigned& b, unsigned& r){
    c++;
    b++;
    hashtable hash_table(getSize()>10?getSize()/10:getSize());
    for(int i=0;i<getSize();i++){
        hash_table.add_element(massive[i], i);
    }
    int index = hash_table.search_element(value, c, b, r);
    return index;
}
