#include "UI.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

UI::UI()
{
}

UI::UI(Service& service)
{
    this->service = service;
}

bool isInt(char* token)
{
    if (isdigit(atoi(token)))
        return true;
    return false;
}

void UI::runMenu()
{
    bool optiuneGresita;
    this->displayMenu();
    while (true)
    {
        char cmd[35];
        cin.getline(cmd, 35);
        char* token1;
        char* token2;
        char* token3;
        char* token4;
        char* token5;
        char* token6;
        char* token7;
        char* token8;
        char* token9;

        token1 = strtok(cmd, " ");
        token2 = strtok(NULL, " ");
        token3 = strtok(NULL, " ");
        token4 = strtok(NULL, " ");
        token5 = strtok(NULL, " ");
        token6 = strtok(NULL, " ");
        token7 = strtok(NULL, " ");
        token8 = strtok(NULL, " ");
        token9 = strtok(NULL, " ");

        optiuneGresita = true;

        if (strcmp(token1, "adauga") == 0)
        {
            if (token5 == NULL)
            {
                cout << "Format comanda gresita!" << endl;
            }
            else {
                int ap = atoi(token2);
                int suma = atoi(token3);
                bool type = uiTransformBool(token4);
                this->uiAddCheltuiala(ap, suma, type, token5);
                optiuneGresita = false;
            }
        }
        if (strcmp(token1, "eliminare") == 0)
        {
            if (token2 == NULL || token3 != NULL && token4 == NULL)
            {
                cout << "Format comanda gresita!" << endl;
            }
            else
            if (token3 == NULL && token2 != NULL)
            {
                if (isInt(token2))
                {
                    int ap = atoi(token2);
                    this->uiDeleteByDay(ap);
                    optiuneGresita = false;

                }
                else
                {
                    this->uiDeleteByDescr(token2);
                    optiuneGresita = false;

                }
            }
            else
            {
                int ap1 = atoi(token2);
                int ap2 = atoi(token4);
                this->uiDeleteBetweenDays(ap1, ap2);
                optiuneGresita = false;

            }
        }
        if (strcmp(token1, "inlocuire") == 0)
        {
            if (token5 == NULL)
            {
                cout << "Format comanda gresita!" << endl;
            }
            else
            {
                int apv = atoi(token2);
                int sumav = atoi(token3);
                bool typev = uiTransformBool(token4);
                int apn = atoi(token6);
                int suman = atoi(token7);
                bool typen= uiTransformBool(token8);
                this->uiUpdateTranzactie(apv, sumav, typev, token5,
                                         apn,suman,typen,token9);
                optiuneGresita = false;

            }

        }
        if (strcmp(token1, "listeaza") == 0)
        {
            if (token4 != NULL)
            {
                cout << "Format comanda gresita!" << endl;
            }
            else
            if (token2 == NULL)
            {
                this->uiShowAll();
                optiuneGresita = false;

            }
            else
            if (token2 != NULL && token3 == NULL)
            {
                int ap = atoi(token2);
                this->uiShowTransaction(ap);
                optiuneGresita = false;
            }
        }
        if (strcmp(token1, "sum") == 0)
        {
            if (token2 == NULL || token3 != NULL)
            {
                cout << "Format comanda gresita!" << endl;
            }
            else
            if (isInt(token2))
            {
                cout << "Format comanda gresita!" << endl;
            }
            else
            {
                this->uiSumByDescr(token2);
                optiuneGresita = false;

            }
        }
        if (strcmp(token1, "max") == 0)
        {
            if (token2 == NULL || token3 != NULL)
            {
                cout << "Format optiune gresita!" << endl;
            }
            else
            {
                int ap = atoi(token2);
                this->uiMaxSum(ap);
                optiuneGresita = false;
            }
        }
        if (strcmp(token1, "sorteaza") == 0)
        {
            if (token2 == NULL || token3 != NULL)
            {
                cout << "Format optiune gresita!" << endl;
            }
            else
            {
                this->uiSortByDescr(token2);
                optiuneGresita = false;
            }
        }
        if (strcmp(token1, "filtru") == 0)
        {
            if (token2 == NULL || token3 != NULL)
            {
                cout << "Format optiune gresita!" << endl;
            }
            else
            if (isInt(token2))
            {
                int sum = atoi(token2);
                this->uiFilterSum(sum);
                optiuneGresita = false;
            }
            else
            {
                this->uiFilterDescr(token2);
                optiuneGresita = false;
            }
        }
        if (strcmp(token1, "iesire") == 0)
        {
            break;
        }
        if (optiuneGresita)
        {
            cout << "Optiune gresita! Reincercati: ";
        }
    }
}

