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
    printf("3. sterge\n");
    printf("4. modificare\n");
    printf("5. ordonare dupa pret  6. ordonare dupa tip\n");
    printf("7. categorii\n");


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

void del_c(Console* console){
    printf("\n\n<<<STERGERE>>>\n\n");
    printf("adresa>>");
    char adr[10];
    scanf("%s", adr);
    if(srv_del(console->srv, adr)){
        printf("<<s-a sters cu succes\n");
    }else{
        printf("<<adresa nu a fost gasita\n");
    }
}

void mod_c(Console* console){
    printf("1. Modifica pret || 2. Modifica suprafata || 3. Modifica tipul\n>>>");
    char buffer[10];
    scanf("%s", buffer);
    int opt = str_to_int(buffer);
    if(opt < 1 || opt > 3){
        printf("optiune invalida\n");
        return;
    }
    if(opt == 1)mod_price_c(console);
    if(opt == 2)mod_surface_c(console);
    if(opt == 3)mod_tip_c(console);
}

void mod_price_c(Console* console){
    printf("<<<MODIFICARE PRET>>>\n");
    printf("adresa>>");
    char adr[10];
    scanf("%s", adr);
    printf("pret>>");
    char buffer[10];
    scanf("%s", buffer);
    int pret = str_to_int(buffer);
    if(pret == -1){
        printf("<<trebuie introdus un numar\n");
        return;
    }
    if(srv_mod_price(console->srv, adr, (float)pret)){
        printf("<<s-a modificat cu succes\n");
    }else{
        printf("<<adresa nu a putut fi gasita\n");
    }
}

void mod_surface_c(Console* console){
    printf("<<<MODIFICARE SUPRAFATA>>>\n");
    printf("adresa>>");
    char adr[10];
    scanf("%s", adr);
    printf("suprafata>>");
    char buffer[10];
    scanf("%s", buffer);
    int surface = str_to_int(buffer);
    if(surface == -1){
        printf("<<trebuie introdus un numar\n");
        return;
    }
    if(srv_mod_surface(console->srv, adr, surface)){
        printf("<<s-a modificat cu succes\n");
    }else{
        printf("<<adresa nu a putut fi gasita\n");
    }
}

void mod_tip_c(Console* console){
    printf("<<<MODIFICARE TIP>>>\n");
    printf("adresa>>");
    char adr[10];
    scanf("%s", adr);
    printf("tip>>");
    char tip[11];
    scanf("%s", tip);
    int rez = srv_mod_tip(console->srv, adr, tip);
    if(rez == -1)printf("<<tip invalid\n");
    if(rez == 1)printf("<<modificat cu succes\n");
    if(rez == 0)printf("<<adresa nu a putut fi gasita\n");
}

void price_ord_c(Console *c){
    Vect* ordered = price_order(c->srv);
    if(ordered->size==0){
        printf("<<<gol>>>");
        return;
    }
    for(int i = 0; i < ordered->size; i++){
        printf("<<tip: %s || suprafata: %d || adresa: %s || pret: %.2f\n",
               ordered->items[i]->tip,
               ordered->items[i]->surface,
               ordered->items[i]->address,
               ordered->items[i]->price);
    }
    destroy_vector(ordered);
}

void type_ord_c(Console *c){
    Vect* ordered = type_order(c->srv);
    if(ordered->size==0){
        printf("<<<gol>>>");
        return;
    }
    for(int i = 0; i < ordered->size; i++){
        printf("<<tip: %s || suprafata: %d || adresa: %s || pret: %.2f\n",
               ordered->items[i]->tip,
               ordered->items[i]->surface,
               ordered->items[i]->address,
               ordered->items[i]->price);
    }
    free(ordered->items);
    free(ordered);
}
void type_filter_c(Console *c){
    printf("<<<CATEGORII>>>\n");
    printf("1. Terenuri ||| 2. Case ||| 3. Apartamente\n>>>");
    char buff[10];
    scanf("%s", buff);
    int opt = str_to_int(buff);
    if(opt < 1 || opt > 3){
        printf("<<<comanda invalida\n");
        return;
    }
    Vect* rezultat;
    if(opt == 1)rezultat = type_filter(c->srv, "teren");
    if(opt == 2)rezultat = type_filter(c->srv, "casa");
    if(opt == 3)rezultat = type_filter(c->srv, "apartament");
    for(int i = 0; i < rezultat->size; i++){
        printf("<<tip: %s || suprafata: %d || adresa: %s || pret: %.2f\n",
               rezultat->items[i]->tip,
               rezultat->items[i]->surface,
               rezultat->items[i]->address,
               rezultat->items[i]->price);
    }
    free(rezultat->items);
    free(rezultat);
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
            case 3:
                del_c(cons);
                break;
            case 4:
                mod_c(cons);
                break;
            case 5:
                price_ord_c(cons);
                break;
            case 6:
                type_ord_c(cons);
                break;
            case 7:
                type_filter_c(cons);
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


