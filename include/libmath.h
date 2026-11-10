#pragma once

namespace libmath
{
    inline int addition(int a, int b) 
    {
        return a + b;
    }

    inline int subtraction(int a, int b) 
    {
        return a - b;
    }

    inline int multiplication(int a, int b) 
    {
        return a * b;
    }

    inline int division(int a, int b, int& c) 
    {
        if (b == 0) 
        {
            return -1;
        }
        c = a / b;
        return 0;
    }

    inline int power(int a, int b) 
    {
        int c = 1;
        for (int i = 0; i < b; ++i) 
        {
            c = c * a;
        }
        return c;
    }
}

