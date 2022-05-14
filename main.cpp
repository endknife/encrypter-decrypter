#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void criptaFile(string fileDaCriptare, string fileCriptato) {
	string linea;
	ifstream fileOrig(fileDaCriptare);
	fstream fileCript;
	fileCript.open(fileCriptato.c_str(), ios::out);
	if (fileOrig.is_open() && fileCript.is_open()) {
		cout << "Criptazione in corso di " << fileDaCriptare << endl;
		while (getline(fileOrig, linea)) {

			for (int i = 0; i < linea.length(); i++) {


				fileCript << (int)linea[i] << endl;
			}

			fileCript << "176" << endl;
		}
		fileOrig.close();
		fileCript.close();
	}
	else cout << "File " << fileDaCriptare << " non è stato trovato";
}

void decriptaFile(string fileDaDeCriptare, string fileDeCript) {
	string linea;
	ifstream fileDadeCript(fileDaDeCriptare);
	fstream fileDecript;
	fileDecript.open(fileDeCript.c_str(), ios::out);
	if (fileDadeCript.is_open() && fileDecript.is_open()) {
		cout << "De criptazione in corso di " << fileDaDeCriptare << endl;
		while (getline(fileDadeCript, linea)) {
			if (linea != "176") {
				int ascii = stoi(linea);
				fileDecript << (char)ascii;
			}
			else {
				fileDecript << endl;
			}
			
		}
		fileDadeCript.close();
		fileDecript.close();
	}
	else cout << "File " << fileDaDeCriptare << " non è stato trovato";
}

int main() {
	int modalita;
	string primo, secondo;
	cout << "PROGRAMMA DI CRIPTAZIONE E DECRIPTAZIONE DI ZAGO" << endl << endl;
	cout << "1| Decripta un file" << endl;
	cout << "2| Cripta un file" << endl << endl;
	cout << "SCEGLI LA MODALITA: ";
	cin >> modalita;

	cout << "\x1b[2J\x1b[H"; // universal clear console
	cout << "[ATTENZIONE] il file inserito deve avere anche il tipo di file" << endl;
	cout << "[ESEMPIO] file.txt" << endl << endl;

	switch (modalita) {
		case 1: 
			cout << "Inserire il nome del file da decriptare: ";
			cin >> primo;
			cout << "Inserire il nome del file decriptato: ";
			cin >> secondo;
			decriptaFile(primo, secondo);
			break;
		case 2: 
			cout << "Inserire il nome del file da criptare: ";
			cin >> primo;
			cout << "Inserire il nome del file criptato: ";
			cin >> secondo;
			criptaFile(primo, secondo);
			break;
	}
}
