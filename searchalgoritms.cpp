#include "searchalgoritms.h"

SearchAlgoritms::SearchAlgoritms(int s, int x): WorkWithMass(s)
{
    value = x;
}

void SearchAlgoritms::setValue(int p)
{
    value = p;
}

/*void SearchAlgoritms::show_mass()
{
    cout << "Massive:\n";
    for (int i = 0; i < size-1; i++) {
        cout << massive[i]<<" ,  ";
    }
    if (size > 0) cout << massive[size - 1] << "." << endl;
}*/

int SearchAlgoritms::fibonachii_search()
{
    int fibon2 = 0;
    int fibon1 = 1;
    int fibon = fibon1 + fibon2;
    while (fibon1 + fibon <= size + 1) {
        fibon2 = fibon1;
        fibon1 = fibon;
        fibon = fibon1 + fibon2;
    }
    int M = fibon1 + fibon - size - 1, i = fibon - M, p = fibon1, q = fibon2;

    return recurs_fibonachi_search(i, p, q);

}

int SearchAlgoritms::recurs_fibonachi_search(int i, int p, int q)
{
    if (i < 0) {
        return increase_I(i, p, q);
    }
    else {
        if (i>=size) {
            return reduse_I(i, p, q);
        }
    }

    if (value == massive[i]) {
        return i;
    }
    else {
        if (value > massive[i]) {
            return increase_I(i, p, q);
        }
        else {
            return reduse_I(i, p, q);
        }
    }
}

int SearchAlgoritms::reduse_I(int i, int p, int q)
{
    if (q == 0) return -1;
    return recurs_fibonachi_search(i - q, q, p - q);
}

int SearchAlgoritms::increase_I(int i, int p, int q)
{
    if (p == 1) return -1;
    return recurs_fibonachi_search(i + q, p - q, 2 * q - p);
}

int SearchAlgoritms::pos_search() {
    for (int i = 0; i < size; i++) {
        if (value == massive[i]) return i;
    }
    return -1;
}

int SearchAlgoritms::interpolar_search()
{
    return recurs_interpolar_search(0, size-1);
}

int SearchAlgoritms::recurs_interpolar_search(int begin, int end)
{
    if (begin <= end && value >= massive[begin] && value <= massive[end]) {
        int i = begin + ((end - begin) * (value - massive[begin])) / (massive[end] - massive[begin]);
        if (value == massive[i]) {
            return i;
        }
        else {
            if(value > massive[i]) return recurs_interpolar_search(i+1, end);
            else return recurs_interpolar_search(begin, i-1);
        }
    }
    return -1;
}
