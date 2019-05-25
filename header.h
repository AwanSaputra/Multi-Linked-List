#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <iostream>
using namespace std;

#include "child.h"

#define Nil NULL
#define last(L) L.last
#define nextP(P) (P)->nextP
#define infoP(P) (P)->infoPr
#define prevP(P) (P)->prevP

struct DataP {
	string nama, ID, divisi;
	long gaji;
	int JumAnggota, lembur;
	bool absen;
};

typedef struct DataP infoP;
typedef struct ElemenP *addressP;

struct ElemenP {
	addressP nextP, prevP;
	addressA nextC;
	infoP infoPr;
};

struct List {
	addressP first, last;
};

void createList(List &L);

addressP alokasi(string nama, string ID, string divisi, long gaji, int lembur, bool absen);

void insertFirstP(List &L, addressP P);
void insertLastP(List &L, addressP P);
void insertAfterP(List &L, addressP P, addressP prec);
void deleteFirstP(List &L, addressP &P);
void deleteLastP(List &L, addressP &P);
void deleteAfterP(List &L, addressP &P, addressP prec);
addressP searchP(List L, string nama);
addressP searchPD(List L, string divisi);
void showP(List L);
void showAll(List L);
long hitungGaji(List L, string nama);
int totalKaryawan(List L);
int KaryawanHadir(List L);
void connect(List L, string divisi, list_anak La);
#endif // HEADER_H_INCLUDED
