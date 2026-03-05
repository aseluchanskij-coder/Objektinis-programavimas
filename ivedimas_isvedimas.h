#ifndef IVEDIMAS_ISVEDIMAS_H
#define IVEDIMAS_ISVEDIMAS_H

#include "studentas.h"
#include <vector>
#include <ostream>

using std::vector;
//////////////void output(std::ostream &out, const vector<studentas> &grupe);
void input(vector<studentas> &grupe);
void output(std::ostream &out, const vector<studentas> &grupe);
void rusiuotistud(vector<studentas> &grupe);
void skaitymas(const string &failo_pav, vector<studentas> &grupe);

#endif