
#include <iostream>
#include <string>

using namespace std;
#define nil NULL
#define info(P) P->info
#define nextC(P) P->nextC
#define first(L) ((L).first)

typedef struct ANAKS infotypeC;
struct ANAKS
{
	string namaA, IDA, jabatan;
	int lemburA;
	long gajiC;
	bool absen;
};

typedef struct nodeA *addressA;
struct nodeA
{
	infotypeC info;
	addressA nextC;
};

struct list_anak
{
	addressA first;
};

void createListChild(list_anak &L);
void insertLastChild(list_anak &L, addressA P);
void deleteFirstChild(list_anak &L, addressA &P);
void deleteAfterChild(list_anak &L, addressA &P, addressA Q);
void deleteLastChild(list_anak &L, addressA &P);
void deleteAnak(list_anak &L, addressA &P, string ID);
addressA alokasi_Child(string nama, string ID, string jabatan, int lembur, bool absensi);
addressA findElm(list_anak L, string x);
void printInfoChild(list_anak L);
void jlhChild(list_anak L, int &jum);


