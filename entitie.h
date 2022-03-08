//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_ENTITIE_H
#define LAB2_4_REINCERCARE_ENTITIE_H

typedef struct{
    char tip[11];
    ///(teren, casa, apartament)
    int surface;
    char address[100];
    float price;
}Item;

/*
 * creează un item cu tip, suprafata, adresa si pret
 */
Item* create_item(char tip[], int surface, char address[], float price);
void destroy_item(Item*);

/*
 * seteaza tipul unui item
 */
void set_tip(Item*, char[]);
/*
 * seteaza suprafata unui item
 */
void set_surface(Item*, int);
/*
 * seteaza adresa unui item
 */
void set_address(Item*, char[]);
/*
 * seteaza pretul unui item
 */
void set_price(Item*, float);

/*
 * verifică daca doi itemi sunt egali
 */
int equal(Item*, Item*);

#endif //LAB2_4_REINCERCARE_ENTITIE_H
