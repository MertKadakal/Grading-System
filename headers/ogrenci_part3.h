//
// Created by HP on 3.10.2024.
//

#ifndef OGRENCI_PART3_H
#define OGRENCI_PART3_H
#include "includes_file.h"

class OgrenciPart3 {
    public:
        int mid1;
        int final;
        string isim;
        string id;
        string odevler;
        OgrenciPart3(string ism, string id1, int m1, int fnl, string odevler1) {
            mid1 = m1;
            final = fnl;
            isim = ism;
            id = id1;
            odevler = odevler1;
        }
    bool operator<(const OgrenciPart3& other) const {
            return id < other.id; // id'ye göre karşılaştırma
        }
};
#endif //OGRENCI_PART3_H
