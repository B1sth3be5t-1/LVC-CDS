#include <iostream>

int fib(int n) {
    if (n == 1 || n == 2) return n;

    return fib(n - 1) + fib(n - 2);
}

using namespace std;

int main() {

    cout << fib(5) << endl;

}
