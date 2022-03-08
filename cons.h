//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_CONS_H
#define LAB2_4_REINCERCARE_CONS_H

#include "service.h"

typedef struct {
    Service* srv;
}Console;

Console* run();
void end_cons(Console*);

void show_all(Console*);
void add_c(Console*);

#endif //LAB2_4_REINCERCARE_CONS_H
