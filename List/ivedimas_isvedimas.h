#ifndef IVEDIMAS_ISVEDIMAS_H
#define IVEDIMAS_ISVEDIMAS_H

#include "studentas.h"
//#include <vector>
#include <list>
#include <ostream>

using std::list;
//////////////void output(std::ostream &out, const list<studentas> &grupe);
void input(list<studentas> &grupe);
void output(std::ostream &out, const list<studentas> &grupe);
void rusiuotistud(list<studentas> &grupe);
void skaitymas(const string &failo_pav, list<studentas> &grupe);
void skaitymas_rez(const string &failo_pav, list<studentas> &grupe);
void padalinti_studentus(const std::list<studentas> &grupe, std::list<studentas> &vargsai, std::list<studentas> &kietuoliai);
#endif