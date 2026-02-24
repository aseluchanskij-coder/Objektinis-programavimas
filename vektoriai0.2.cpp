#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>

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
};

void skaiciuoti(studentas &A, int sum) {
    double vid;
    vid = sum * 1.0 / A.paz.size();
    A.rez = 0.4 * vid + 0.6 * A.egz;
}

void skaitymas(vector<studentas>& grupe, const string& failas) {
    std::ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo!\n";
        return;
    }

    string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        studentas A;
        int sum = 0;
        A.paz.clear();

        std::stringstream ss(eilute);

        ss >> A.vardas >> A.pavarde;

        int x;
        while (ss >> x) {
            A.paz.push_back(x);
        }

        A.egz = A.paz.back();
        A.paz.pop_back();

        for (int p : A.paz) sum += p;

        skaiciuoti(A, sum);
        grupe.push_back(A);
    }

    in.close();
}

void output(const vector<studentas> &grupe) {
    cout << left << setw(12) << "Vardas"
         << left << setw(15) << "Pavarde"
         << setw(20) << "Galutinis" << endl;

    cout << "----------------------------------------------\n";

    for (const auto &A : grupe) {
        cout << left << setw(12) << A.vardas
             << left << setw(15) << A.pavarde
             << setw(20) << fixed << setprecision(2) << A.rez << endl;
    }
}

int main() {
    vector<studentas> grupe;

    skaitymas(grupe, "kursiokai.txt");
    output(grupe);

    return 0;
}