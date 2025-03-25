#include "header/stack.h"

int main() {
    infotype isi;
    List MyList;

    CreateList (&MyList);

    printf("Masukkan angka desimal : ");
    scanf("%d", &isi);

    if (isi < 0) {
        printf("Bilangan harus positif!\n");
    } else {
        KonversiDesimalBiner(isi);
    }

    return 0;
}