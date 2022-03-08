//
// Created by david on 08.03.2022.
//
#include "service.h"
#include "malloc.h"
#include "mystrings.h"

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

