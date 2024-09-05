#include <iostream>
#include <random>
#include <string>
using namespace std;

unsigned xorshift32( unsigned v ) {
    v = v ^ ( v << 13 );
    v = v ^ ( v >> 17 );
    v = v ^ ( v << 15 );
    return v;
}
float getGrad( int x, int y, int elem, int seed = 0 ) {
    unsigned r = xorshift32( x + seed );
    r = xorshift32( r + y );
    r = xorshift32( r + elem ) % 10000;
    return (float)r / 5000 - 1.0f;
}
int main()
{
    for (int i = 0; i < 10; i++) {
        std::cout << xorshift32(i+1) << std::endl;
    }
    return 0;
}
