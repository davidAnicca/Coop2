//
// Created by david on 08.03.2022.
//
#include "vect.h"
#include "entitie.h"
#include "malloc.h"
#include <stdio.h>

Elem get(Vect* vect, int i){
    return vect->items[i];
}

Vect* create_vect(){

    Elem* items = (Elem*) malloc(40*sizeof(Elem));
    Vect* vect = (Vect*) malloc(sizeof(Vect));
    vect->items = items;
    vect->size=0;
    vect->capacity = 40;
    return vect;
}

void redim_up(Vect* vect){
    Elem* items = (Elem*) malloc((2*(vect->capacity))*sizeof(Elem));
    for(int i = 0; i < vect->size; i++)
        items[i] = vect->items[i];
    free(vect->items);
    vect->capacity *= 2;
    vect->items = items;
}

void redim_down(Vect* vect){
    if(vect->capacity < 3 )return;
    Elem* items = (Elem*) malloc(((vect->capacity)/2)*sizeof(Elem));
    for(int i = 0; i < vect->size; i++)
        items[i] = vect->items[i];
    free(vect->items);
    vect->capacity /= 2;
    vect->items = items;
}

void add_to_vect(Vect* vect, Elem item){
    if(vect->size + 1 > vect->capacity)
        redim_up(vect);
    vect->items[vect->size] = item;
    vect->size++;
}

void remove_from_vect(Vect* vect, Elem item, void (*destructor)(Elem)){
    for(int i = 0; i < vect->size; i++){
        if(item == vect->items[i]){
            destructor(vect->items[i]);
            for(int j = i; j < (vect->size)-1; j++)
                vect->items[j] = vect->items[j+1];
            vect->size--;
            if(vect->size < (vect->capacity)/2)
                redim_down(vect);
            return;
        }
    }
}



void destroy_vector(Vect* vect, void (*destructor)(Elem)){
    for(int i = 0; i < vect->size; i++)
        destructor(vect->items[i]);
    free(vect->items);
    free(vect);
}