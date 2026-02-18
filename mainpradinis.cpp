#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::endl;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egz;
    double rez;
    string tipas; 
};

void input(vector<studentas> &grupe) {
    
    for (int ii = 0; ii < 1; ii++) {
        studentas A;
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;

        cout << "Iveskite studento pazymius. Kiek ju bus? ";
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cout << "Iveskite " << i+1 << " pazymi is: " << n << " : ";
            cin >> temp;
            A.paz.push_back(temp);
            sum += temp;
        }

        cout << "Iveskite egzamino bala: ";
        cin >> A.egz;

        cout << "Pasirinkite ar skaiciuoti vid(vidurkis) ar mediana(med): ";
        cin >> A.tipas;

        double skaicius;

        if (A.tipas == "vid") {
            skaicius = sum * 1.0 / n;
        }
        else { // med
            sort(A.paz.begin(), A.paz.end());
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
         << left << setw(20) << "Pavarde"
         << setw(15) << "Galutinis(vid.)"
         << setw(15) << "Galutinis(med.)" << endl;

    cout << "---------------------------------------------------------------" << endl;

    for (const auto &A : grupe) {
        cout << left << setw(10) << A.vardas
             << left << setw(20) << A.pavarde;

        if (A.tipas == "vid") {
            cout << setw(15) << std::fixed << std::setprecision(2) << A.rez << setw(15) << "-" << endl;
        }
        else {
            cout << setw(15) << "-" << setw(15) << std::fixed << std::setprecision(2) << A.rez << endl;
        }
    }
}

int main() {
    vector<studentas> grupe;
    input(grupe);
    output(grupe);
    return 0;
}
