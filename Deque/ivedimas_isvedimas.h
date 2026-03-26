#ifndef IVEDIMAS_ISVEDIMAS_H
#define IVEDIMAS_ISVEDIMAS_H

#include "studentas.h"
#include <deque>
#include <ostream>

using std::deque;
//////////////void output(std::ostream &out, const vector<studentas> &grupe);
void input(deque<studentas> &grupe);
void output(std::ostream &out, const deque<studentas> &grupe);
void rusiuotistud(deque<studentas> &grupe);
void skaitymas(const string &failo_pav, deque<studentas> &grupe);
void skaitymas_rez(const string &failo_pav, deque<studentas> &grupe);
void padalinti_studentus(const std::deque<studentas> &grupe, std::deque<studentas> &vargsai, std::deque<studentas> &kietuoliai);
#endif