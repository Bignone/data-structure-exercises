#include "FlightCodeGenerator.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

FlightCodeGenerator::FlightCodeGenerator()
{
    //ctor
}

void FlightCodeGenerator::generate_code()
{
    char s[7];
    static const char nums[] = "0123456789";
    static const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 3; ++i) {
        s[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    for (int i = 3; i < 7; ++i) {
        s[i] = nums[rand() % (sizeof(nums) - 1)];
    }
    cout << s <<endl;
}
