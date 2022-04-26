#include "Repo.h"
Repo::Repo()
{
    this->nr=0;
}
Repo::~Repo()
{
}
void Repo::addItem(const Transaction &n)
{
    if(this->nr==100)
        return;
    this->elements[this->nr]=n;
    this->nr++;
}

int Repo::size()
{return this->nr;
}

Transaction *Repo::getAll() {
    return this->elements;

}

void Repo::delItem(Transaction &t) {
    for (int i = 0; i < this->nr; i++)
    {
        if (this->elements[i] == t)
        {
            for (int j = i; j < this->nr - 1; j++)
                this->elements[j] = this->elements[j + 1];
            this->nr--;
        }
    }
}

void Repo::updateItem(Transaction &tV, Transaction &tN) {
    for (int i = 0; i < this->nr; i++)
    {
        if (this->elements[i] == tV)
        {
            this->elements[i] = tN;
            break;
        }
    }

}

void Repo::findAll(Transaction *t, int &n) {
    for (int i = 0; i < this->nr; i++)
        t[i] = this->elements[i];
    n = this->nr;
}






