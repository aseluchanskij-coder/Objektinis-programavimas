#include "studentas.h"
#include <algorithm>

using std::sort;

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

bool pagalVarda(const studentas &a, const studentas &b) {
    return a.vardas < b.vardas;
}

bool pagalPavarde(const studentas &a, const studentas &b) {
    return a.pavarde < b.pavarde;
}

bool pagalVid(const studentas &a, const studentas &b) {
    return (a.tipas == "vid" ? a.rez : -1) < (b.tipas == "vid" ? b.rez : -1);
}

bool pagalMed(const studentas &a, const studentas &b) {
    return (a.tipas == "med" ? a.rez : -1) > (b.tipas == "med" ? b.rez : -1);
}
bool pagalRez(const studentas &a, const studentas &b) {
    return a.rez > b.rez; }

