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


#endif //LAB2_4_REINCERCARE_SERVICE_H
