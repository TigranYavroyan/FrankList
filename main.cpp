#include "franklist.h"

using namespace vhuk;

int main () {
    FrankList<int>::size_type a = 10;
    FrankList<int>::value_type b = 5;
   // FrankList<int> ml = {1, 2, 3, 4, 5};
    //FrankList<int> ml2 = ml;
    FrankList ml3 (a, b);
    //ml.print(false, true);
    //ml = {2, 4, 5, 6, 6,7};
    //ml.print();
    ml3.print();
}