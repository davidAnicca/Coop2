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

Vect* create_vect();
void add_to_vect(Vect*,Item*);
void remove_from_vect(Vect*, Item*);
Item* find_in_vect(Vect*, Item*);


#endif //LAB2_4_REINCERCARE_VECT_H
