//
// Created by HP on 3.10.2024.
//

#ifndef OGRENCI_H
#define OGRENCI_H
#include "includes_file.h"

class Ogrenci {
public:
    int mid1;
    int mid2;
    int final;
    string isim;
    float ortalama;
    Ogrenci(int m1, int m2, int fnl) {
        mid1 = m1;
        mid2 = m2;
        final = fnl;
        if (fnl == 101) {
            ortalama = 0.4*m1 + 0.6*m2;
        } else {
            ortalama = 0.3*m1 + 0.3*m2 + 0.4*fnl;
        }

    }
};

#endif //OGRENCI_H
