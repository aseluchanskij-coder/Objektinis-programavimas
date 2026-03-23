#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <string>
#include <vector>  
#include "studentas.h"
void failo_kurimo_testas(int kiek);
void skaitymas_is_galutinio(const std::string& failas, std::vector<studentas>& grupe);
void apdorojimo_testas(const std::string& failas);

#endif