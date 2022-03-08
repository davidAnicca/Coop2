//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_CONS_H
#define LAB2_4_REINCERCARE_CONS_H

#include "service.h"

typedef struct {
    Service* srv;
}Console;

/*
 * rulează consola. returnează referința la consola care va urma a fi distrusă
 */
Console* run();
/*
 * oprirea consolei. eliberează memoria
 */
void end_cons(Console*);
/*
 * afișează meniul
 */
void menu();
/*
 * transformă un sir de caractere în număr
 * returnează numărul dacă acesta s-a putut forma
 * returnează -1 dacă sirul de caractere nu se poate transforma în număr
 */
int str_to_int(char[]);

/*
 * afisarea tuturor itemilor
 */
void show_all(Console*);
/*
 * adăugare item
 */
void add_c(Console*);

#endif //LAB2_4_REINCERCARE_CONS_H
