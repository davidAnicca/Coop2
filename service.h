//
// Created by david on 08.03.2022.
//

#ifndef LAB2_4_REINCERCARE_SERVICE_H
#define LAB2_4_REINCERCARE_SERVICE_H

#include "repo.h"

typedef struct {
    Repo* repo;
}Service;

Service* create_service();
void destroy_service(Service*);
int srv_add(Service*,char[], int, char[], float);
int type_val(char[]);///validator de tip

#endif //LAB2_4_REINCERCARE_SERVICE_H
