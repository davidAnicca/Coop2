//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_REPO_H
#define LAB2_4_REINCERCARE_REPO_H

#include "vect.h"

typedef struct {
    Vect* vect;
}Repo;
/*
 * adăugare in repo
 * returnează 1 dacă s-a adăugat 0 altfel
 */
int add(Repo*, Item*);
/*
 * sterge din repo
 * returneaza 1 daca s-a sters 0 dacă nu există
 */
int remove_it(Repo*, Item*);
/*
 * modifica itemul trimis.
 * returneaza 1 daca s-a modificat
 *          0 dacă nu există
 *          -1 eroare de validare
 */
int modify(Repo*, Item*);
/*
 * caută itemul în repo
 * returnează itemul sau NULL dacă el nu există
 */
Item* find(Repo*, Item*);

/*
 * constructor de repo
 */
Repo* create_repo();
/*
 * destructor de repo
 */
void destroy_repo();

#endif //LAB2_4_REINCERCARE_REPO_H
