//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_SERVICE_H
#define LAB2_4_REINCERCARE_SERVICE_H

#include "repo.h"

typedef struct {
    Repo* repo;
}Service;

/*
 * constructor de srv
 */
Service* create_service();
/*
 * destructor de srv
 */
void destroy_service(Service*);

/*
 * adăugare în baza itemilor |tip|suprafata|adresa|pret|
 * returnează 1 dacă s-a adăugat
 * 0 dacă există deja
 * -1 eroare de validare
 */
int srv_add(Service*,char[], int, char[], float);
/*
 * validează tipul
 * returneaza 1 pentru tip valid 0 invalid
 */
int type_val(char[]);///validator de tip
/*
 * sterge un item pe baza adresei sale
 */
int srv_del(Service*, char[]);
/*
 * modifica tipul (service, adresa, tip_nou)
 * returneaza 1 daca s-a modificat
 * 0 dacă nu exista
 * -1 tip cresit
 */
int srv_mod_tip(Service*, char[], char[]);
/*
 * modifica suprafata (service, adresa, suprafata_noua)
 * returneaza 1 daca s-a modificat
 * 0 altfel (nu exista)
 */
int srv_mod_surface(Service*, char[], int);
/*
 * modifica pretul (service, adresa, pret-nou)
 * returneaza 1 dacă s-a modificat
 * 0 altfel (nu exista)
 */
int srv_mod_price(Service*, char[], float);
/*
 * ordonează crescător după pret
 * returnează o listă
 */
Vect* price_order(Service*);
/*
 * ordonează descrescător după tip
 * returnează o listă
 */
Vect* type_order(Service*);
/*
 * compară pretul a doi itemi.
 * returneaza 1 daca item1.pret > item2.pret
 * 0 altfel
 */
int cmpprice(Item*, Item*);
/*
 * compara tipul
 * 1 daca item1.tip < item2.tip
 * 0 altfel
 */
int cmptype(Item*, Item*);
/*
 * filtrare după tip
 * returnează o lista
 */
Vect* type_filter(Service*);
#endif //LAB2_4_REINCERCARE_SERVICE_H
