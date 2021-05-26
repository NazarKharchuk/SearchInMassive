#ifndef WORKWITHMASS_H
#define WORKWITHMASS_H


class WorkWithMass
{
public:
    WorkWithMass(int s);
    ~WorkWithMass();
    void setSize(int s);
    void create_mass();
    void delete_mass();
    void init_mass();
    int getSize();
    int getElement(int);
protected:
    int* massive;
    int size;
};

#endif // WORKWITHMASS_H
