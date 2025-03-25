#ifndef mainbody_H
#define mainbody_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
} ElmtList;

typedef struct {
	  address First;
} List;


boolean ListEmpty (List L);

void CreateList (List * L);

address Alokasi (infotype X);

void DeAlokasi (address P);

address Search (List L, infotype X);

boolean FSearch (List L, address P);

address SearchPrec (List L, infotype X);

void InsVFirst (List * L, infotype X);

void InsVLast (List * L, infotype X);

void DelVFirst (List * L, infotype * X);

void DelVLast (List * L, infotype * X);

void InsertFirst (List * L, address P);

void InsertAfter (List * L, address P, address Prec);

void InsertLast (List * L, address P);

void DelFirst (List * L, address * P);

void DelP (List * L, infotype X);

void DelLast (List * L, address * P);

void DelAfter (List * L, address * Pdel, address Prec);

void PrintInfo (List L);

void DelAll (List * L);

void DelGanjil(List * L);

#endif
