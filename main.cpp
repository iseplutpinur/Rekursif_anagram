#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<fstream>
using namespace std;
class Kata{
	private:
		int ukuran;
		int kounter;
		string strKerja;
		void rotasi(int);
		void tampilkankata();
	public:
		Kata(string);
		void anagram(int);
};

Kata::Kata(string strMasukan) : strKerja(strMasukan), kounter(0){
	ukuran = strMasukan.length();
}

void Kata::anagram(int ukuranBaru){
	if(ukuranBaru == 1)
		return;

	for(int j=0; j<ukuranBaru; j++){
		anagram(ukuranBaru-1);

	if(ukuranBaru==2)
		tampilkankata();
		rotasi(ukuranBaru);
	}
}

void Kata::rotasi(int ukuranBaru){
	int j;
	int posisi = ukuran - ukuranBaru;
	char temp = strKerja[posisi];

	for(j = posisi+1; j<ukuran; j++)
		strKerja[j-1] = strKerja[j];

	strKerja[j-1] = temp;	
}


void Kata::tampilkankata(){
	ofstream tulis;
    tulis.open("data.txt",ios::app);
	if(kounter < 99)
		cout << " ";
		//tulis << "\t";
	if(kounter < 9 )
		cout << " ";
		//tulis << "\t";
	cout << ++kounter << " ";
	int Penghitung=kounter;
	tulis << Penghitung << "\t\t";
	//if(kounter < 10 ){
	//	tulis << "\t";
	//}
	cout << strKerja << " ";
	tulis << strKerja << "\t";
	if(kounter < 1000){
		tulis << "\t";
	}

	if(kounter%6 == 0){
		cout << endl;
		tulis << endl;
	}
	tulis.close();
}

int main(){
	ofstream tulis;
	string masukan,a;
	int pjg;
	system("cls");
	cout << "Program Rekursif Anagram" << endl;
	cout << "Masukan sebuah kata : ";
	cin >> masukan;
	tulis.open("data.txt",ios::trunc);
    tulis << "Peluang dari kata [" << masukan << "] adalah : " << endl << endl;
    tulis.close();

	pjg = masukan.length();
	Kata Kata(masukan);
	Kata.anagram(pjg);
	getch();
}