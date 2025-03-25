/* File        : stack.h */
/* Deskripsi   : Deklarasi stack yang diimplementasikan dgn using ADT linked */
/*		 	  Top adalah alamat elemen puncak */
/* Dibuat oleh : Ade Chandra Nugraha*/

#ifndef stack_H
#define stack_H
#include "mainbody.h"  //nama header disesuaikan dengan program linked list pribadi
#include "boolean.h"

/* Null adalah stack dengan elemen kosong. */
/* Contoh deklarasi variabel bertype stack dengan ciri TOP bertype address (Head)*/
typedef List Stack ;

/**** Perubahan nilai komponen struktur ****/
// void SetTop(Stack *S, Stack NewTop);
/* Memberi Nilai TOP yang baru dengan NewTop */

/*    PROTO TYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S);
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */

/**** Predikat untuk test keadaan KOLEKSI ****/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack Kosong */

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X);
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X);
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong FS : X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void KonversiDesimalBiner(infotype X);

#endif

