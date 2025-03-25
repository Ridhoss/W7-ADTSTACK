#include "header/stack.h"

int main() {
    infotype isi;

    printf("Masukkan angka desimal : ");
    scanf("%d", &isi);

    if (isi < 0) {
        printf("Bilangan harus positif!\n");
    } else {
        KonversiDesimalBiner(isi);
    }

    return 0;
}