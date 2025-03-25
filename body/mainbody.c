#include "../header/mainbody.h"

void BuatNode(address *p, infotype X) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = X;
        (*p)->next = NULL;
    } else {
        printf("Alokasi memori gagal!\n");
    }
}

bool isEmpty(List L) {
    return (L == NULL);
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

void PrintList(List L) {
    address temp = L;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void InsVFirst(List *L, infotype X) {
    address P;
    BuatNode(&P, X);
    if (P != NULL) {
        InsertFirst(L, P);
    }
}

void InsertFirst(List *L, address P) {
    P->next = *L;
    *L = P;
}

void DelVFirst(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        DelFirst(L, &P);
        *X = P->info;
        DeAlokasi(&P);
    }
}

void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = *L;
        *L = (*P)->next;
        (*P)->next = NULL;
    }
}
