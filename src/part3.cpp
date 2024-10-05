//
// Created by HP on 3.10.2024.
//

#include "part3.h"
#include "ogrenci_part3.h"

vector<OgrenciPart3> ogrenciler3;
map<string, int> grades3;
map<string, string> names_and_letters_vector;
map<OgrenciPart3, float> students_and_gpas;

float overall_of_assignments(string& odevler, string& id) {
    istringstream iss(odevler);
    string number;
    vector<int> assignments;

    // String'deki sayıları al ve vektöre ekle
    while (iss >> number) {
        assignments.push_back(stoi(number));
    }

    int total = 0;
    for (int grade : assignments) {
        total += grade;
    }
    return 0.06*total;
}

bool check_assignments(string& odevler) {
    istringstream iss(odevler);
    string number;
    vector<int> assignments;

    // String'deki sayıları al ve vektöre ekle
    while (iss >> number) {
        assignments.push_back(stoi(number));
    }

    int zeros = 0;
    // Sıfır olan sayıları say
    for (int grade : assignments) {
        if (grade == 0) {
            zeros++;
        }
    }

    // Sıfır sayısı 2'den fazla mı?
    if (zeros > 1) {
        return true;
    }
    return false;
}

// İsimlere göre sıralama yapmak için karşılaştırma fonksiyonu
bool isimKarsilastir(const OgrenciPart3 &a, const OgrenciPart3 &b) {
    if (a.isim == b.isim) {
        return a.id < b.id;
    }
    return a.isim < b.isim;
}

// İsimlere göre sıralama yapmak için karşılaştırma fonksiyonu
bool idKarsilastir(const OgrenciPart3 &a, const OgrenciPart3 &b) {
    return stoi(a.id) < stoi(b.id);
}

