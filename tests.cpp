#include "tests.h"
#include <cassert>
#include <cstring>
#include "Transactions.h"
#include "Repo.h"
#include "Operations.h"
#include "Service.h"
void tests_Transactions()
{
    Transaction t1(15,1200,true,"Pizza");
    assert(t1.getDay()==15);
    assert(t1.getSum()==1200);
    assert(t1.getType()==true);
    assert(strcmp(t1.getDescr(),"Pizza")==0);
}

void tests_Repo()
{
    Transaction t2(15,1200,true,"Pizza");
    Repo r1;
    r1.addItem(t2);
    assert(r1.size()==1);
    assert(r1.getAll()[0]==t2);
}

void tests_Filtreaza()
{
    Repo r2;
    Transaction x(11,1100,true,"Mancare");
    Transaction y(12,1300,true,"Mancare");
    Transaction z(19,900,false,"Mancare");
    r2.addItem(x);
    r2.addItem(y);
    r2.addItem(z);
    Transaction rezultat[2];
    int lenrezultat;

    filtreazaTranzactii(r2,"Mancare", 1000, rezultat,lenrezultat);
    assert(lenrezultat==2);
    assert(rezultat[0]==x);
    assert(rezultat[1]==y);

}

void tests_Service()
{
    Service serv;
    Transaction v[10];
    int n;

    serv.add(1, 200, true,  "gaz");
    serv.add(2, 250, false,  "apa");
    serv.add(3, 300, true,  "electricitate");

    assert(serv.getNoOfCheltuieli() == 3);

    serv.del(1, 200, true,  "gaz");
    serv.getAll(v, n);

    assert(serv.getNoOfCheltuieli() == 2);
    assert(v[0].getDay() == 2);
    assert(v[0].getSum() == 250);
    assert(v[0].getType()==false);
    assert(strcmp(v[0].getDescr(), "apa") == 0);

    serv.update(2, 250, false,  "apa", 4, 400,true,  "gaz");
    serv.getAll(v, n);

    assert(v[0].getDay() == 4);
    assert(v[0].getSum() == 400);
    assert(v[0].getType()==true);
    assert(strcmp(v[0].getDescr(), "gaz") == 0);
}


