//
// Created by HP on 3.10.2024.
//
#include "part2.h"
#include "ogrenci.h"

vector<Ogrenci> ogrenciler;
map<string, int> grades;

void part2::init_students() {
    ifstream dosya("inputs/part2_input.txt");

    if (!dosya.is_open())
    {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    grades = {
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
        string fnl;
        getline(ss, mid1, '\t');
        getline(ss, mid2, '\t');
        getline(ss, fnl, '\t');

        ogrenciler.push_back(Ogrenci(stoi(mid1), stoi(mid2), stoi(fnl)));
    }
    dosya.close();
}

void part2::reset_grades_map() {
    grades = {
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
}

void part2::no_curve() {
    //calculate the average score of the class
    float total_score;
    float average_score_of_the_class;
    for (Ogrenci& ogrenci :ogrenciler) {
        total_score += ogrenci.ortalama;
    }
    average_score_of_the_class = total_score/ogrenciler.size();

    float max_score = 0;
    float min_score = 100;
    float total_grades;

    for (Ogrenci& ogrenci :ogrenciler) {

        if (ogrenci.ortalama > max_score) {
            max_score = ogrenci.ortalama;
        }
        if (ogrenci.ortalama < min_score) {
            min_score = ogrenci.ortalama;
        }

        total_grades += ogrenci.ortalama;
        if (ogrenci.ortalama >= 95) {
            grades["A1"] += 1;
        } else if (ogrenci.ortalama >= 90) {
            grades["A2"] += 1;
        } else if (ogrenci.ortalama >= 85) {
            grades["A3"] += 1;
        } else if (ogrenci.ortalama >= 80) {
            grades["B1"] += 1;
        } else if (ogrenci.ortalama >= 75) {
            grades["B2"] += 1;
        } else if (ogrenci.ortalama >= 70) {
            grades["B3"] += 1;
        } else if (ogrenci.ortalama >= 65) {
            grades["C1"] += 1;
        } else if (ogrenci.ortalama >= 60) {
            grades["C2"] += 1;
        } else if (ogrenci.ortalama >= 55) {
            grades["C3"] += 1;
        } else if (ogrenci.ortalama >= 50) {
            grades["D"] += 1;
        } else {
            grades["F"] += 1;
        }
    }

    ofstream dosya1("outputs/part2_no_curve.txt");
    if (dosya1.is_open()) { // Dosya başarıyla açıldıysa
        dosya1 << "- - - - - - - - - -\n"
                  "BBM201 Statistics\n"
                  "(Without Curve)\n"
                  "- - - - - - - - - -" << endl;

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

void part2::curve_1() {
    //calculate the average score of the class
    float total_score = 0;
    float average_score_of_the_class;
    for (Ogrenci& ogrenci :ogrenciler) {
        total_score += ogrenci.ortalama;
    }
    average_score_of_the_class = total_score/ogrenciler.size();
    reset_grades_map();

    float score_to_plus;
    if (average_score_of_the_class < 50) {
        score_to_plus = 50 - average_score_of_the_class;
    } else {
        score_to_plus = 0;
    }

    float max_score = 0;
    float min_score = 100;
    float total_grades = 0;

    for (Ogrenci& ogrenci :ogrenciler) {
        ogrenci.ortalama += score_to_plus;

        if (ogrenci.ortalama > 100) {
            ogrenci.ortalama = 100;
        }

        if (ogrenci.ortalama > max_score) {
            max_score = ogrenci.ortalama;
        }
        if (ogrenci.ortalama < min_score) {
            min_score = ogrenci.ortalama;
        }

        total_grades += ogrenci.ortalama;
        if (ogrenci.ortalama >= 95) {
            grades["A1"] += 1;
        } else if (ogrenci.ortalama >= 90) {
            grades["A2"] += 1;
        } else if (ogrenci.ortalama >= 85) {
            grades["A3"] += 1;
        } else if (ogrenci.ortalama >= 80) {
            grades["B1"] += 1;
        } else if (ogrenci.ortalama >= 75) {
            grades["B2"] += 1;
        } else if (ogrenci.ortalama >= 70) {
            grades["B3"] += 1;
        } else if (ogrenci.ortalama >= 65) {
            grades["C1"] += 1;
        } else if (ogrenci.ortalama >= 60) {
            grades["C2"] += 1;
        } else if (ogrenci.ortalama >= 55) {
            grades["C3"] += 1;
        } else if (ogrenci.ortalama >= 50) {
            grades["D"] += 1;
        } else {
            grades["F"] += 1;
        }
    }

    ofstream dosya1("outputs/part2_curve1.txt");
    if (dosya1.is_open()) { // Dosya başarıyla açıldıysa
        dosya1 << "- - - - - - - - - -\n"
                  "BBM201 Statistics\n"
                  "(Curve Type 1 - Increase Average)\n"
                  "- - - - - - - - - -" << endl;

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

void part2::curve_2() {
    //calculate the average score of the class
    float max_score = 0;
    float min_score = 100;
    float total_grades;

    for (Ogrenci& ogrenci :ogrenciler) {
        if (ogrenci.ortalama > max_score) {
            max_score = ogrenci.ortalama;
        };
    }
    float score_to_plus = 100 - max_score;

    reset_grades_map();
    for (Ogrenci& ogrenci :ogrenciler) {
        ogrenci.ortalama += score_to_plus;
        if (ogrenci.ortalama > 100) {
            ogrenci.ortalama = 100;
        }

        if (ogrenci.ortalama > max_score) {
            max_score = ogrenci.ortalama;
        }
        if (ogrenci.ortalama < min_score) {
            min_score = ogrenci.ortalama;
        }

        total_grades += ogrenci.ortalama;
        if (ogrenci.ortalama >= 95) {
            grades["A1"] += 1;
        } else if (ogrenci.ortalama >= 90) {
            grades["A2"] += 1;
        } else if (ogrenci.ortalama >= 85) {
            grades["A3"] += 1;
        } else if (ogrenci.ortalama >= 80) {
            grades["B1"] += 1;
        } else if (ogrenci.ortalama >= 75) {
            grades["B2"] += 1;
        } else if (ogrenci.ortalama >= 70) {
            grades["B3"] += 1;
        } else if (ogrenci.ortalama >= 65) {
            grades["C1"] += 1;
        } else if (ogrenci.ortalama >= 60) {
            grades["C2"] += 1;
        } else if (ogrenci.ortalama >= 55) {
            grades["C3"] += 1;
        } else if (ogrenci.ortalama >= 50) {
            grades["D"] += 1;
        } else {
            grades["F"] += 1;
        }
    }

    ofstream dosya1("outputs/part2_curve2.txt");
    if (dosya1.is_open()) { // Dosya başarıyla açıldıysa
        dosya1 << "- - - - - - - - - -\n"
                  "BBM201 Statistics\n"
                  "(Curve Type 2 - Increase Max Score)\n"
                  "- - - - - - - - - -" << endl;

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

void part2::curve_3() {
    float max_score = 0;
    float min_score = 100;
    float total_grades = 0;

    vector<float> grades1;
    for (Ogrenci& ogrenci :ogrenciler) {
        grades1.push_back(ogrenci.ortalama);
    }
    sort(grades1.begin(), grades1.end());

    int lower_bound = grades1.size() / 4;
    float lower_bound_ortalama = grades1[lower_bound];

    float score_to_plus = 50 - grades1[lower_bound];



    reset_grades_map();
    for (Ogrenci& ogrenci :ogrenciler) {
        ogrenci.ortalama += score_to_plus;
        total_grades += ogrenci.ortalama;
        if (ogrenci.ortalama > lower_bound_ortalama) {
            if (ogrenci.ortalama >= 95) {
                grades["A1"] += 1;
            } else if (ogrenci.ortalama >= 90) {
                grades["A2"] += 1;
            } else if (ogrenci.ortalama >= 85) {
                grades["A3"] += 1;
            } else if (ogrenci.ortalama >= 80) {
                grades["B1"] += 1;
            } else if (ogrenci.ortalama >= 75) {
                grades["B2"] += 1;
            } else if (ogrenci.ortalama >= 70) {
                grades["B3"] += 1;
            } else if (ogrenci.ortalama >= 65) {
                grades["C1"] += 1;
            } else if (ogrenci.ortalama >= 60) {
                grades["C2"] += 1;
            } else if (ogrenci.ortalama >= 55) {
                grades["C3"] += 1;
            } else if (ogrenci.ortalama >= 50) {
                grades["D"] += 1;
            } else {
                grades["F"] += 1;
            }

        }

        if (ogrenci.ortalama  > max_score) {
            max_score = ogrenci.ortalama ;
        }
        if (ogrenci.ortalama  < min_score) {
            min_score = ogrenci.ortalama ;
        }


    }
    grades["F"] = lower_bound;

    ofstream dosya1("outputs/part2_curve3.txt");
    if (dosya1.is_open()) { // Dosya başarıyla açıldıysa
        dosya1 << "- - - - - - - - - -\n"
                  "BBM201 Statistics\n"
                  "(Curve Type 3 - Fail %25)\n"
                  "- - - - - - - - - -" << endl;

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
