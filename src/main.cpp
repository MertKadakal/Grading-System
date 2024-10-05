
#include "includes_file.h"
#include "part1.h"
#include "part2.h"
#include "part3.h"

using namespace std;

int main()
{
    part1 part1;
    part1.execute();

    part2 part2;
    part2.init_students();
    part2.no_curve();
    part2.curve_1();
    part2.curve_2();
    part2.curve_3();

    part3 part3;
    part3.execute();
    part3.names_and_letters();
    part3.f1_list();
    part3.top10_list();
    return 0;
}
