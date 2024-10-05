//
// Created by HP on 3.10.2024.
//

#ifndef PART2_H
#define PART2_H
#include "includes_file.h"
using namespace std;

class part2 {
    public:
        void reset_grades_map();
        void init_students();
        void no_curve();
        void curve_1(); //consider average score
        void curve_2(); //consider highest score
        void curve_3(); //consider fixed number of students to fail
};
#endif //PART2_H
