#include <iostream>
#include <cassert>
using namespace std;

bool is_prime(int p) {
    if (p <= 1)
        return false;
    else if (p <= 3)
        return true;
    else if (p % 2 == 0 || p % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= p) {
        if (p % i == 0 || p % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int main() {
    // Type 1: Test for negative input
    assert(is_prime(-7) == false);
    assert(is_prime(-8) == false);

    cout << "Assertions type 1 passed!" << endl;

    // Type 2: Test for zero input
    assert(is_prime(0) == false);

    cout << "Assertions type 2 passed!" << endl;

    // Type 3: Test for positive prime input
    assert(is_prime(2) == true);
    assert(is_prime(3) == true);
    assert(is_prime(5) == true);
    assert(is_prime(7) == true);
    assert(is_prime(17) == true);
    assert(is_prime(10007) == true);

    cout << "Assertions type 3 passed!" << endl;

    // Type 4: Test for positive composite input
    assert(is_prime(4) == false);
    assert(is_prime(9) == false);
    assert(is_prime(16) == false);
    assert(is_prime(81) == false);
    assert(is_prime(525) == false);
    assert(is_prime(2048) == false);

    cout << "Assertions type 4 passed!" << endl;
    return 0;
}
