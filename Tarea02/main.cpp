#include <iostream>
#include <FlightCodeGenerator.h>

using namespace std;

int main()
{
    cout << "Random code: " << endl;
    FlightCodeGenerator generator;
    generator.generate_code();
    generator.generate_code();

    return 0;
}
