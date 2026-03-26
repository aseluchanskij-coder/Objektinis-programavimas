# Objektinis-programavimas
🗂️ Versions / Releases
🔹 v.pradinė

Pirmoji programos iteracija.
Įgyvendintas studentų informacijos įvedimas, galutinio įvertinimo skaičiavimas (pagal vidurkį ir medianą) bei aiškus rezultatų pateikimas.

🔹 v0.1

Sistema pritaikyta darbui su dinamišku studentų ir namų darbų kiekiu.

Realizuoti du sprendimo būdai:

naudojant C masyvus
naudojant std::vector

Papildomai įdiegta atsitiktinio pažymių generavimo funkcija.

🔹 v0.2

Pridėtas duomenų nuskaitymas iš failų (std::vector).

Įgyvendintas lankstus rūšiavimas pagal:

vardą
pavardę
galutinį balą (vidurkis / mediana)

Rezultatai pateikiami tvarkingai išlygiuotu formatu. Programa patikrinta su dideliais duomenų rinkiniais.

🔹 v0.3

Atliktas projekto kodo pertvarkymas.

Kodas išskaidytas į atskirus .cpp ir .h failus, pagerinant struktūrą.
Taip pat įdiegtas klaidų valdymas naudojant išimtis.

🔹 v0.4

Sukurta duomenų generavimo funkcija bei paruošti dideli testiniai failai.

Įgyvendintas studentų skirstymas į grupes pagal galutinį balą, rezultatus išvedant į atskirus failus.
Atlikta veikimo spartos analizė įvairiuose apdorojimo etapuose.

🔹 v1.0

Galutinė versija.

Vektoriu versija prašo vartotojo padaryti pasirinkimą: 1- ranka įvesti studentų vardus bei jų pažymius, 2 - prašo įvesti studento vardus, bet namų darbų bei egzamino pažymiai generuojami atsitiktinai nuo 1 iki 10, 3 - sugeneruoja studentų vardus bei pavardes, analogiškai ir visus gautus pažymius, 4 - nuskaito duomenis iš failo, 5 - nuskaityti is anksto sugeneruota faila, 6 - baigti.
Yra galimybė skaityti duomenis iš failo, taip pat juos rūšiuoti pagal vieną iš penkių parinkčių. Sukurti papildomi funkcionalumai, sukurta daugiau .cpp ir .h failų, panaudota exception handling funckija dviejuose vietuose. Dabartinėje versijoje pridėtas studentų atskirimas į vargšus ir kietuolius, taip pat pridėta galimybė skaityti duomenis iš vartotojo įvesto failo ir rašyti į vartotojo pasirinktą failą. Taip pat yra galimybė atlikti testavimą, o būtent programos veikimo laiko. Buvo atlikti du tyrimai: 1 tyrimas (darbas su failais tik failų sukūrimas, atskira testavimo funkcija):  
failų kūrimas ir jo uždarymas.


📊 Performance Analysis
🖥️ Testavimo aplinka
OS: MacOS
CPU: Apple silicon M1
RAM: 16 GB
Diskas: 512 GB NVMe SSD



2 tyrimas: duomenų apdorojimas:
Duomenų nuskaitymas iš failo;
Studentų rūšiavimas į dvi grupes/kategorijas (į atskirus konteinerius);
Surūšiuotų studentų išvedimas į du naujus failus.
Visos programos veikimo laikas.

REZULTATAI:

 1 TYRIMAS — Failu kurimo sparta

1000 irasu failo kurimo laikas: 0.00373712
10000 irasu failo kurimo laikas: 0.0206178
100000 irasu failo kurimo laikas: 0.112169
1000000 irasu failo kurimo laikas: 0.895016
10000000 irasu failo kurimo laikas: 9.04963

🧾 REZULTATAI.1 — Failų kūrimas

Failų generavimo laikas didėja beveik proporcingai įrašų kiekiui.
Mažiems failams skirtumas minimalus, bet su 10M įrašų pasiekia ~9 s.

2 TYRIMAS - Duomenu apdorojimas
| Failo dydis:                       | 1000        | 10000     | 100000   | 1000000  | 10000000 |
|------------------------------------|-------------|-----------|----------|----------|----------|
| Failo nuskaitymo laikas(s):        | 0.0016515   | 0.0165995 | 0.100474 | 0.964666 | 10.647   |
| Studentų skirstymo laikas(s):      | 0.000661208 | 0.0110059 | 0.050126 | 0.503981 | 4.96271  |
| Įrašymo į failus laikas(s):        | 0.00734433  | 0.0344782 | 0.222286 | 2.22069  | 25.1476  |
| Visos programos veikimo laikas(s): | 0.00967396  | 0.062123  | 0.37293  | 3.68938  | 40.7573  |

