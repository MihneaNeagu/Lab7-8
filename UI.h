#pragma once

#include"Service.h"

class UI {
private:
    Service service;
public:
    UI();
    UI(Service& service);
    void runMenu();
    void displayMenu();
    void uiAddCheltuiala(int zi, int suma, bool type, char* descr);
    void uiUpdateTranzactie(int ziVeche, int sumaVeche, bool typeVechi, char* descrVeche,
                            int ziNoua, int sumaNoua, bool typeNou, char* descrNoua);
    void uiDeleteByDay(int zi);
    void uiDeleteBetweenDays(int zi1, int zi2);
    void uiDeleteByDescr(char* descr);
    void uiShowAll();
    void uiShowTransaction(int zi);
    void uiSumByDescr(char* descr);
    void uiMaxSum(int sum);
    void uiSortByDescr(char* descr);
    void uiFilterDescr(char* descr);
    void uiFilterSum(int sum);
    bool uiTransformBool(char* input);
    ~UI();
};
