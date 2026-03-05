#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "studentas.h"
#include "ivedimas_isvedimas.h"

int main() {
    vector<studentas> grupe;

    auto start = std::chrono::high_resolution_clock::now();
   try {
    input(grupe);

    if (!grupe.empty()) { 
        rusiuotistud(grupe);
    }
}
    catch (const std::exception &e) {
        std::cout << "Klaida: " << e.what() << std::endl;
    }
   
    rusiuotistud(grupe);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Laikas: " << elapsed.count() << " sekundes\n";

    return 0;
}