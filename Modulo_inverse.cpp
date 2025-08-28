#include <iostream>
using namespace std;

// Function to compute modular inverse of b mod m
int modinv(int b, int m)
{
    int orig_m = m;
    int x0 = 0, x1 = 1;

    // Extended Euclidean Algorithm loop
    while (b > 0)
    {
        int q = m / b;
        int temp = b;
        b = m % b;
        m = temp;

        int temp_x = x0;
        x0 = x1 - q * x0;
        x1 = temp_x;
    }

    // If gcd is not 1, inverse doesn't exist
    if (m != 1)
        return -1;

    // Ensure the result is positive
    return (x1 + orig_m) % orig_m;
}
