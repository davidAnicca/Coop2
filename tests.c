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
    Repo* repo = create_repo();
    Item* it = create_item("tip", 2, "adresa", 2);
    Item* it2 = create_item("tip", 2, "ad", 2);
    assert(remove_it(repo, it) == 0);
    add(repo, it);
    add(repo, it2);
    assert(remove_it(repo, it) == 1);
    assert(remove_it(repo, it2) == 1);
    assert(repo->vect->size == 0);
    destroy_repo(repo);
}
void mod_item_repo_test(){
    Repo* repo = create_repo();
    Item* item = create_item("casa", 12, "adr", 0);
    Item* alt = create_item("apartament", 120, "adr", 10);
    assert(modify(repo, alt)==0);
    add(repo, item);
    assert(modify(repo, alt)==1);
    assert(repo->vect->items[0]->price == 10);
    assert(repo->vect->items[0]->surface == 120);
    assert(str_equal(repo->vect->items[0]->tip, "apartament"));
    destroy_repo(repo);
}

void add_it_srv_test(){
    Service* srv = create_service();
    assert(srv_add(srv, "a", 1, "a", 0) == -1); ///tip invalid
    assert(srv_add(srv, "casa", 1, "adresa", 0) == 1); ///adaugare ok
    assert(srv_add(srv, "casa", 1, "adresa", 0) == 0); //nu poti adauga existent

    Item* item = create_item("casa", 2, "adresa", 0);
    assert(equal(srv->repo->vect->items[0], item));
    destroy_item(item);

    destroy_service(srv);
}
void del_it_srv_test(){
    Service* srv = create_service();
    assert(srv_del(srv, "adr")==0); ///nu s-a sters

    srv_add(srv, "casa", 1, "adr", 0);
    assert(srv_del(srv, "adr")==1); ///s-a sters

    assert(srv->repo->vect->size==0);
    destroy_service(srv);
}
void mod_it_srv_test(){
    Service* srv = create_service();
    Item* item = create_item("casa", 12, "adr", 0);
    assert(srv_mod_price(srv, "adr", 0)==0);  //nu exista
    assert(srv_mod_surface(srv, "adr", 0)==0); //nu exista
    assert(srv_mod_tip(srv, "adr", "apartament")==0);  //nu exista
    add(srv->repo, item);
    assert(srv_mod_price(srv, "adr", 0)==1);  //ok
    assert(srv->repo->vect->items[0]->price == 0);
    assert(srv_mod_surface(srv, "adr", 0)==1); //ok
    assert(srv->repo->vect->items[0]->surface == 0);
    assert(srv_mod_tip(srv, "adr", "apartament")==1); //ok
    assert(str_equal(srv->repo->vect->items[0]->tip, "apartament"));
    assert(srv_mod_tip(srv, "adr", "ca")==-1); ///tip invalid

    destroy_service(srv);
}

void order_test(){
    Service* srv = create_service();
    Item* item1 = create_item("apartament", 12, "adr", 3);
    Item* item2 = create_item("casa", 12, "adr1", 2);
    Item* item3 = create_item("teren", 12, "adr2", 1);
    Vect* ordonat = price_order(srv);
    assert(ordonat->size==0);


    add(srv->repo, item1);
    add(srv->repo, item2);
    add(srv->repo, item3);
    Vect* ordonat1 = price_order(srv);
    assert(equal(ordonat1->items[0], item3));
    assert(equal(ordonat1->items[1], item2));
    assert(equal(ordonat1->items[2], item1));


    Vect* ordonat2 = type_order(srv);
    assert(equal(ordonat2->items[0], item3));
    assert(equal(ordonat2->items[1], item2));
    assert(equal(ordonat2->items[2], item1));
    destroy_service(srv);
    free(ordonat1->items);
    free(ordonat2->items);
    free(ordonat->items);
    free(ordonat1);
    free(ordonat2);
    free(ordonat);
}

void filter_test(){
    Service* srv = create_service();
    Item* item1 = create_item("apartament", 12, "adr", 3);
    Item* item2 = create_item("casa", 12, "adr1", 2);
    Item* item3 = create_item("teren", 12, "adr2", 1);
    Vect* vect = type_filter(srv, "casa");
    assert(vect->size==0);


    add(srv->repo, item1);
    add(srv->repo, item2);
    add(srv->repo, item3);
    Vect* vect1 = type_filter(srv, "casa");
    assert(vect1->size==1);
    assert(str_equal(vect1->items[0]->tip, "casa"));

    Vect* vect2 = type_filter(srv, "apartament");
    assert(vect2->size==1);
    assert(str_equal(vect2->items[0]->tip, "apartament"));

    Vect* vect3 = type_filter(srv, "teren");
    assert(vect3->size==1);
    assert(str_equal(vect3->items[0]->tip, "teren"));

    Vect* vect4 = type_filter(srv, "a");
    assert(vect4->size==0);

    destroy_service(srv);
    free(vect1->items);
    free(vect2->items);
    free(vect->items);
    free(vect3->items);
    free(vect4->items);
    free(vect1);
    free(vect2);
    free(vect);
    free(vect3);
    free(vect4);
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

    order_test();
    filter_test();
    printf("tests done");
}

