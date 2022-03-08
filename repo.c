//
// Created by david on 08.03.2022.
//
#include "malloc.h"
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

void destroy_repo(Repo* repo){
    free(repo->vect);
    free(repo);
}
