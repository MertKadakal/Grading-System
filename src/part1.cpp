//
// Created by HP on 3.10.2024.
//

#include "part1.h"
#include "ogrenci.h"

void part1::execute() {
ifstream dosya("inputs/part1_input.txt");

    if (!dosya.is_open())
    {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    float total_grades = 0;
    float max_score = 0;
    float min_score = 100;
    vector<Ogrenci> ogrenciler;
    map<string, int> grades = {
        {"A1", 0},
        {"A2", 0},
        {"A3", 0},
        {"B1", 0},
        {"B2", 0},
        {"B3", 0},
        {"C1", 0},
        {"C2", 0},
        {"C3", 0},
        {"D", 0},
        {"F", 0}
    };

    string satir;
    while (getline(dosya, satir)) {
        stringstream ss(satir);  // Her satırı bir stringstream'e koyuyoruz
        string mid1;
        string mid2;
        getline(ss, mid1, '\t');  // Tab'a göre ilk kısmı alıyoruz
        getline(ss, mid2, '\t');  // Tab'a göre ilk kısmı alıyoruz

        ogrenciler.push_back(Ogrenci(stoi(mid1), stoi(mid2), 101));
    }
    dosya.close();


    for (Ogrenci& ogrenci :ogrenciler) {
        float ortalama = ogrenci.mid1*0.4 + ogrenci.mid2*0.6;

        if (ortalama > max_score) {
            max_score = ortalama;
        }
        if (ortalama < min_score) {
            min_score = ortalama;
        }

        total_grades += ortalama;
        if (ortalama >= 95) {
            grades["A1"] += 1;
        } else if (ortalama >= 90) {
            grades["A2"] += 1;
        } else if (ortalama >= 85) {
            grades["A3"] += 1;
        } else if (ortalama >= 80) {
            grades["B1"] += 1;
        } else if (ortalama >= 75) {
            grades["B2"] += 1;
        } else if (ortalama >= 70) {
            grades["B3"] += 1;
        } else if (ortalama >= 65) {
            grades["C1"] += 1;
        } else if (ortalama >= 60) {
            grades["C2"] += 1;
        } else if (ortalama >= 55) {
            grades["C3"] += 1;
        } else if (ortalama >= 50) {
            grades["D"] += 1;
        } else {
            grades["F"] += 1;
        }
    }

    ofstream dosya1("outputs/part1_output.txt");
    if (dosya1.is_open()) { // Dosya başarıyla açıldıysa
        dosya1 << "- - - - - - - - - -" << endl;
        dosya1 << "BBM201 Statistics (Part 1)" << endl;
        dosya1 << "- - - - - - - - - -" << endl;

        for (const auto& pair : grades) {
            dosya1 << pair.first << ": " << pair.second << endl;
        }

        dosya1 << "--------------------" << endl;
        dosya1 << "Total number of students: " + to_string(ogrenciler.size()) << endl;
        dosya1 << "Average of grades: " << total_grades/ogrenciler.size() << endl;
        dosya1 << "Max score: " << max_score << endl;
        dosya1 << "Min score: " << min_score << endl;
        dosya1 << "--------------------";
        dosya1.close(); // Dosyayı kapat
    }
}