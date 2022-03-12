//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_VECT_H
#define LAB2_4_REINCERCARE_VECT_H

#include "entitie.h"

typedef struct {
    Item** items;
    int size;
    int capacity;
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
/*
 * dublare capacitate
 */
void redim_up(Vect*);
/*
 * înjumătățire capacitate
 */
void redim_down(Vect*);


#endif //LAB2_4_REINCERCARE_VECT_H
