//
// Created by david on 08.03.2022.
//

#include "cons.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

void menu(){
    printf("\n\n1. adauga\n");
    printf("2. vezi lista\n");

    printf("0. iesire\n");
}

int str_to_int(char opt[]){
    if(strlen(opt) == 0)
        return -2;
    int nr = 0;
    for(int i = 0; i < strlen(opt); i++) {
        if (opt[i] < '0' || opt[i] > '9')
            return -1;
        nr = nr*10 + (opt[i]-'0');
    }
    return nr;
}

void add_c(Console* console){
    printf("\n<<<ADAUGARE>>>\n");

    printf("tip>>");
    char tip[10];
    scanf("%s", tip);

    printf("suprafata>>");
    int surface;
    char buffer[10];
    scanf("%s", buffer);
    surface = str_to_int(buffer);
    if(surface == -1){
        printf("<<trebuie introdus un numar\n");
        return;
    }

    printf("adresa>>");
    char address[100];
    scanf("%s",address);

    printf("pretul>>");
    scanf("%s", buffer);
    int pret = str_to_int(buffer);
    if(pret == -1){
        printf("<<trebuie introdus un numar\n");
        return;
    }
    int rezultat = srv_add(console->srv, tip, surface, address, (float)pret);
    if(rezultat == -1){
        printf("<<tipul trebuie să fie unul dintre: casa | apartament | teren\n");
    }else if(rezultat == 0){
        printf("<<oferta exista deja in lista\n");
    }else{
        printf("<<s-a adaugat cu succes\n");
    }
}

void show_all(Console* console){
    if(console->srv->repo->vect->size == 0){
        printf("<<<gol>>>\n");
        return;
    }
    for(int i = 0; i < console->srv->repo->vect->size; i++){
        printf("<<tip: %s || suprafata: %d || adresa: %s || pret: %.2f\n",
               console->srv->repo->vect->items[i]->tip,
               console->srv->repo->vect->items[i]->surface,
               console->srv->repo->vect->items[i]->address,
               console->srv->repo->vect->items[i]->price);
    }
}



Console* run(){
    Console* cons = (Console*)malloc(sizeof(Console));
    cons->srv = create_service();
    while(1){
        menu();
        char opt[10];
        printf(">>>");
        scanf("%s", opt);
        int num_opt = str_to_int(opt);
        switch (num_opt) {
            case -2:
                break;
            case -1:
                printf("<<comanda invalidas\n");
                break;
            case 0:
                return cons;
            case 1:
                add_c(cons);
                break;
            case 2:
                show_all(cons);
                break;
            default:
                printf("<<comanda invalida\n");
        }
    }
}

void end_cons(Console* console){
    destroy_service(console->srv);
    free(console);
}


