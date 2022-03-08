//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_REPO_H
#define LAB2_4_REINCERCARE_REPO_H

#include "vect.h"

typedef struct {
    Vect* vect;
}Repo;

int add(Repo*, Item*);
int remove_it(Repo*, Item*);
int modify(Repo*, Item*);
Item* find(Repo*, Item*);

Repo* create_repo();
void destroy_repo();

#endif //LAB2_4_REINCERCARE_REPO_H
