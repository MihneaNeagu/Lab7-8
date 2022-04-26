#include "Service.h"
#include "Transactions.h"
#include "Repo.h"
Service::Service()
{
}

Service::Service(Repo& rep)
{
    this->repo = rep;
}

void Service::add(int zi, int suma, bool type, char* descr)
{
    Transaction t(zi, suma, type, descr);
    repo.addItem(t);
}

void Service::del(int zi, int suma,bool type, char* descr)
{
    Transaction t(zi, suma, type, descr);
    repo.delItem(t);
}

void Service::update(int ziVeche, int sumaVeche, bool typeVechi, char* descrVeche,
                     int ziNoua, int sumaNoua, bool typeNou, char* descrNoua)
{
    Transaction tV(ziVeche, sumaVeche, typeVechi, descrVeche);
    Transaction tN(ziNoua, sumaNoua, typeNou, descrNoua);
    repo.updateItem(tV, tN);
}

void Service::getAll(Transaction v[], int& n)
{
    repo.findAll(v, n);
}

int Service::getNoOfCheltuieli()
{
    return this->repo.size();
}

Service::~Service()
{
}

void Service::deleteByDay(int zi) {
    Transaction c[100];
    int n;
    repo.findAll(c, n);
    for (int i = 0; i < n; i++) {
        if (c[i].getDay() == zi) {
            repo.delItem(c[i]);
        }
    }
}

void Service::deleteBetweenDays(int zi1, int zi2)
{
    Transaction c[100];
    int n;
    repo.findAll(c, n);
    for (int i = 0; i < n; i++)
    {
        if (zi1 <= c[i].getDay() && c[i].getDay() <= zi2)
        {
            repo.delItem(c[i]);
        }
    }
}

void Service::deleteByDescr(char* descr)
{
    Transaction c[100];
    int n;
    repo.findAll(c, n);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(c[i].getDescr(), descr) == 0)
        {
            repo.delItem(c[i]);
        }
    }
}

int Service::sumByDescr(char* descr)
{
    Transaction c[100];
    int n, sum = 0;
    repo.findAll(c, n);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(c[i].getDescr(), descr) == 0)
        {
            sum += c[i].getSum();
        }
    }
    return sum;
}

Transaction Service::maxSum(int sum)
{
    Transaction c[100];
    int n;
    Transaction maxi(0, 0, false,  "null");
    repo.findAll(c, n);
    for (int i = 0; i < n; i++)
    {
        if (c[i].getSum() == sum)
        {
            if (c[i].getSum() > maxi.getSum())
            {
                maxi = c[i];
            }
        }
    }
    return maxi;
}

void Service::sortByDescr(char* descr, Transaction v[], int& p)
{
    Transaction c[100];
    int n;
    repo.findAll(c, n);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(c[i].getDescr(), descr) == 0)
        {
            v[p++] = c[i];
        }
    }

    for (int i = 0; i < p-1; i++)
        for (int j = i + 1; j < p; j++)
        {
            if (v[j].getSum() > v[i].getSum())
            {
                Transaction aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
}

void Service::filterByDescr(char* descr)
{
    Transaction c[100];
    int n;
    repo.findAll(c, n);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(descr, c[i].getDescr()) != 0)
        {
            repo.delItem(c[i]);
        }
    }
}

void Service::filterBySum(int sum)
{
    Transaction c[100];
    int n;
    repo.findAll(c, n);
    for (int i = 0; i < n; i++)
    {
        if (sum!=c[i].getSum())
        {
            repo.delItem(c[i]);
        }
    }
}