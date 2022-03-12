//
// Created by david on 08.03.2022.
//
#include "vect.h"
#include "entitie.h"
#include "malloc.h"
#include <stdio.h>

Vect* create_vect(){
    Vect* vect;
    Item** items = (Item**) malloc(10*sizeof(Item*));
    vect = (Vect*) malloc(sizeof(Vect));
    vect->items = items;
    vect->size=0;
    vect->capacity = 10;
    return vect;
}

void redim_up(Vect* vect){
    Item** items = (Item**) malloc((2*vect->capacity)*sizeof(Item*));
    for(int i = 0; i < vect->size; i++)
        items[i] = vect->items[i];
    free(vect->items);
    vect->capacity *= 2;
    vect->items = items;
}

void redim_down(Vect* vect){
    Item** items = (Item**) malloc(((vect->capacity)/2)*sizeof(Item*));
    for(int i = 0; i < vect->size; i++)
        items[i] = vect->items[i];
    free(vect->items);
    vect->capacity /= 2;
    vect->items = items;
}

void add_to_vect(Vect* vect, Item* item){
    if(vect->size + 1 > vect->capacity)
        redim_up(vect);
    vect->items[vect->size] = item;
    vect->size++;
}

void remove_from_vect(Vect* vect, Item* item){
    for(int i = 0; i < vect->size; i++){
        if(equal(item, vect->items[i])){
            for(int j = i; j < vect->size-1; j++)
                vect->items[i] = vect->items[i+1];
            vect->size--;
            if(vect->size < vect->capacity)
                redim_down(vect);
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

void destroy_vector(Vect* vect){
    free(vect->items);
    free(vect);
}