#include <iostream>
#include "Repo.h"
#include "Service.h"
#include "UI.h"
#include "tests.h"
using namespace std;

int main()
{
    tests_Transactions();
    tests_Repo();
    tests_Filtreaza();
    tests_Service();
    cout<<"Tests are working";
    Repo repo;
    Service service;
    UI ui;
    ui.runMenu();
    return 0;
}