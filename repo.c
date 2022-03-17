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

int add(Repo* repo, Item* item){
    Item* found = find_in_vect(repo->vect, item);
    if(found != NULL)
        return 0;
    add_to_vect(repo->vect, item);
    return 1;
}

int remove_it(Repo* repo, Item* item){
    Item* found = find_in_vect(repo->vect, item);
    if(found == NULL)
        return 0;
    remove_from_vect(repo->vect, item);
    return 1;
}

int modify(Repo* repo, Item* item){
    Item* found = find_in_vect(repo->vect, item);
    if(found == NULL)
        return 0;
    *found = *item;
    free(item);
    return 1;
}

Item* find(Repo* repo, Item* item){
    return find_in_vect(repo->vect, item);
}

void destroy_repo(Repo* repo){
    destroy_vector(repo->vect);
    free(repo);
}
