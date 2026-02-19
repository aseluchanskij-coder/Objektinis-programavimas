#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::endl;
using std::fixed;
using std::setprecision;
struct studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
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
        skaicius = sum * 1.0 / A.paz.size();
    } else {
        sort(A.paz.begin(), A.paz.end());
        int n = A.paz.size();
        if (n % 2 == 0)
            skaicius = (A.paz[n/2 - 1] + A.paz[n/2]) / 2.0;
        else
            skaicius = A.paz[n/2];
    }
    A.rez = 0.4 * skaicius + 0.6 * A.egz;
}

void input(vector<studentas> &grupe) {
    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti viska, 4 - baigti: ";
        int menu = skaiciaus_nusk();
        if (menu == 4) break;

        if (menu == 3) {
            cout << "Kiek studentu generuoti? ";
            int kiek_stud = skaiciaus_nusk();

            for (int k = 0; k < kiek_stud; k++) {
                studentas A;
                int sum = 0;

                A.vardas = random_vardas();
                A.pavarde = random_pavarde();

                int kiek = rand() % 5 + 3;
                for (int i = 0; i < kiek; i++) {
                    int r = random_paz();
                    A.paz.push_back(r);
                    sum += r;
                }
                A.egz = random_paz();

                cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
                cin >> A.tipas;
                while (A.tipas != "vid" && A.tipas != "med") {
                    cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
                    cin >> A.tipas;
                }

                skaiciuoti(A, sum);
                grupe.push_back(A);
            }
            continue;
        }

        studentas A;
        int sum = 0;

        if (menu == 1 || menu == 2) {
            cout << "Iveskite studento varda (arba 0): ";
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
            cout << "Iveskite pazymius (0 - baigti): ";
            int temp;
            while (true) {
                temp = skaiciaus_nusk();
                if (temp == 0) break;
                if (temp < 1 || temp > 10) continue;
                A.paz.push_back(temp);
                sum += temp;
            }

            cout << "Iveskite egzamino bala: ";
            A.egz = skaiciaus_nusk();
            while (A.egz < 1 || A.egz > 10) A.egz = skaiciaus_nusk();
        }

        if (menu == 2) {
            int kiek = rand() % 5 + 3;
            for (int i = 0; i < kiek; i++) {
                int r = random_paz();
                A.paz.push_back(r);
                sum += r;
            }
            A.egz = random_paz();
        }

        cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
        cin >> A.tipas;
        while (A.tipas != "vid" && A.tipas != "med"){
            cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
            cin >> A.tipas;
        }

        skaiciuoti(A, sum);
        grupe.push_back(A);
    }
}


void output(const vector<studentas> &grupe) {
    cout << left << setw(10) << "Vardas"
         << left << setw(15) << "Pavarde"
         << setw(15) << "Galutinis(vid.)"
         << setw(15) << "Galutinis(med.)" << endl;

    cout << "----------------------------------------------------------" << endl;

    for (const auto &A : grupe) {
        cout << left << setw(10) << A.vardas
             << left << setw(15) << A.pavarde;

        if (A.tipas == "vid") {
            cout << setw(15) << fixed << setprecision(2) << A.rez
                 << setw(15) << "-" << endl;
        } else {
            cout << setw(15) << "-"
                 << setw(15) << fixed << setprecision(2) << A.rez << endl;
        }
    }
}

int main() {
    srand(time(0));
    vector<studentas> grupe;
    input(grupe);
    output(grupe);
    return 0;
}
