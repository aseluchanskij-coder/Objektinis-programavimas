#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::left;
using std::endl;

struct studentas {
    string vardas;
    string pavarde;
    int *paz;
    int paz_kiek;
    int egz;
    double rez;
    string tipas;
};

bool string_nusk(const string &s) {
    for (char c : s)
        if (!isalpha(c)) return false;
    return true;
}

int skaiciaus_nusk() {
    int x;
    while (true) {
        cin >> x;
        if (!cin.fail()) return x;
        cout << "Klaida! Prasome ivesti skaiciu: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int random_paz() {
    return rand() % 10 + 1;
}

string random_vardas() {
    string vardai[10] = {"Jonas","Petras","Mantas","Lukas","Tomas","Paulius","Alanas","Danielius","Povilas","Ernestas"};
    return vardai[rand() % 10];
}

string random_pavarde() {
    string pavardes[10] = {"Jonaitis","Petraitis","Kazlauskas","Balciunas","Jankauskas","Stankevicius","Vaitkus","Butkus","Urbonas","Zukauskas"};
    return pavardes[rand() % 10];
}

void skaiciuoti(studentas &A, int sum) {
    double skaicius;
    if (A.tipas == "vid") {
        skaicius = sum * 1.0 / A.paz_kiek;
    } else {
        std::sort(A.paz, A.paz + A.paz_kiek);
        if (A.paz_kiek % 2 == 0)
            skaicius = (A.paz[A.paz_kiek/2 - 1] + A.paz[A.paz_kiek/2]) / 2.0;
        else
            skaicius = A.paz[A.paz_kiek/2];
    }
    A.rez = 0.4 * skaicius + 0.6 * A.egz;
}

void input(studentas grupe[], int &m) {
    m = 0;

    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti viska, 4 - baigti: ";
        int menu = skaiciaus_nusk();
        if (menu == 4) break;

        if (menu == 3) {
            cout << "Kiek studentu generuoti? ";
            int kiek_stud = skaiciaus_nusk();

            for (int k = 0; k < kiek_stud; k++) {
                studentas A;
                int temp[100];
                A.paz_kiek = 0;
                int sum = 0;

                A.vardas = random_vardas();
                A.pavarde = random_pavarde();

                int kiek = rand() % 5 + 3;
                for (int i = 0; i < kiek; i++) {
                    int r = random_paz();
                    temp[A.paz_kiek++] = r;
                    sum += r;
                }
                A.egz = random_paz();

                A.paz = new int[A.paz_kiek];
                for (int i = 0; i < A.paz_kiek; i++) A.paz[i] = temp[i];

                cout << "Pasirinkite skaiciavimo buda (vid arba med): ";
                cin >> A.tipas;
                while (A.tipas != "vid" && A.tipas != "med") {
                    cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
                    cin >> A.tipas;
                }

                skaiciuoti(A, sum);
                grupe[m++] = A;
            }

            continue;
        }

        studentas A;
        int temp[100];
        A.paz_kiek = 0;
        int sum = 0;

        if (menu == 1 || menu == 2) {
            cout << "Iveskite studento varda (0 - baigti): ";
            cin >> A.vardas;
            if (A.vardas == "0") break;
            while (!string_nusk(A.vardas)) {
                cout << "Klaida! Vardas negali buti skaicius: ";
                cin >> A.vardas;
            }

            cout << "Iveskite studento pavarde: ";
            cin >> A.pavarde;
            while (!string_nusk(A.pavarde)) {
                cout << "Klaida! Pavarde negali buti skaicius: ";
                cin >> A.pavarde;
            }
        }

        if (menu == 1) {
            cout << "Iveskite pazymius (1-10, 0 - baigti): " << endl;
            while (true) {
                int x = skaiciaus_nusk();
                if (x == 0) break;
                if (x < 1 || x > 10) continue;
                temp[A.paz_kiek++] = x;
                sum += x;
            }
            cout << "Iveskite egzamino bala: ";
            A.egz = skaiciaus_nusk();
            while (A.egz < 1 || A.egz > 10) A.egz = skaiciaus_nusk();
        }

        if (menu == 2) {
            int kiek = rand() % 5 + 3;
            for (int i = 0; i < kiek; i++) {
                int r = random_paz();
                temp[A.paz_kiek++] = r;
                sum += r;
            }
            A.egz = random_paz();
        }

        A.paz = new int[A.paz_kiek];
        for (int i = 0; i < A.paz_kiek; i++) A.paz[i] = temp[i];

        cout << "Pasirinkite skaiciavimo buda (vid arba med): ";
        cin >> A.tipas;
        while (A.tipas != "vid" && A.tipas != "med"){
                cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
                cin >> A.tipas;
        } 

        skaiciuoti(A, sum);
        grupe[m++] = A;
    }
}

void output(studentas grupe[], int m) {
    cout << left << setw(10) << "Vardas"
         << left << setw(20) << "Pavarde"
         << setw(15) << "Galutinis(vid.)"
         << setw(15) << "Galutinis(med.)" << endl;

    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < m; i++) {
        cout << left << setw(10) << grupe[i].vardas
             << left << setw(20) << grupe[i].pavarde;

        if (grupe[i].tipas == "vid") {
            cout << setw(15) << std::fixed << std::setprecision(2) << grupe[i].rez << setw(15) << "-" << endl;
        } else {
            cout << setw(15) << "-" << setw(15) << std::fixed << std::setprecision(2) << grupe[i].rez << endl;
        }
    }
}

int main() {
    srand(time(0));
    studentas grupe[100];
    int m;

    input(grupe, m);
    output(grupe, m);

    for (int i = 0; i < m; i++) {
        delete[] grupe[i].paz;
    }

    return 0;
}
