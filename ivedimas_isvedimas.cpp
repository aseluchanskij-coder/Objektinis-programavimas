#include "ivedimas_isvedimas.h"
#include "studentas.h"
#include "pagalbines.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <limits>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::sort;

void skaitymas(const string &failo_pav, vector<studentas> &grupe) {
    std::ifstream failas(failo_pav);
    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo!");
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
    while (getline(failas, line)) {
        std::stringstream fs(line);
        studentas A;
        int x, sum = 0;

        fs >> A.vardas >> A.pavarde;

        vector<int> temp;
        while (fs >> x) temp.push_back(x);

        if (temp.size() < 2) continue;

        A.egz = temp.back();
        temp.pop_back();
        A.paz = temp;

        for (int p : A.paz) sum += p;

        A.tipas = tipas;
        skaiciuoti(A, sum);
        grupe.push_back(A);
    }

    failas.close();
    cout << "Duomenys nuskaityti is failo!\n";
}

void input(vector<studentas> &grupe) {
    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti viska, 4 - nuskaityti is failo, 5 - baigti: ";
        int menu = skaiciaus_nusk();

        if (menu == 5) break;

        if (menu == 4) {
            skaitymas("kursiokai.txt", grupe);
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

// cia prasei istrint sita void output(std::ostream &out, const vector<studentas> &grupe);

void rusiuotistud(vector<studentas> &grupe) {
    cout << "Rikiuoti pagal:" << endl;
    cout << "1 - Varda" << endl;
    cout << "2 - Pavarde" << endl;
    cout << "3 - Galutinis (vid.)" << endl;
    cout << "4 - Galutinis (med.)" << endl;
    cout << "Pasirinkimas: ";

    int pasirinkimas = skaiciaus_nusk();
    while (pasirinkimas < 1 || pasirinkimas > 4) {
        cout << "Klaida! Pasirinkite 1, 2, 3 arba 4: ";
        pasirinkimas = skaiciaus_nusk();
    }

    if (pasirinkimas == 1)
        sort(grupe.begin(), grupe.end(), pagalVarda);
    else if (pasirinkimas == 2)
        sort(grupe.begin(), grupe.end(), pagalPavarde);
    else if (pasirinkimas == 3)
        sort(grupe.begin(), grupe.end(), pagalVid);
    else if (pasirinkimas == 4)
        sort(grupe.begin(), grupe.end(), pagalMed);

    try {
        cout << "Pasirinkite isvesti duomenis i konsole (1) ar i faila (2): ";
        cin >> pasirinkimas;

        if (cin.fail()) {
            throw std::runtime_error("Ivestas netinkamas formatas!");
        }

        if (pasirinkimas != 1 && pasirinkimas != 2) {
            throw std::runtime_error("Pasirinkimas turi buti 1 arba 2!");
        }
    }
    catch (const std::exception& e) {
        cout << "Klaida: " << e.what() << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (pasirinkimas == 1) {
        output(cout, grupe);
    }
    else if (pasirinkimas == 2) {
        std::ofstream out("Rezultatai.txt");
        if (!out) {
            cout << "Nepavyko sukurti failo!\n";
            return;
        }
        output(out, grupe);
        out.close();
    }
}
void output(std::ostream &out, const vector<studentas> &grupe) {
    out << left << setw(20) << "Vardas"
        << left << setw(25) << "Pavarde"
        << setw(20) << "Galutinis(vid.)"
        << setw(20) << "Galutinis(med.)" << endl;

    out << "----------------------------------------------------------------------------" << endl;

    for (const auto &A : grupe) {
        out << left << setw(20) << A.vardas
            << left << setw(25) << A.pavarde;

        if (A.tipas == "vid") {
            out << setw(20) << fixed << setprecision(2) << A.rez
                << setw(20) << "-" << endl;
        } else {
            out << setw(20) << "-"
                << setw(20) << fixed << setprecision(2) << A.rez << endl;
        }
    }
}