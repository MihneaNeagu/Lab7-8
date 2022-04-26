#include "Operations.h"
#include "Repo.h"
void filtreazaTranzactii(Repo repo, const char* descr, int suma, Transaction rezultat[], int& lenRezultat)
{
    lenRezultat = 0;
    Transaction* tranzactii = repo.getAll();
    for (int i = 0; i < repo.size(); i++)
    {
        if (strstr(tranzactii[i].getDescr(), descr) != NULL && tranzactii[i].getSum() > suma)
        {
            rezultat[lenRezultat] = tranzactii[i];
            lenRezultat++;
        }
    }
}

