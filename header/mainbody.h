#ifndef MAINBODY_H
#define MAINBODY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef address List;


void Create_Node(address *p, infotype X);

void DeAlokasi(address *p);

bool isEmpty(List L);

void PrintList(List L);

void InsVFirst(List *L, infotype X);
void InsertFirst(List *L, address P);

void DelVFirst(List *L, infotype *X);
void DelFirst(List *L, address *P);

#endif
