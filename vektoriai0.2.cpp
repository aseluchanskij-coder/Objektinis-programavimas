#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>

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

void skaitymas(const string &fname, vector<studentas> &grupe) {
    std::ifstream fin(fname);
    if (!fin) {
        cout << "Nepavyko atidaryti failo!\n";
        return;
    }

    grupe.clear();

    string tipas;
    cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
    cin >> tipas;
    while (tipas != "vid" && tipas != "med") {
        cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
        cin >> tipas;
    }

    string line;
    while (getline(fin, line)) {
        std::stringstream ss(line);
        studentas A;
        int x, sum = 0;

        ss >> A.vardas >> A.pavarde;

        vector<int> temp;
        while (ss >> x) temp.push_back(x);

        if (temp.size() < 2) continue;

        A.egz = temp.back();
        temp.pop_back();
        A.paz = temp;

        for (int p : A.paz) sum += p;

        A.tipas = tipas;
        skaiciuoti(A, sum);
        grupe.push_back(A);
    }

    fin.close();
    cout << "Duomenys nuskaityti is failo!\n";
}

void input(vector<studentas> &grupe) {
    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti viska, 4 - nuskaityti is failo, 5 - baigti: ";
        int menu = skaiciaus_nusk();

        if (menu == 5) break;

        if (menu == 4) {
            skaitymas("Kursiokai.txt", grupe);
            continue;
        }

        if (menu == 3) {
            cout << "Kiek studentu generuoti? ";
            int kiek_stud = skaiciaus_nusk();

            string bendras_tipas;
            cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
            cin >> bendras_tipas;
            while (bendras_tipas != "vid" && bendras_tipas != "med") {
                cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
                cin >> bendras_tipas;
            }

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
                A.tipas = bendras_tipas;

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

bool pagalVarda(const studentas &a, const studentas &b) {
    return a.vardas < b.vardas;
}

bool pagalPavarde(const studentas &a, const studentas &b) {
    return a.pavarde < b.pavarde;
}

bool pagalVid(const studentas &a, const studentas &b) {
    return (a.tipas == "vid" ? a.rez : -1) > (b.tipas == "vid" ? b.rez : -1);
}

bool pagalMed(const studentas &a, const studentas &b) {
    return (a.tipas == "med" ? a.rez : -1) > (b.tipas == "med" ? b.rez : -1);
}

void sortStudents(vector<studentas> &grupe) {
    cout << "Rikiuoti pagal:\n";
    cout << "1 - Varda\n";
    cout << "2 - Pavarde\n";
    cout << "3 - Galutinis (vid.)\n";
    cout << "4 - Galutinis (med.)\n";
    cout << "Pasirinkimas: ";

    int pasirinkimas = skaiciaus_nusk();

    if (pasirinkimas == 1) {
        sort(grupe.begin(), grupe.end(), pagalVarda);
    } 
    else if (pasirinkimas == 2) {
        sort(grupe.begin(), grupe.end(), pagalPavarde);
    } 
    else if (pasirinkimas == 3) {
        sort(grupe.begin(), grupe.end(), pagalVid);
    } 
    else if (pasirinkimas == 4) {
        sort(grupe.begin(), grupe.end(), pagalMed);
    }
}

void output(const vector<studentas> &grupe) {
    cout << left << setw(20) << "Vardas"
         << left << setw(25) << "Pavarde"
         << setw(20) << "Galutinis(vid.)"
         << setw(20) << "Galutinis(med.)" << endl;

    cout << "----------------------------------------------------------------------------" << endl;

    for (const auto &A : grupe) {
        cout << left << setw(20) << A.vardas
             << left << setw(25) << A.pavarde;

        if (A.tipas == "vid") {
            cout << setw(20) << fixed << setprecision(2) << A.rez
                 << setw(20) << "-" << endl;
        } else {
            cout << setw(20) << "-"
                 << setw(20) << fixed << setprecision(2) << A.rez << endl;
        }
    }
}

int main() {
    srand(time(0));
    vector<studentas> grupe;

    auto start = std::chrono::high_resolution_clock::now();

    input(grupe);

    if (!grupe.empty()) {
        sortStudents(grupe);   
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;

    if (!grupe.empty()) {
        output(grupe);
    }
    cout << "\nApdorojimo laikas: " << diff.count() << " s\n";

    return 0;
}