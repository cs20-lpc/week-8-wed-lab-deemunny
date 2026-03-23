#include "ArrayStack.hpp"
#include <iostream>
#include <chrono>

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

long long factorialRecursive(unsigned, long long = 1);
long long factorialStack(unsigned);

/*******************************************************************************
 * I didn't vibe with the weird? arbitrary? code of adding 1.1 to a seemingly random number like 3.2.
 * Figured there are other rec functions we've done that could instead be writen via stack.
*******************************************************************************/

int main() {
    unsigned startValue = 0;

    cout << "Enter the starting value for i: ";
    cin  >> startValue;

    cout << "\nFactorial Recursive:\n";
    auto start = chrono::high_resolution_clock::now();
    cout << factorialRecursive(startValue) << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> elapsed = end - start;
    cout << "in " << elapsed.count() << " us." << endl;

    cout << "\nFactorial Iterative:\n";
    start = chrono::high_resolution_clock::now();
    cout << factorialStack(startValue) << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "in " << elapsed.count() << " us." << endl;


    return 0;
}

long long factorialRecursive(unsigned i, long long acc) {
    if (i == 0) return acc;
    return factorialRecursive(i-1, acc * i);
}

long long factorialStack(unsigned i) {
    ArrayStack<unsigned> recStack;
    long long result = 1;

    while (i > 0) {
        recStack.push(i);
        --i;
    }

    while (!recStack.isEmpty()) {
        result *= recStack.peek();
        recStack.pop();
    }

    return result;
}