#include "header.h"

addressP alokasi(string nama, string ID, string divisi, long gaji, int lembur, bool absen) {
	addressP P = new ElemenP;
	infoP(P).nama = nama;
	infoP(P).ID = ID;
	infoP(P).divisi = divisi;
	infoP(P).gaji = gaji;
	infoP(P).lembur = lembur;
	infoP(P).absen = absen;
	infoP(P).JumAnggota = 1;
	nextP(P) = 0;
	nextC(P) = 0;
	prevP(P) = 0;
	return P;
}

void createList(List &L) {
	first(L) = 0;
	last(L) = 0;
}

void insertFirstP(List &L, addressP P) {
	if (first(L) == 0) {
		first(L) = P;
		last(L) = P;
	}
	else {
		nextP(P) = first(L);
		prevP(first(L)) = P;
		first(L) = P;
	}
}
void insertLastP(List &L, addressP P) {
	if (first(L) == 0) {
		first(L) = P;
		last(L) = P;
	}
	else {
		nextP(last(L)) = P;
		prevP(P) = last(L);
		last(L) = P;
	}
}

void insertAfterP(List &L, addressP P, addressP prec) {
	nextP(P) = nextP(prec);
	prevP(P) = prec;
	nextP(prec) = P;
	prevP(nextP(P)) = P;
}

void deleteFirstP(List &L, addressP &P) {
	if (first(L) == 0) {
		cout << "KOSONG";
	}
	else if (nextP(first(L)) == 0) {
		P = first(L);
		first(L) = 0;
		last(L) = 0;
	}
	else {
		P = first(L);
		first(L) = nextP(P);
		prevP(first(L)) = 0;
		nextP(P) = 0;
	}
}
void deleteLastP(List &L, addressP &P) {
	if (first(L) == 0) {
		cout << "KOSONG";
	}
	else if (nextP(first(L)) == 0) {
		P = first(L);
		first(L) = 0;
		last(L) = 0;
	}
	else {
		P = last(L);
		last(L) = prevP(P);
		prevP(P) = 0;
		nextP(last(L)) = 0;
	}
}

void deleteAfterP(List &L, addressP &P, addressP prec) {
	P = nextP(prec);
	nextP(prec) = nextP(P);
	prevP(nextP(P)) = prec;
	prevP(P) = 0;
	nextP(P) = 0;
}

addressP searchP(List L, string nama) {
	addressP P = first(L);
	while ((infoP(P).nama != nama) && (P != 0)) {
		P = nextP(P);
	}
	return P;
}

addressP searchPD(List L, string divisi) {
	addressP P = first(L);
	while ((infoP(P).divisi != divisi) && (P != 0)) {
		P = nextP(P);
	}
	return P;
}

void showP(List L) {
	addressP P = first(L);
	while (P != 0) {
		cout << infoP(P).divisi << " ";
		P = nextP(P);
	}
}

void showAll(List L) {
	addressP P = first(L);
	addressA A;
	while (P != 0) {
		cout << infoP(P).divisi << ": " << infoP(P).nama << "(ketua) ";
		A = nextC(P);
		while (A != 0) {
			cout << info(A).namaA << " ";
			A = nextC(A);
		}
		cout << endl;
		P = nextP(P);
	}
}

long hitungGaji(List L, string nama) {
	addressP P = searchP(L, nama);
	long i = infoP(P).gaji + (infoP(P).lembur * 50000);
	return i;
}

int totalKaryawan(List L) {
	int i = 0;
	addressP P = first(L);
	while (P != 0) {
		i = i + infoP(P).JumAnggota;
		P = nextP(P);
	}
	return i;
}

int KaryawanHadir(List L) {
	addressP P = first(L);
	addressA A;
	int i = 0;
	while (P != 0) {
		if (infoP(P).absen == true) {
			i = i + 1;
		}
		A = nextC(P);
		while (A != 0) {
			if (info(A).absen == true) {
				i = i + 1;
			}
			A = nextC(A);
		}
		P = nextP(P);
	}
	return i;
}

void connect(List L, string divisi, list_anak La) {
	addressP P = searchPD(L, divisi);
	nextC(P) = first(La);
}