⚙️ REZULTATAI.2 — Duomenų apdorojimas

Didžiausią laiko dalį sudaro failų skaitymas ir rašymas.
Skaičiavimai (rūšiavimas, skirstymas) yra žymiai greitesni už I/O operacijas.

3 TYRIMAS - Skirtingų konteinerių naudojimas.

| Failo dydis:                                   | 1000.txt | 10000.txt | 100000.txt | 1000000.txt | 10000000.txt |
|------------------------------------------------|----------|-----------|------------|-------------|--------------|
| Duomenų nuskaitymas iš failų(vector):             | 0.0030 s | 0.0102 s  | 0.0729 s   | 0.6431 s    | 7.1492 s     |
| Duomenų rūšiavimas didėjimo tvarka(vector):       | 0.0002 s | 0.0021 s  | 0.0082 s   | 0.0808 s    | 1.0035 s     |
| Studentų skirstymas į dvi kategorijas (vector):    | 0.0001 s | 0.0006 s  | 0.0018 s   | 0.0243 s    | 0.2549 s     |
| Duomenų nuskaitymas iš failų(deque):           | 0.0025 s | 0.0095 s  | 0.0714 s   | 0.6387 s    | 6.5077 s     |
| Duomenų rūšiavimas didėjimo tvarka(deque):     | 0.0003 s | 0.0022 s  | 0.0101 s   | 0.1026 s    | 1.0970 s     |
| Studentų skirstymas į dvi kategorijas (deque): | 0.0000 s | 0.0004 s  | 0.0019 s   | 0.0244 s    | 0.2338 s     |
| Duomenų nuskaitymas iš failų(list):            | 0.0028 s | 0.0102 s  | 0.0701 s   | 0.6469 s    | 6.5776 s     |
| Duomenų rūšiavimas didėjimo tvarka(list):      | 0.0002 s | 0.0019 s  | 0.0174 s   | 0.4894 s    | 8.5884 s     |
| Studentų skirstymas į dvi kategorijas (list):  | 0.0001 s | 0.0004 s  | 0.0084 s   | 0.1203 s    | 1.2879 s     |

📦 REZULTATAI.3 — Konteineriai

deque ir vector veikia panašiai, tačiau list stipriai atsilieka rūšiavime.
Optimaliausias bendram naudojimui – std::deque.

4 TYRIMAS - 3 grupavimo strategijų taikymas.

| Failo dydis:          | 1000.txt  | 10000.txt | 100000.txt | 1000000.txt  | 10000000.txt |
|-----------------------|-----------|-----------|------------|--------------|--------------|
| 1 Strategija (vector) | 0.00008 s | 0.00072 s | 0.00272 s  | 0.03569 s    | 3.20373      |
| 2 Strategija (vector) | 0.00105 s | 0.11505 s | 9.13686 s  | 1065.17006 s | >15 min      |
| 3 Strategija (vector) | 0.00002 s | 0.00012 s | 0.00164 s  | 0.01999 s    |      -       |
| 1 Strategija (deque)  | 0.00005 s | 0.00045 s | 0.00213 s  | 0.02117 s    | 0.33282 s    |
| 2 Strategija (deque)  | 0.00165 s | 0.06658 s | 4.29863 s  | 455.74734 s  | >15 min      |
| 3 Strategija (deque)  | 0.00016 s | 0.00034 s | 0.00295 s  | 0.03310 s    |      -       |
| 1 Strategija (list)   | 0.00007 s | 0.00059 s | 0.02725 s  | 0.00264 s    | 0.02725 s    |
| 2 Strategija (list)   | 0.00006 s | 0.00041 s | 0.02560 s  | 0.00251 s    | 0.02560 s    |
| 3 Strategija (list)   | 0.00003 s | 0.00018 s | 0.01677 s  | 0.00082 s    | 0.01677 s    |

🔬 REZULTATAI.4 — Strategijos

2 strategija (vector) yra labai neefektyvi ir lėta.
3 strategija (stable_partition) – greičiausia ir rekomenduojama visais atvejais.


🚀 Getting Started
🔧 Reikalavimai
🐧 Linux

Ubuntu / Debian

sudo apt update
sudo apt install cmake g++ make

Fedora

sudo dnf install cmake gcc-c++ make

Arch Linux

sudo pacman -S cmake gcc make
🪟 Windows (MSYS2)
pacman -Syu
pacman -Su
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake make
🍏 macOS
xcode-select --install
brew install cmake
▶️ Paleidimas
git clone -b v1.0 https://github.com/aseluchanskij-coder/Objektinis-programavimas.git 
cd Objektinis-programavimas

mkdir build
cd build

cmake ..
cmake --build .

Paleidimas:

./build/v1.0_vector
./build/v1.0_deque
./build/v1.0_list