#include "Transactions.h"
#include <cstring>
#include <iostream>
using namespace std;

Transaction::Transaction() {
    this->day=0;
    this->sum=0;
    this->type = false;
    this->descr = new char[1];
    strcpy_s(this->descr,1,"");
}


Transaction::Transaction(int day, int sum, bool type, char *descr) {
    this->day = day;
    this->sum = sum;
    this->type = type;
    this->descr = new char[strlen(descr) + 1];
    strcpy_s(this->descr, strlen(descr) + 1, descr);
}

Transaction::Transaction(Transaction &n) {
    this->day = n.day;
    this->sum = n.sum;
    this->type = n.type;
    this->descr = new char[strlen(n.descr) + 1];
    strcpy_s(this->descr, strlen(n.descr) + 1, n.descr);
}

Transaction::~Transaction() {
    if(this->descr){
        delete[] this->descr;
    }
    this->day = 0;
    this->sum = 0;
    this->type = false;
}

void Transaction::setDay(int day) {
    this->day=day;
}

void Transaction::setSum(int sum) {
    this->sum=sum;
}

void Transaction::setType(bool type) {
    this->type=type;
}

void Transaction::setDescr(char *descr) {
    this->descr = new char[strlen(descr) + 1];
    strcpy_s(this->descr, strlen(descr) + 1, descr);
}

int Transaction::getDay() {
    return this->day;
}

int Transaction::getSum() {
    return this->sum;
}

bool Transaction::getType() {
    return this->type;
}

char *Transaction::getDescr() {
    return this->descr;
}

bool Transaction::operator==(Transaction t){
    return ((this->day == t.getDay()) && (strcmp(this->descr, t.getDescr()) == 0)
            &&(this->sum == t.getSum())&&(this->type == t.getType()));
}

ostream& operator<<(ostream& os, Transaction& z){
    os<<z.getDay()<<" "<<z.getSum()<<" "<<z.getType()<<" "<<z.getDescr();
    return os;
}

istream& operator>>(istream& is, Transaction& z){
    cout<<"Introduceti datele ziua(int), suma(int), type(bool), descr(string): "<<endl;
    int a,b;
    bool c;
    char *d;
    cout<<"Introduceti ziua: ";
    cin>>a;
    cout<<"Introduceti suma: ";
    cin>>b;
    cout<<"Introduceti type: ";
    cin>>c;
    cout<<"Introduceti descr: ";
    cin>>d;
    z.setDay(a);
    z.setSum(b);
    z.setType(c);
    z.setDescr(d);
    return is;
}




