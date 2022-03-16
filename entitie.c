//
// Created by david on 08.03.2022.
//
#include <stdio.h>
#include "malloc.h"
#include <string.h>
#include "entitie.h"

Item* create_item(char tip[], int surface, char address[], float price){
    Item* item = (Item*)malloc(sizeof(Item));
    set_tip(item, tip);
    set_address(item, address);
    set_surface(item, surface);
    set_price(item, price);
    return item;
}

void set_tip(Item* item, char tip[]){
    strcpy((*item).tip, tip);
}

void set_address(Item* item, char address[]){
    strcpy((*item).address, address);
}

void set_price(Item* item, float price){
    (*item).price = price;
}

void set_surface(Item* item, int surface){
    (*item).surface = surface;
}

int equal(Item* a, Item* b){
    return strcmp(a->address, b->address) == 0;
}


void destroy_item(Item* it){
    ///free(it);
}
