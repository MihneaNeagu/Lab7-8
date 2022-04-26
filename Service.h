#pragma once
#include "Repo.h"

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo&);
    void add(int zi, int suma, bool type, char * descr);
    void del(int nr, int suma, bool type, char* descr);
    void update(int ziVeche, int sumaVeche, bool typeVechi, char* descrVeche, int ziNoua, int sumaNoua, bool typeNou, char* descrNoua);
    void getAll(Transaction v[], int& n);
    int getNoOfCheltuieli();
    void deleteByDay(int zi);
    void deleteBetweenDays(int zi1, int zi2);
    void deleteByDescr(char* descr);
    int sumByDescr(char* descr);
    Transaction maxSum(int sum);
    void sortByDescr(char* descr, Transaction v[], int& p);
    void filterByDescr(char* descr);
    void filterBySum(int sum);
    ~Service();
};
