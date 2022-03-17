//
// Created by david on 08.03.2022.
//
#include <malloc.h>
#include <stdio.h>
#include "repo.h"

Repo* create_repo(){
    Repo* repo = (Repo*) malloc(sizeof(repo));
    repo->vect = create_vect();
    return repo;
}

Item* find_in_vect(Repo* repo, Item* item){
    for(int i = 0; i < repo->vect->size; i++){
        if(equal(item, get(repo->vect, i)))
            return get(repo->vect, i);
    }
    return NULL;
}

int add(Repo* repo, Item* item){
    Item* found = find_in_vect(repo, item);
    if(found != NULL)
        return 0;
    add_to_vect(repo->vect, item);
    return 1;
}

int remove_it(Repo* repo, Item* item){
    Item* found = find_in_vect(repo, item);
    if(found == NULL)
        return 0;
    remove_from_vect(repo->vect, found, (void (*)(Elem)) destroy_item);
    return 1;
}

int modify(Repo* repo, Item* item){
    Item* found = find_in_vect(repo, item);
    if(found == NULL)
        return 0;
    *found = *item;
    free(item);
    return 1;
}

Item* find(Repo* repo, Item* item){
    return find_in_vect(repo, item);
}

void destroy_repo(Repo* repo){
    destroy_vector(repo->vect, (void (*)(Elem)) destroy_item);
    free(repo);
}
