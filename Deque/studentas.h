#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <deque>

using std::string;
using std::deque;

struct studentas {
    string vardas;
    string pavarde;
    deque<int> paz;
    int egz;
    double rez;
    string tipas;
};

void skaiciuoti(studentas &A, int sum);

bool pagalVarda(const studentas &a, const studentas &b);
bool pagalPavarde(const studentas &a, const studentas &b);
bool pagalVid(const studentas &a, const studentas &b);
bool pagalMed(const studentas &a, const studentas &b);

#endif