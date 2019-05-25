#include "child.h"
void createListChild(list_anak &L) {
	first(L) = nil;
}

long Gaji_Child(int x) {
	long G;
	//gaji anak utama 5 jt, lembur perjamnya 50 k
	G = 5000000 + (x * 50000);
	return G;
}

addressA alokasi_Child(string nama, string ID, string jabatan, int lembur, bool absensi) {
	addressA P;
	P = new nodeA;
	info(P).namaA = nama;
	info(P).IDA = ID;
	info(P).lemburA = lembur;
	info(P).jabatan = jabatan;
	info(P).gajiC = Gaji_Child(lembur);
	info(P).absen = absensi;
	nextC(P) = nil;
	return P;
}

void insertLastChild(list_anak &L, addressA P) {
	if (first(L) == nil)
	{
		first(L) = P;
	}
	else {
		addressA Q;
		Q = first(L);
		while (nextC(Q) != nil) {
			Q = nextC(Q);
		}
		nextC(Q) = P;
	}
}
void deleteFirstChild(list_anak &L, addressA &P) {
	first(L) = nextC(P);
	nextC(P) = nil;
}

void deleteAfterChild(list_anak &L, addressA &P, addressA Q) {
	nextC(Q) = nextC(P);
	nextC(P) = nil;
}

void deleteLastChild(list_anak &L, addressA &P) {
	addressA  Q;
	Q = first(L);
	while (nextC(Q) != P) {
		Q = nextC(Q);
	}
	nextC(Q) = nil;
}

void deleteAnak(list_anak &L, addressA &P, string ID) {
	if (first(L) == nil)
	{
		cout << "Kosong" << endl;
	}
	else {
		P = first(L);
		while ((info(P).IDA != ID) && (P != nil))
		{
			P = nextC(P);
		}
		if (P == first(L))
		{
			deleteFirstChild(L, P);
		}
		else if (nextC(P) == nil)
		{
			deleteLastChild(L, P);
		}
		else {
			addressA Q;
			Q = first(L);
			while (nextC(Q) != P) {
				Q = nextC(Q);
			}
			deleteAfterChild(L, P, Q);
		}

	}
}



addressA findElm(list_anak L, string x) {
	addressA P;
	P = first(L);
	while ((info(P).IDA != x) && (P != nil)) {
		P = nextC(P);
	}
	if (info(P).IDA == x)
	{
		return P;
	}
	else {
		return nil;
	}
}

void printInfoChild(list_anak L) {
	addressA P;
	P = first(L);
	while (P != nil) {
		cout << "Nama: " << info(P).namaA << endl;
		cout << "ID: " << info(P).IDA << endl;
		cout << "Jumlah lembur: " << info(P).lemburA << " jam" << endl;
		cout << "Jabatan: " << info(P).jabatan << endl;
		cout << "Gaji: RP " << info(P).gajiC << endl;
		cout << "Absensi:  " << info(P).absen << endl;
		cout << endl;
		P = nextC(P);
	}
}


void jlhChild(list_anak L, int &jum) {
	addressA P;
	P = first(L);
	jum = 1;
	while (P != nil) {
		jum = jum + 1;
		P = nextC(P);
	}
}
