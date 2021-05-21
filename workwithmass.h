#ifndef WORKWITHMASS_H
#define WORKWITHMASS_H


class WorkWithMass
{
public:
    WorkWithMass(int s);
    ~WorkWithMass();
protected:
    int* massive;
    int size;
    void setSize(int s);
    void create_mass();
    void delete_mass();
    void init_mass();
};

#endif // WORKWITHMASS_H
