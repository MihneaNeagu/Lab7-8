# Lab7-8

Să se rezolve una dintre problemele de mai jos:
Lab 7:
 LIVE:
o implementat clasa entitate cu un singur atribut & teste (2p)

o implementare clasa Repo (doar constructorii, destructorul si metodele addElem,
getAll, getSize) & teste (3p)

 TEMA (predare în Lab 8)
o dezvoltarea completă a entității și metodelor din Repo & teste complete (5p)
Precizari:

 clasa entitate va folosi char* pentru atributul de tip sir de caractere (ex. char* nume)

 clasa repo va folosi un array de entitati (alocat static sau dinamic)

 in clase se vor implementa toate tipurile de constructori, destructorul, setteri, getteri,
operator= (si, optional, alte metode si operatori)

Lab 8:
 - LIVE:
o implementare clasa Service (operatii CRUD) (2p) si teste aferente (1p)

 - TEMA (predare în Lab 9):
o implementare clasa UI (2p)

o functionalitati propriu-zise (in plus fata de CRUD) (3p)

o restul de teste pt Service (1p)

o undo (1p) 

Problema 2:

2. Gestiune conturi bancare
John vrea să-și gestioneze conturile bancare și are nevoie de o aplicație care să-i
permită stocarea și vizualizarea tranzacțiilor bancare efectuate în contul său în timpul
unei luni calendaristice. Fiecare tranzacție este identificată prin: ziua din lună când a
fost efectuată (întreg între 1 și 28/29/30/31), suma de bani (întreg pozitiv), tip (in - au
intrat bani în cont - sau out - au ieșit bani din cont) și descriere. Creați o aplicație care să-l ajute pe John oferindu-i următoarele funcționalități:

 adăugarea unei tranzacții în lista de tranzacții

o ex. adaugă 100 out pizza - este adăugată o tranzație de tip out în valoarea de
100 RON pentru ziua curentă cu descrierea ”pizza”

o ex. inserează 25 100 in salar - inserează o tranzacție de tip in pentru ziua 25 în
valaorea de 100 RON cu descrierea salar

 modificarea tranzacțiilor din listă

o ex. eliminare 15 - se elimină toate tranzacțiile din ziua 15

o ex. eliminare 5 la 10 - se elimină toate tranzacțiile din ziua 10 până în ziua 15

o ex. eliminare in - se elimină toate tranzacțiile de tip in din luna curentă

o ex. înlocuire 12 in salar cu 2000 - se înlocuiește suma vechea tranzacției de tip
in din ziua 12 cu descrierea ”salar” cu suma 2000

 identificarea tranzacțiilor cu anumite proprietăți

o ex. listează - afișează toate tranzacțiile din listă

o ex. listează in - afișează toate tranzacțiile de tip in din listă

o ex. listează > 100 - afișează toate tranzacțiile din listă cu suma mai mare decât
100

o ex. listează = 60 - afișează toate tranzacțiile din listă cu suma egală cu 60

o ex. listează sol 10 - afișează sold-ul tranzacțiilor din ziua 10 (diferența între
suma tranzacțiilor de tip in și suma tranzacțiilor de tip out)

 obținerea unor caracteristici ale tranzacțiilor

o ex. sum in - afișează suma totală a tranzacțiilor de tip in

o ex. max out 15 - afișează cea mai valoroasă tranzacție de tip out din ziua 15
 filtrări

o ex. filtru in - se păstrează doar tranzacțiile de tip in

o ex. filtru in 100 - se păstrează doar tranzacțiile de tip in cu valoare mai mică
decât 100

 undo - reface ultima operație. Aplicația trebuie să permită revenirea (prin undo) l
starea inițială. 

