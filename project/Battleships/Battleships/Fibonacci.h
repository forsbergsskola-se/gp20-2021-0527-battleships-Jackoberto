#pragma once

#include <iostream>
#include <chrono>
using namespace std;

namespace Fibonacci
{
    inline int iteratively(int times_to_run = 5)
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

    inline int recursively(int n = 5)
    {
        if(n==1||n==0){
            return n;
        }
        return recursively(n-1)+recursively(n-2);
    }

    inline void test(int n)
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
}