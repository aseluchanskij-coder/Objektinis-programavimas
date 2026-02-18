#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

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

void input(studentas grupe[], int &m) {
    m = 0;

    while (true) {
        studentas A;

        cout << "Iveskite studento varda (0 - baigti): ";
        cin >> A.vardas;
        if (A.vardas == "0") break;

        while (!string_nusk(A.vardas)) {
            cout << "Klaida! Vardas negali tureti skaiciu ar simboliu. Bandykite dar karta: ";
            cin >> A.vardas;
        }

        cout << "Iveskite studento pavarde: ";
        cin >> A.pavarde;
        while (!string_nusk(A.pavarde)) {
            cout << "Klaida! Pavarde negali tureti skaiciu ar simboliu. Bandykite dar karta: ";
            cin >> A.pavarde;
        }

        cout << "Iveskite studento pazymius (1-10). Ivedus 0 – baigti: " << endl;

        int temp[100];
        A.paz_kiek = 0;
        int x;

        while (true) {
            x = skaiciaus_nusk();

            if (x == 0) break;

            if (x < 1 || x > 10) {
                cout << "Klaida! Pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
                continue;
            }

            temp[A.paz_kiek] = x;
            A.paz_kiek++;
        }

        A.paz = new int[A.paz_kiek];
        int sum = 0;

        for (int i = 0; i < A.paz_kiek; i++) {
            A.paz[i] = temp[i];
            sum += A.paz[i];
        }

        cout << "Iveskite egzamino bala: ";
        A.egz = skaiciaus_nusk();

        cout << "Pasirinkite skaiciavimo buda (vid arba med): ";
        cin >> A.tipas;
        while (A.tipas != "vid" && A.tipas != "med") {
            cout << "Klaida! Galima rinktis tik 'vid' arba 'med'. Bandykite dar karta: ";
            cin >> A.tipas;
        }

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
        grupe[m] = A;
        m++;
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
            cout << setw(15) << grupe[i].rez << setw(15) << "-" << endl;
        } else {
            cout << setw(15) << "-" << setw(15) << grupe[i].rez << endl;
        }
    }
}

int main() {
    studentas grupe[100];
    int m;

    input(grupe, m);
    output(grupe, m);

    for (int i = 0; i < m; i++) {
        delete[] grupe[i].paz;
    }

    return 0;
}
