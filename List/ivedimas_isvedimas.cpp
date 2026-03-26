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
#include <list>

using std::list;
using std::cout;
using std::cin;
using std::string;
//using std::vector;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
//using std::sort;

void skaitymas(const string &failo_pav, list<studentas> &grupe) {
    std::ifstream failas("duomenys/" + failo_pav);
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

        std::list<int> temp;
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
void skaitymas_rez(const string &failo_pav, list<studentas> &grupe) {
    std::ifstream failas("duomenys/" + failo_pav);
    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo!");
    }

    grupe.clear();

    string line;

    getline(failas, line);
    getline(failas, line);

    while (getline(failas, line)) {
        std::stringstream fs(line);
        studentas A;

        fs >> A.vardas >> A.pavarde >> A.rez;

        A.tipas = "vid"; 

        grupe.push_back(A);
    }

    cout << "Rezultatai nuskaityti is failo!\n";
}

void input(list<studentas> &grupe) {
    while (true) {
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti viska, 4 - nuskaityti is failo,\n5 - nuskaityti sugeneruota faila, 6 - baigti: ";
        int menu = skaiciaus_nusk();

        if (menu == 6) break;

        if (menu == 4) {
            skaitymas("duomenys/kursiokai.txt", grupe);
            continue;
        }
        if (menu == 5) {
    string failo_pav;

    cout << "Iveskite rezultatu failo pavadinima: ";
    cin >> failo_pav;

    try {
        skaitymas_rez(failo_pav, grupe);
    }
    catch (const std::exception &e) {
        cout << "Klaida: " << e.what() << endl;
    }

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
            cin.ignore(10000, '\n');
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
        cin.ignore(10000, '\n');
        skaiciuoti(A, sum);
        grupe.push_back(A);
    }
}

void rusiuotistud(list<studentas> &grupe) {
    cout << "Rikiuoti pagal:" << endl;
    cout << "1 - Varda" << endl;
    cout << "2 - Pavarde" << endl;
    cout << "3 - Galutinis (vid.)" << endl;
    cout << "4 - Galutinis (med.)" << endl;
    cout << "Pasirinkimas: ";

    int pasirinkimas = skaiciaus_nusk();
    while (pasirinkimas < 1 || pasirinkimas > 4) {
        cout << "Klaida! Pasirinkite 1, 2, 3, 4: ";
        pasirinkimas = skaiciaus_nusk();
    }

    if (pasirinkimas == 1)
    grupe.sort(pagalVarda);
else if (pasirinkimas == 2)
    grupe.sort(pagalPavarde);
else if (pasirinkimas == 3)
    grupe.sort(pagalVid);
else if (pasirinkimas == 4)
    grupe.sort(pagalMed);

    try {
        cout << "Pasirinkite isvesti duomenis i konsole (1), i faila (2) ar padalinti (3): ";
        pasirinkimas = skaiciaus_nusk();

        if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
            throw std::runtime_error("Pasirinkimas turi buti 1, 2 arba 3!");
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
        std::string failo_pav;
        std::cout << "Iveskite failo pavadinima (pvz., 1000.txt, enter – numatytasis Rezultatai.txt): ";

        std::cin.ignore(1, '\n');
        std::getline(std::cin, failo_pav);

        if (failo_pav.empty()) {
            failo_pav = "Rezultatai.txt"; 
        } else if (failo_pav.find('.') == std::string::npos) {
            failo_pav += ".txt"; 
        }

        std::ofstream out(failo_pav);
        if (!out) {
            std::cout << "Nepavyko sukurti failo: " << failo_pav << "\n";
            return;
        }
        output(out, grupe);
        out.close();

        cout << "Duomenys issaugoti faile: " << failo_pav << endl;
    }
    else if (pasirinkimas == 3) {
        if (grupe.empty()) {
            std::cout << "Nera studentu nuskaitytų! Pirmiausia nuskaitykite duomenis.\n";
            return;
        }

        std::list<studentas> vargsai, kietuoliai;
        padalinti_studentus(grupe, vargsai, kietuoliai);

        std::ofstream f_vargsai("duomenys/vargsai.txt");
        output(f_vargsai, vargsai);
        f_vargsai.close();

        std::ofstream f_kietuoliai("duomenys/kietuoliai.txt");
        output(f_kietuoliai, kietuoliai);
        f_kietuoliai.close();

        std::cout << "Studentai padalinti i failus:\n";
        std::cout << "vargsai.txt\n";
        std::cout << "kietuoliai.txt\n";
    }
}
void padalinti_studentus(const std::list<studentas> &grupe,
                         std::list<studentas> &vargsai,
                         std::list<studentas> &kietuoliai) {
    for (const auto &A : grupe) {
        if (A.rez < 5.0)
            vargsai.push_back(A);
        else
            kietuoliai.push_back(A);
    }
}


void output(std::ostream &out, const std::list<studentas> &grupe) {
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
// padalinti_studentus