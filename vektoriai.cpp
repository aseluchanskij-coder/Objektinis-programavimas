#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

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

void input(vector<studentas> &grupe) {
    while (true) {
        studentas A;

        cout << "Iveskite studento varda (arba 0): ";
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

        cout << "Iveskite pazymius (0 - baigti): " << endl;
        int temp;
        int sum = 0;

        while (true) {
            temp = skaiciaus_nusk();
            if (temp == 0) break;
            if (temp < 1 || temp > 10) continue;
            A.paz.push_back(temp);
            sum += temp;
        }

        cout << "Iveskite egzamino bala: ";
        A.egz = skaiciaus_nusk();
        while (A.egz < 1 || A.egz > 10) {
            A.egz = skaiciaus_nusk();
        }

        cout << "Skaiciuoti su vidurkiu (vid) ar mediana (med)? ";
        cin >> A.tipas;
        while (A.tipas != "vid" && A.tipas != "med") {
            cout << "Klaida! Pasirinkite 'vid' arba 'med': ";
            cin >> A.tipas;
        }

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
    vector<studentas> grupe;
    input(grupe);
    output(grupe);
    return 0;
}
