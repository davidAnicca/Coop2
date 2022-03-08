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

Item* create_item(char tip[], int surface, char address[], float price);
void destroy_item(Item*);

void set_tip(Item*, char[]);
void set_surface(Item*, int);
void set_address(Item*, char[]);
void set_price(Item*, float);

int equal(Item*, Item*);

#endif //LAB2_4_REINCERCARE_ENTITIE_H