void UI::displayMenu()
{
    cout << "Lista tipuri tranzactii: masina, mancare, pizza, salar." << endl << endl;
    cout << "1.  adauga {zi} {suma} {type} {descr}." << endl;
    cout << "2.  eliminare {zi}." << endl; // nu merge
    cout << "3.  eliminare {zi} la {zi}." << endl;
    cout << "4.  eliminare {descr}." << endl;
    cout << "5.  inlocuire {zi} {descr} cu {suma}." << endl;
    cout << "6.  listeaza." << endl;
    cout << "7.  listeaza {zi}." << endl;
    cout << "8.  sum {descr}." << endl;
    cout << "9. max {numar apartament}." << endl;
    cout << "10. sorteaza {tip}." << endl;
    cout << "11. filtru {tip}." << endl;
    cout << "12. filtru {suma}." << endl; // nu merge
    cout << "13. undo." << endl;
    cout << "14. iesire" << endl;
}

void UI::uiAddCheltuiala(int zi, int suma, bool type, char* descr)
{
    this->service.add(zi, suma, type, descr);
}

void UI::uiUpdateTranzactie(int ziVeche, int sumaVeche, bool typeVechi, char* descrVeche,
                            int ziNoua, int sumaNoua, bool typeNou, char* descrNoua)
{
    this->service.update(ziVeche,sumaVeche,typeVechi, descrVeche,
            ziNoua,sumaNoua,typeNou,descrNoua);
}

void UI::uiDeleteByDay(int zi)
{
    this->service.deleteByDay(zi);
}

void UI::uiDeleteBetweenDays(int zi1, int zi2)
{
    this->service.deleteBetweenDays(zi1, zi2);
}

void UI::uiDeleteByDescr(char* descr)
{
    this->service.deleteByDescr(descr);
}

void UI::uiShowAll()
{
    Transaction v[100];
    int n;
    this->service.getAll(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].getDay() << " " << v[i].getSum() << " " << v[i].getType() << " " << v[i].getDescr() << endl;
    }
    cout << endl;
}

void UI::uiShowTransaction(int zi)
{
    Transaction v[100];
    int n;
    this->service.getAll(v, n);
    for (int i = 0; i < n; i++)
    {
        if (v[i].getDay() == zi)
        {
            cout << v[i].getDay() << " " << v[i].getSum() << " " << v[i].getType() << " " << v[i].getDescr() << endl;
        }
    }
    cout << endl;
}

void UI::uiSumByDescr(char* descr)
{
    cout << this->service.sumByDescr(descr) << endl;
}

void UI::uiMaxSum(int sum)
{
    cout << this->service.maxSum(sum).getDay() << " " << this->service.maxSum(sum).getSum() <<
    " " << this->service.maxSum(sum).getType() << " " << this->service.maxSum(sum).getDescr() << endl;
}

void UI::uiSortByDescr(char* descr)
{
    Transaction v[100];
    int n = 0;
    this->service.sortByDescr(descr, v, n);
    if (n == 0)
    {
        cout << "Nu exista tranzactii cu aceasta descriere!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i].getDay() << " " << v[i].getSum() << " " << v[i].getType() << " " << v[i].getDescr() << endl;
        }
    }
}

void UI::uiFilterDescr(char* descr)
{
    this->service.filterByDescr(descr);
}

void UI::uiFilterSum(int sum)
{
    this->service.filterBySum(sum);
}

bool UI::uiTransformBool(char* input)
{
    if(strcmp(input,"True")==0||strcmp(input,"true")==0)
        return true;
    if(strcmp(input,"False")==0||strcmp(input,"false")==0)
        return false;
}

UI::~UI()
{
}

