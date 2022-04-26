#pragma once
#include <cmath>
#include <ostream>
#include <cstring>
using namespace std;
class Transaction{
private:
    int day, sum;
    bool type;
    char *descr;

public:
    Transaction();
    Transaction(int a, int b, bool t, char *d);
    Transaction(Transaction &n);
    ~Transaction();
    void setDay(int day);
    void setSum(int sum);
    void setType(bool type);
    void setDescr(char *descr);
    int getDay();
    int getSum();
    bool getType();
    char *getDescr();
    bool operator==(Transaction t);
    friend ostream& operator<<(ostream& os, Transaction&z);
    friend istream& operator>>(istream& is, Transaction&z);
};

