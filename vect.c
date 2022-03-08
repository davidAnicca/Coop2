//
// Created by david on 08.03.2022.
//
#include "vect.h"
#include "entitie.h"
#include "malloc.h"
#include <stdio.h>

Vect* create_vect(){
    Vect* vect;
    vect = (Vect*) malloc(sizeof(Vect));
    vect->size=0;
    return vect;
}

void add_to_vect(Vect* vect, Item* item){
    vect->items[vect->size] = item;
    vect->size++;
}

void remove_from_vect(Vect* vect, Item* item){
    for(int i = 0; i < vect->size; i++){
        if(equal(item, vect->items[i])){
            for(int j = i; j < vect->size-1; j++)
                vect->items[i] = vect->items[i+1];
            return;
        }
    }
}

Item* find_in_vect(Vect* vect, Item* item){
    for(int i = 0; i < vect->size; i++){
        if(equal(item, vect->items[i]))
            return vect->items[i];
    }
    return NULL;
}