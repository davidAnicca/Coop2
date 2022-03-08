//
// Created by david on 08.03.2022.
//
#include "entitie.h"
#include "mystrings.h"
#include "repo.h"
#include "service.h"
#include "malloc.h"
#include <stdio.h>
#include <assert.h>

void create_item_test(){
    Item* it = create_item("tip", 3, "adresa", 2);
    assert(it != NULL);
    assert(str_equal((*it).tip, "tip"));
    assert(str_equal((*it).address, "adresa"));
    assert((*it).price == 2);
    assert((*it).surface == 3);
    destroy_item(it);
}

void destroy_item_test(){
    Item* it = create_item("tip", 3, "adresa", 2);
    destroy_item(it);
}
void add_item_repo_test(){
    Repo* repo = create_repo();
    Item* it = create_item("tip", 3, "adresa", 2);
    assert(add(repo, it) == 1);
    assert(add(repo, it) == 0);
    assert(equal(repo->vect->items[0], it));
    destroy_repo(repo);
}
void del_item_repo_test(){

}
void mod_item_repo_test(){

}

void add_it_srv_test(){
    Service* srv = create_service();
    assert(srv_add(srv, "a", 1, "a", 0) == -1); ///tip invalid
    assert(srv_add(srv, "casa", 1, "adresa", 0) == 1); ///adaugare ok
    assert(srv_add(srv, "casa", 1, "adresa", 0) == 0); //nu poti adauga existent
    Item* item = create_item("casa", 1, "adresa", 0);
    assert(equal(srv->repo->vect->items[0], item));
}
void del_it_srv_test(){

}
void mod_it_srv_test(){

}

void run_all_tests(){
    create_item_test();
    destroy_item_test();
    add_item_repo_test();
    del_item_repo_test();
    mod_item_repo_test();
    add_it_srv_test();
    del_it_srv_test();
    mod_it_srv_test();

    printf("tests done");
}

