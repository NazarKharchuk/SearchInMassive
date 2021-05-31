#ifndef WORKWITHMASS_H
#define WORKWITHMASS_H

/***********************************
*   Клас, що працює із масивом     *
***********************************/
class WorkWithMass
{
public:
    WorkWithMass(int);      //   Конструктор класу WorkWithMass
    ~WorkWithMass();        //   Деструктор класу WorkWithMass
    void setSize(int s);    //   Сетер, що встановлює значення розміру масиву
    void create_mass();     //   Прототип функції, яка створює масив
    void delete_mass();     //   Прототип функції, яка видаляє масив
    void init_mass();       //   Прототип функції, яка ініціалізує масив
    int getSize();          //   Гетер, що повертає значення розміру масиву
    int getElement(int);    //   Гетер, що повертає значення елемента певної комірки масиву

protected:
    int* massive;           //   Оброблюваний динамічний масив
    int size;               //   Значення розміру оброблюваного масиву
};

#endif // WORKWITHMASS_H
