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
/*
 * stergere item
 */
void del_c(Console*);
/*
 * submeniu modifica
 */
void mod_c(Console*);
/*
 * modifica suprafata
 */
void mod_surface_c(Console*);
/*
 * modifica tipul
 */
void mod_tip_c(Console *c);
/*
 * modifica pretul
 */
void mod_price_c(Console *c);
/*
 * ordoneaza crescator dupa pret
 */
void price_ord_c(Console *c);
/*
 * ordonează descrescator dupa tip
 */
void type_ord_c(Console *c);
/*
 * filtrare dupa tip
 */
void type_filter_c(Console *c);

#endif //LAB2_4_REINCERCARE_CONS_H
