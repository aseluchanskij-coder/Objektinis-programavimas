#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <deque>
#include <string>
#include "studentas.h" 

void strategija1(std::deque<studentas>& grupe, std::deque<studentas>& vargsai, std::deque<studentas>& kietuoliai);
void strategija2(std::deque<studentas>& grupe, std::deque<studentas>& vargsai);
void strategija3(std::deque<studentas>& grupe, std::deque<studentas>& vargsai);
void failo_kurimo_testas(int kiek);
void apdorojimo_testas(const std::string& failas);

#endif
