#pragma once
#include "Transactions.h"
using namespace std;
class Repo{
private:
    Transaction elements[100];
    int nr;
public:
    Repo();
    ~Repo();
    void addItem(const Transaction &n);
    int size();
    Transaction * getAll();
    Repo(Transaction t[], int n);
    void delItem(Transaction &t);
    void updateItem(Transaction &tV, Transaction &tN);
    void findAll(Transaction t[], int &n);
};

