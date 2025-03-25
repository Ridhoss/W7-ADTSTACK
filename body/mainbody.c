#include <limits.h>
#include <malloc.h>
#include "../header/mainbody.h"

boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	return (First(L) == Nil);
}

void CreateList (List * L)
{
	First(*L) = Nil;
}

address Alokasi (infotype X)
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != Nil)		/* Alokasi berhasil */
	{
		Info(P) = X;
		Next(P) = Nil;
	}
	return (P);
}

void DeAlokasi (address P)
{
	if (P != Nil)
	{
		free (P);
	}
}

address Search (List L, infotype X)
{
	 /* Kamus Lokal */
	address P;
	boolean found =  false;
	 /* algoritma */
	P = First(L);
	while ((P != Nil) && (!found))
	{
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	}	/* P = Nil atau Ketemu */
	
	return (P);
}

boolean FSearch (List L, address P)
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

void InsVFirst (List * L, infotype X)
{
	 /* Kamus Lokal */
	address P;

	 /* Algoritma */
	P = Alokasi(X);

	if(P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}

	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsVLast (List * L, infotype X)
{
	 /* Kamus Lokal */
	address P, temp;
	
	 /* Algoritma */
	P = Alokasi(X);

	temp = First(*L);

	while (Next(temp) != Nil)
	{
		temp = Next(temp);
	}

	Next(temp) = P;
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelVFirst (List * L, infotype * X)
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = First(*L);

	*X = Info(P);
	First(*L) = Next(P);
	DeAlokasi(P);
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelVLast (List * L, infotype * X)
{
	 /* Kamus Lokal */
	address PDel, Prev;
	 /* Algoritma */
	PDel = First(*L);

	while (Next(PDel) != Nil)
	{
		Prev = PDel;
		PDel = Next(PDel);
	}

	*X = Info(PDel);
	Next(Prev) = Nil;
	DeAlokasi(PDel);
	
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertFirst (List * L, address P)
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec)
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	address temp;

	temp = First(*L);
	
	while (temp != Prec)
	{
		temp = Next(temp);
	}

	Next(P) = Next(temp);
	Next(temp) = P;

}

void InsertLast (List * L, address P)
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	Last = First(*L);

	while (Next(Last) != Nil)
	{
		Last = Next(Last);
	}

	Next(Last) = P;
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelFirst (List * L, address * P)
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	address temp;

	temp = First(*L);
	if(temp != Nil){
		(*P) = Alokasi(Info(temp));

		First(*L) = Next(temp);
		DeAlokasi(temp);
	}
}


void DelP (List * L, infotype X)
{
	 /* Kamus Lokal */
	address P, prec;
	boolean found=false;
	 
	 /* Algoritma */
	P = Search((*L), X);
	prec = SearchPrec((*L), Info(P));

	if(prec == Nil){
		DelFirst(L, &P);
	}else {
		Next(prec) = Next(P);
		DeAlokasi(P);
	}

	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelLast (List * L, address * P)
{
	 /* Kamus Lokal */
	address Prec, temp;
	 /* Algoritma */

	temp = First(*L);

	while (Next(temp) != Nil)
	{
		temp = Next(temp);
	}

	Prec = SearchPrec((*L), Info(temp));

	if(temp != Nil){
		(*P) = Alokasi(Info(temp));

		Next(Prec) = Nil;
		DeAlokasi(temp);
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
{
	 //Buatkan algoritma sesuai spesifikasi modul ini
	address temp;

	if (Next(Prec) == Nil)
	{
		printf("Tidak ada element list berikutnya!\n");
	}

    if (Prec != Nil && Next(Prec) != Nil) {
        temp = Next(Prec);
        *Pdel = Alokasi(Info(temp));
        
        Next(Prec) = Next(temp);
        DeAlokasi(temp);
    }
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */

	if(First(L) == Nil){
		printf("List Kosong!\n");
	} else {
		P = First(L);
		while (P != Nil) {
			printf("%d -> ", Info(P));
			P = Next(P); 
		}
		printf("NULL \n");
	}
    printf("======================== \n");

	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel, temp;
	 /* Algoritma */
	
	PDel = First(*L);

	while (PDel != Nil)
	{
		temp = PDel;
		PDel = Next(PDel);
		DeAlokasi(temp);
	}

	First(*L) = Nil;

	printf("Berhasil Menghapus Semua Element List!\n");
}

void DelGanjil(List * L) 
{
    address PBefore, PNext, Pdel;
	
    while (First(*L) != Nil && Info(First(*L)) % 2 == 1) {
        Pdel = First(*L);
        First(*L) = Next(Pdel);
        DeAlokasi(Pdel);
    }

    if (First(*L) == Nil) return;

    PBefore = First(*L);
    PNext = Next(PBefore);

    while (PNext != Nil) {
        if (Info(PNext) % 2 == 1) {
            Pdel = PNext;
            PNext = Next(PNext);
            Next(PBefore) = PNext;
            DeAlokasi(Pdel);
        } else {
            PBefore = PNext;
            PNext = Next(PNext);
        }
    }

    printf("Node Ganjil Berhasil Dihapus!\n");
}
