#include "Fibonacci.h"
#include <iostream>
#include <chrono>

int Fibonacci::iteratively(int times_to_run)
{
    int y = 0, x = 1, z = 0;
    for (int i = 0; i < times_to_run; i++)
    {
        z = x + y;
        int even = i%2;
        if (even == 0)
        {
            x = z;
        }
        else
            y = z;
    }
    return z;
}

int Fibonacci::recursively(int n)
{
    if(n==1||n==0){
        return n;
    }
    return recursively(n-1)+recursively(n-2);
}

void Fibonacci::test(int n)
{
    cout << "Getting " << n << "th Fibonacci number" << endl; 
    auto start = chrono::high_resolution_clock::now();
    cout << recursively(n) << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Recursive Fibonacci Took " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << iteratively(n) << endl;
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Iterative Fibonacci Took " << duration.count() << " microseconds" << endl;
}