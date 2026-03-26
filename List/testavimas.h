#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <list>
#include <string>
#include "studentas.h" 

void strategija1(std::list<studentas>& grupe, std::list<studentas>& vargsai, std::list<studentas>& kietuoliai);
void strategija2(std::list<studentas>& grupe, std::list<studentas>& vargsai);
void strategija3(std::list<studentas>& grupe, std::list<studentas>& vargsai);
void failo_kurimo_testas(int kiek);
void apdorojimo_testas(const std::string& failas);

#endif
