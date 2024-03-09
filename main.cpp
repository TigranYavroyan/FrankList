#include "franklist.h"
#include <vector>

using namespace vhuk;
using std::vector;

int main () {
	// FrankList ml1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FrankList ml1 = {1, 4, 6};
    FrankList ml2 = {7, 1, 2};
    auto i = ml2.begin();
    auto j = ml2.end();
    // for (int i = 0; i < 4; ++i) {
    //     ml1.insert(ml1.begin(), 7);
    // }
    FrankList<int>::iterator b = ml1.begin();
    // ++b;
    // ++b;
    // ++b;


    // FrankList<int>::size_type s = 1;
    // FrankList<int>::const_reference r = 4;
    // ml1.insert(b, s, r);
    // ml1.insert(b, s, r);
    // ml1.insert(ml1.begin(), s, r);
    // ml1.insert(ml1.end(), s, r);
    // ml1.insert(ml1.begin(), s, r);
    // ml1.insert(ml1.end(), s, r);
    // ml1.insert(ml1.begin(), s, r);

    // ml1.insert(ml1.begin(), i, j);
    


    ml1.insert(ml1.begin(), i, j);
    ml1.insert(b, 20);
    //ml2.clear();
    //it = it2;
   //FrankList ml1 = {1, 2, 3, 4};
    // FrankList<int>::iterator it = ml1.begin();
    // ++it;
    // ++it;
    // ++it;
    //std::cout << ml1.remove_if([](int a){ return a % 2 == 0;}) << std::endl;
    ml1.print();
}