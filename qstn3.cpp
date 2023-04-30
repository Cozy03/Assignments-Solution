#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

//Function for primality check
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

// Function that returns the least no of oparations to compute 2^37
int num_operations(int p) {
    assert(is_prime(p));
    int num_ops = 0;
    int power = 37;
    while (power > 0) {
        if (power == 1) {
            num_ops++;
            break;
        }
        int k = log2(power);
        int x = pow(2, k);
        if (x >= p) {
            x /= 2;
            k--;
        }
        power -= x;
        num_ops++;
    }
    return num_ops;
}

int main() {
    int p;
    cout << "Enter a prime number p: ";
    cin >> p;
    assert(is_prime(p));// Checks if the input is prime or not
    int ops = num_operations(p);
    cout << "Number of operations required to compute 2^37 (mod p): " << ops << endl;
    return 0;
}
