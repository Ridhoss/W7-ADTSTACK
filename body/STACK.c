/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "../header/stack.h"

/**** Perubahan nilai komponen struktur ****/
void SetTop (Stack *S, Stack NewTop )
/* Memberi Nilai TOP yang baru dengan NewTop */
{
	if (NewTop != NULL) {
        *S = NewTop; // Menggeser top ke alamat yang baru
    }
}

/*    PROTO TYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */
{
	*S = NULL;
}

/**** Predikat untuk test keadaan KOLEKSI ****/
bool IsEmpty (Stack S)
/* Mengirim true jika Stack Kosong */
{
	return (isEmpty(S));
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	InsVFirst(S, X);  // nama modul disesuaikan dengan pseudocode linked list pribadi
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	DelVFirst(S, X); // nama modul disesuaikan dengan pseudocode linked list pribadi
}

void KonversiDesimalBiner(infotype desimal)
{
    Stack S, temp;
    int sisa;

    CreateEmpty(&S);

    while (desimal > 0) {
        sisa = desimal % 2;
        Push(&S, sisa);
        desimal /= 2;
    }

    SetTop(&temp, S);

    printf("Hasil konversi biner: ");
    while (!IsEmpty(S)) {
        Pop(&S, &sisa);
        printf("%d", sisa);
    }
    printf("\n");

    SetTop(&S, temp);
}


