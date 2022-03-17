//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_VECT_H
#define LAB2_4_REINCERCARE_VECT_H

#include "entitie.h"

typedef void* Elem;

typedef struct {
    Elem* items;
    int size;
    int capacity;
}Vect;
/*
 * dă de la index
 */
Elem get(Vect*, int);
/*
 * constructor
 */
Vect* create_vect();

/*
 * adăugare în vector
 */
void add_to_vect(Vect*,Elem);
/*
 * stergere din vector
 */
void remove_from_vect(Vect*, Elem, void (*destructor)(Elem));

/*
 * destructor
 */
void destroy_vector(Vect*, void (*destructor)(Elem));
/*
 * dublare capacitate
 */
void redim_up(Vect*);
/*
 * înjumătățire capacitate
 */
void redim_down(Vect*);


#endif //LAB2_4_REINCERCARE_VECT_H
