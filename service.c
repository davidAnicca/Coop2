//
// Created by david on 08.03.2022.
//
#include "service.h"
#include "malloc.h"
#include "mystrings.h"
#include <stdio.h>
#include <string.h>

Service* create_service(){
    Repo* repo = create_repo();
    Service* service = (Service*)malloc(sizeof(service));
    service->repo=repo;
    return service;
}

void destroy_service(Service* service){
    free(service->repo->vect);
    free(service->repo);
    free(service);
}

int type_val(char type[]){
    return str_equal(type, "casa") || str_equal(type, "apartament") || str_equal(type, "teren");
}

int srv_add(Service* srv, char tip[], int surface, char address[], float price){
    if(!type_val(tip))
        return -1;
    Item* item = create_item(tip, surface, address, price);
    if(add(srv->repo, item)){
        return 1;
    }else{
        return 0;
        destroy_item(item);
    }
}

int srv_del(Service* srv, char address[]){
    return remove_it(srv->repo, create_item("casa", 1, address, 0));
}

int srv_mod_tip(Service* srv, char address[], char tip[]){
    if(!type_val(tip))return -1;
    Item *it = create_item(tip, 0, address, 0);
    Item *found = find(srv->repo, it);
    if(found == NULL)return 0;
    set_price(it, found->price);
    set_surface(it, found->price);
    return modify(srv->repo, it);
}

int srv_mod_surface(Service* srv, char address[], int surface){
    Item *it = create_item("casa", surface, address, 0);
    Item *found = find(srv->repo, it);
    if(found == NULL)return 0;
    set_price(it, found->price);
    set_tip(it, found->tip);
    return modify(srv->repo, it);
}

int srv_mod_price(Service* srv, char address[], float price){
    Item *it = create_item("casa", 0, address, price);
    Item *found = find(srv->repo, it);
    if(found == NULL)return 0;
    set_surface(it, found->surface);
    set_tip(it, found->tip);
    return modify(srv->repo, it);
}

int cmpprice(Item* item1, Item* item2){
    return item1->price > item2->price;
}

int cmptype(Item* item1, Item* item2){
    return strcmp(item1->tip, item2->tip) < 0;
}

Vect* price_order(Service* service){
    Vect* list = create_vect();
    list->size = service->repo->vect->size;
    for(int i = 0; i < service->repo->vect->size; i++){
        list->items[i] = service->repo->vect->items[i];
    }
    int ordered = 0;
    while(!ordered){
        ordered = 1;
        for(int i = 0; i < list->size-1; i++){
            if(cmpprice(list->items[i], list->items[i+1])){
                Item* item = list->items[i];
                list->items[i] = list->items[i+1];
                list->items[i+1] = item;
                ordered = 0;
            }
        }
    }
    return list;
}

Vect* type_order(Service* service){
    Vect* list = create_vect();
    list->size = service->repo->vect->size;
    for(int i = 0; i < service->repo->vect->size; i++){
        list->items[i] = service->repo->vect->items[i];
    }
    int ordered = 0;
    while(!ordered){
        ordered = 1;
        for(int i = 0; i < list->size-1; i++){
            if(cmptype(list->items[i], list->items[i+1])){
                Item* item = list->items[i];
                list->items[i] = list->items[i+1];
                list->items[i+1] = item;
                ordered = 0;
            }
        }
    }
    return list;
}

