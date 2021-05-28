#include "MD5.h"
#include <iostream>
using namespace std;

int main() {
    MD5 m;
    cout << m.encrypt("abcd") << endl;
    cout << m.encrypt("abc") << endl;

    return 0;
}