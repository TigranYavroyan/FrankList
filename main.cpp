#include "franklist.h"

using namespace vhuk;

int main () {
    FrankList<int>::size_type a = 10;
    FrankList<int>::value_type b = 5;
   // FrankList<int> ml = {1, 2, 3, 4, 5};
    //FrankList<int> ml2 = ml;
    FrankList ml3 = {9, 8 ,7, 6, 4, 2 ,1};
    ml3.print(true);
}