void part3::execute() {
    ifstream dosya("inputs/part3_input.txt");

    if (!dosya.is_open())
    {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    grades3 = {
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
        {"F1", 0},
        {"F2", 0},
        {"F3", 0},
    };

    string satir;
    while (getline(dosya, satir)) {
        stringstream ss(satir);  // Her satırı bir stringstream'e koyuyoruz
        string mid1;
        string fnl;
        string isim;
        string id;
        string odevler;
        getline(ss, isim, '\t');
        getline(ss, id, '\t');
        getline(ss, mid1, '\t');
        getline(ss, fnl, '\t');
        getline(ss, odevler, '\t');

        ogrenciler3.push_back(OgrenciPart3(isim, id, stoi(mid1), stoi(fnl), odevler));
    }
    dosya.close();

    float max_score = 0;
    float min_score = 100;
    int ogrenci_sayisi = 0;
    float total_grades = 0;
    for (OgrenciPart3& ogrenci : ogrenciler3) {
        float ortalama = ogrenci.mid1*0.3 + ogrenci.final*0.4 + overall_of_assignments(ogrenci.odevler, ogrenci.id);
        total_grades += ortalama;
        ogrenci_sayisi++;
        students_and_gpas[ogrenci] = ortalama;

        if (ortalama > max_score) {
            max_score = ortalama;
        }
        if (ortalama < min_score) {
            min_score = ortalama;
        }

        if (check_assignments(ogrenci.odevler)) {
            grades3["F1"] += 1;
            names_and_letters_vector[ogrenci.id] = "F1";
        } else if (ogrenci.final == 0) {
            grades3["F2"] += 1;
            names_and_letters_vector[ogrenci.id] = "F2";
        } else if (ogrenci.final < 50) {
            grades3["F3"] += 1;
            names_and_letters_vector[ogrenci.id] = "F3";
        } else {
            if (ortalama >= 95) {
                grades3["A1"] += 1;
                names_and_letters_vector[ogrenci.id] = "A1";
            } else if (ortalama >= 90) {
                grades3["A2"] += 1;
                names_and_letters_vector[ogrenci.id] = "A2";
            } else if (ortalama >= 85) {
                grades3["A3"] += 1;
                names_and_letters_vector[ogrenci.id] = "A3";
            } else if (ortalama >= 80) {
                grades3["B1"] += 1;
                names_and_letters_vector[ogrenci.id] = "B1";
            } else if (ortalama >= 75) {
                grades3["B2"] += 1;
                names_and_letters_vector[ogrenci.id] = "B2";
            } else if (ortalama >= 70) {
                grades3["B3"] += 1;
                names_and_letters_vector[ogrenci.id] = "B3";
            } else if (ortalama >= 65) {
                grades3["C1"] += 1;
                names_and_letters_vector[ogrenci.id] = "C1";
            } else if (ortalama >= 60) {
                grades3["C2"] += 1;
                names_and_letters_vector[ogrenci.id] = "C2";
            } else if (ortalama >= 55) {
                grades3["C3"] += 1;
                names_and_letters_vector[ogrenci.id] = "C3";
            } else if (ortalama >= 50) {
                grades3["D"] += 1;
                names_and_letters_vector[ogrenci.id] = "D";
            } else {
                grades3["F3"] += 1;
                names_and_letters_vector[ogrenci.id] = "F3";
            }
        }
    }

    ofstream dosya1("outputs/part3_output.txt");
    if (dosya1.is_open()) { // Dosya başarıyla açıldıysa
        dosya1 << "- - - - - - - - - -\n"
                  "BBM201 Statistics (Part 3)\n"
                  "- - - - - - - - - -\n" << total_grades << endl;

        for (const auto& pair : grades3) {
            if (pair.second == 0) {
                dosya1 << pair.first << ": -" << endl;
            } else {
                dosya1 << pair.first << ": " << pair.second << endl;
            }
        }
        dosya1 << "--------------------" << endl;

        dosya1 << "Total number of students: " + to_string(ogrenciler3.size()) << endl;
        dosya1 << "Average of grades: " << total_grades/ogrenci_sayisi << endl;
        dosya1 << "Max score: " << max_score << endl;
        dosya1 << "Min score: " << min_score << endl;
        dosya1 << "--------------------";

        dosya1.close(); // Dosyayı kapat
    }
}

void part3::names_and_letters() {
    // Öğrencileri isimlerine göre sıralama
    sort(ogrenciler3.begin(), ogrenciler3.end(), isimKarsilastir);

    ofstream dosya1("outputs/part3_names_and_letters.txt");
    if (dosya1.is_open()) {
        dosya1 << "Letters List of BBM201 Course:" << endl;
        dosya1 << "--------------------" << endl;


        for (const auto &ogrenci : ogrenciler3) {
            dosya1 << ogrenci.isim << "\t" << ogrenci.id << "\t" << names_and_letters_vector[ogrenci.id] << std::endl;
        }
        dosya1 << "--------------------";

    }
}

void part3::f1_list() {
    // Öğrencileri idlerine göre sıralama
    sort(ogrenciler3.begin(), ogrenciler3.end(), idKarsilastir);

    ofstream dosya1("outputs/part3_F1_list.txt");
    if (dosya1.is_open()) {
        dosya1 << "Students who will fail BBM201 with F1 Grade:" << endl;
        dosya1 << "--------------------" << endl;

        for (const auto &ogrenci : ogrenciler3) {
            if (names_and_letters_vector[ogrenci.id] == "F1") {
                dosya1 << ogrenci.isim << "\t" << ogrenci.id << std::endl;
            }
        }
        dosya1 << "--------------------";

    }
}

string determine_the_grade(float grade) {
    if (grade >= 95) {
        return "A1";
    } if (grade >= 90) {
        return "A2";
    } if (grade >= 85) {
        return "A3";
    } if (grade >= 80) {
        return "B1";
    } if (grade >= 75) {
        return "B2";
    } if (grade >= 70) {
        return "B3";
    } if (grade >= 65) {
        return "C1";
    } if (grade >= 60) {
        return "C2";
    } if (grade >= 55) {
        return "C3";
    } if (grade >= 50) {
        return "D";
    }
    return "F"; // Geçersiz not için
}

void part3::top10_list() {
    // Öğrencileri idlerine göre sıralama
    // Öğrencileri ve GPA'lerini içeren bir vektör oluştur
    vector<pair<OgrenciPart3, float>> sorted_students(students_and_gpas.begin(), students_and_gpas.end());

    // Vektörü GPA'ye (value) göre sırala
    sort(sorted_students.begin(), sorted_students.end(),
        [](const pair<OgrenciPart3, float>& a, const pair<OgrenciPart3, float>& b) {
            return a.second > b.second; // GPA'yi büyükten küçüğe sıralamak için
        });

    ofstream dosya1("outputs/part3_top10_list.txt");
    if (dosya1.is_open()) {
        dosya1 << "Top 10 Students of BBM201 by GPA:" << endl;
        dosya1 << "--------------------" << endl;

        for (int n = 0; n < 10; n++) {
            dosya1 << sorted_students[n].first.isim << "\t" << sorted_students[n].first.id << "\t" << determine_the_grade(sorted_students[n].second) << "\t" << sorted_students[n].second << endl;
        }
        dosya1 << "--------------------";

    }
}