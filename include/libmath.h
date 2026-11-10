#pragma once

namespace libmath
{
    inline int addition(int a, int b, int& result) 
    {
        if ((b > 0 && a > __INT_MAX__ - b) || (b < 0 && a < (-__INT_MAX__ - 1) - b)) 
        {
            return -5; 
        }
        result = a + b;
        return 0;
    }

    inline int subtraction(int a, int b, int& result) 
    {
        if ((b > 0 && a < (-__INT_MAX__ - 1) + b) || (b < 0 && a > __INT_MAX__ + b)) 
        {
            return -5; 
        }
        result = a - b;
        return 0;
    }

    inline int multiplication(int a, int b, int& result) 
    {
        if (a > 0) 
        {
            if (b > 0 && a > __INT_MAX__ / b) return -5;
            if (b < 0 && b < (-__INT_MAX__ - 1) / a) return -5;
        } 
        else 
        {
            if (b > 0 && a < (-__INT_MAX__ - 1) / b) return -5;
            if (b < 0 && a != 0 && b < __INT_MAX__ / a) return -5;
        }
        result = a * b;
        return 0;
    }

    inline int division(int a, int b, int& result) 
    {
        if (b == 0) 
        {
            return -1; 
        }
        if (a == (-__INT_MAX__ - 1) && b == -1) 
        {
            return -5; 
        }
        result = a / b;
        return 0;
    }

    inline int power(int a, int b, int& result) 
    {
        if (b < 0) 
        {
            return -2; 
        }
        
        int res = 1;
        for (int i = 0; i < b; ++i) 
        {
            int temp_status = multiplication(res, a, res);
            if (temp_status != 0) return temp_status;
        }
        result = res;
        return 0;
    }

    inline int factorial(int a, int& result) 
    {
        if (a < 0) 
        {
            return -3; 
        }
        if (a == 0 || a == 1) 
        {
            result = 1;
            return 0;
        }

        int sub_res = 0;
        int status = factorial(a - 1, sub_res);
        if (status != 0) return status; 

        if (__INT_MAX__ / a < sub_res) 
        {
            return -5; 
        }

        result = a * sub_res;
        return 0;
    }
}

