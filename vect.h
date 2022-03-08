//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_VECT_H
#define LAB2_4_REINCERCARE_VECT_H

#include "entitie.h"

typedef struct {
    Item* items[100];
    int size;
}Vect;

/*
 * constructor
 */
Vect* create_vect();

/*
 * adăugare în vector
 */
void add_to_vect(Vect*,Item*);
/*
 * stergere din vector
 */
void remove_from_vect(Vect*, Item*);
/*
 * căutare în vector
 * returnează instanța corectă sau NULL dacă nu există
 */
Item* find_in_vect(Vect*, Item*);
/*
 * destructor
 */
void destroy_vector(Vect*);


#endif //LAB2_4_REINCERCARE_VECT_H
