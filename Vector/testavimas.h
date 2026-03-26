#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <vector>
#include <string>
#include "studentas.h" 

void strategija1(std::vector<studentas>& grupe, std::vector<studentas>& vargsai, std::vector<studentas>& kietuoliai);
void strategija2(std::vector<studentas>& grupe, std::vector<studentas>& vargsai);
void strategija3(std::vector<studentas>& grupe, std::vector<studentas>& vargsai);
void failo_kurimo_testas(int kiek);
void apdorojimo_testas(const std::string& failas);

#endif
