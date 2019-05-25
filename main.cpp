#include <stdlib.h>
#include "header.h"

using namespace std;

int main()
{
	List L;
	createList(L);
	list_anak La;

	char i = '0';
	while (i != '9')
	{
		system("CLS");
		cout << "=====================MENU========================" << endl;
		cout << "1. Buat divisi baru" << endl;
		cout << "2. Tambah karyawan" << endl;
		cout << "3. Daftar Divisi" << endl;
		cout << "4. Tampil Gaji" << endl;
		cout << "5. Daftar Seluruh Karyawan" << endl;
		cout << "6. Presensi" << endl;
		cout << "7. Hapus divisi" << endl;
		cout << "8. Hapus karyawan" << endl;
		cout << "9. Exit" << endl;
		cout << "pilih menu: ";
		cin >> i;
		if (i == '1') {
			system("CLS");
			string nama, divisi, ID;
			long gaji;
			char hadir;
			bool absen;
			int lembur;
			cout << "Nama Divisi: ";
			cin >> divisi;
			cout << "Nama Ketua: ";
			cin >> nama;
			cout << "ID: ";
			cin >> ID;
			cout << "Gaji: ";
			cin >> gaji;
			cout << "Hadir(Y/T): ";
			cin >> hadir;
			if ((hadir == 'Y') || (hadir == 'y')) {
				absen = true;
			}
			else {
				absen = false;
			}
			cout << "Jam lembur: ";
			cin >> lembur;
			addressP P = alokasi(nama, ID, divisi, gaji, lembur, absen);
			insertLastP(L, P);
		}
		else if (i == '2') {
			system("CLS");
			addressP P;
			addressA K;
			string nama, ID, jabatan, divisi;
			int lembur;
			char absensi;
			bool absen;
			cout << "Divisi yang ingin ditambahkan anggota: ";
			cin >> divisi;
			P = searchPD(L, divisi);
			if (P != 0)
			{
				cout << "Nama : ";
				cin >> nama;
				cout << "ID: ";
				cin >> ID;
				cout << "jabatan: ";
				cin >> jabatan;
				cout << "lembur: ";
				cin >> lembur;
				cout << "Hadir(Y/T): ";
				cin >> absensi;
				if ((absensi == 'Y') || (absensi == 'y')) {
					absen = true;
				}
				else {
					absen = false;
				}
				if (nextC(P) == 0) {
					createListChild(La);
					K = alokasi_Child(nama, ID, jabatan, lembur, absen);
					insertLastChild(La, K);
					connect(L, divisi, La);
					infoP(P).JumAnggota++;
				}
				else {
					K = alokasi_Child(nama, ID, jabatan, lembur, absen);
					insertLastChild(La, K);
					infoP(P).JumAnggota++;
				}
			}
			else {
				cout << "Divisi belum ada" << endl;
			}
		}
		else if (i == '3') {
			system("CLS");
			showP(L);
			cin >> i;
		}
		else if (i == '4') {
			system("CLS");
			string nama;
			cout << "Nama: ";
			cin >> nama;
			cout << "total gaji: " << hitungGaji(L, nama);
			cin >> i;
		}
		else if (i == '5') {
			showAll(L);
			cin >> i;
		}
		else if (i == '6') {
			system("CLS");
			cout << "jumlah karyawan yang hadir: " << KaryawanHadir(L);
			cin >> i;
		}
		else if (i == '7') {
			system("CLS");
			string divisi;
			cout << "Divisi yang akan dihapus: ";
			cin >> divisi;
			addressP P = searchPD(L, divisi);
			if (P != 0) {
				if (prevP(P) == 0) {
					deleteFirstP(L, P);
				}
				else if (nextP(P) == 0) {
					deleteLastP(L, P);
				}
				else {
					addressP Q = prevP(P);
					deleteAfterP(L, P, Q);
				}
			}
			cin >> i;
		}
		else if (i == '8') {
			system("CLS");
			//addressA Q,T;
			//addressP P;
			addressP P;
			addressA A;
			string ID;
			string divisi;
			cout << "Menghapus karyawan" << endl;
			cout << "Masukkan divisi: " << endl;
			cin >> divisi;
			cout << "Masukkan ID karyawan yang ingin dihapus: " << endl;
			cin >> ID;

			P = searchPD(L, divisi);
			A = nextC(P);
			while ((A != 0) && (info(A).IDA != ID)) {
				A = nextC(A);
			}
			if (A != 0) {
				if (nextC(P) == A) {
					nextC(P) = nextC(A);
					nextC(A) = 0;
				}
				else {
					addressA B;
					B = nextC(P);
					while (nextC(B) != A) {
						B = nextC(B);
					}
					nextC(B) = nextC(A);
				}
				showAll(L);
			}
			else {
				cout << "empty" << endl;
			}
			cin >> i;
		}
		
		
	}
	return 0;
}
