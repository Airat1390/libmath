#pragma once

namespace libmath
{
    enum Status
    {
        kSuccess = 0,
        kDivisionByZero = -1,
        kNegativeDegree = -2,
        kNegativeFactorial = -3,
        kOverflow = -5
    };

    inline int addition(int a, int b, int& result) 
    {
        if ((b > 0 && a > __INT_MAX__ - b) || (b < 0 && a < (-__INT_MAX__ - 1) - b)) 
        {
            return kOverflow; 
        }
        result = a + b;
        return kSuccess;
    }

    inline int subtraction(int a, int b, int& result) 
    {
        if ((b > 0 && a < (-__INT_MAX__ - 1) + b) || (b < 0 && a > __INT_MAX__ + b)) 
        {
            return kOverflow; 
        }
        result = a - b;
        return kSuccess;
    }

    inline int multiplication(int a, int b, int& result) 
    {
        if (a > 0) 
        {
            if (b > 0 && a > __INT_MAX__ / b) return kOverflow;
            if (b < 0 && b < (-__INT_MAX__ - 1) / a) return kOverflow;
        } 
        else 
        {
            if (b > 0 && a < (-__INT_MAX__ - 1) / b) return kOverflow;
            if (b < 0 && a != 0 && b < __INT_MAX__ / a) return kOverflow;
        }
        result = a * b;
        return kSuccess;
    }

    inline int division(int a, int b, int& result) 
    {
        if (b == 0) 
        {
            return kDivisionByZero; 
        }
        if (a == (-__INT_MAX__ - 1) && b == -1) 
        {
            return kOverflow; 
        }
        result = a / b;
        return kSuccess;
    }

    inline int power(int a, int b, int& result) 
    {
        if (b < 0) 
        {
            return kNegativeDegree; 
        }
        
        int res = 1;
        for (int i = 0; i < b; ++i) 
        {
            int temp_status = multiplication(res, a, res);
            if (temp_status != kSuccess) return temp_status;
        }
        result = res;
        return kSuccess;
    }

    inline int factorial(int a, int& result) 
    {
        if (a < 0) 
        {
            return kNegativeFactorial; 
        }
        if (a > 12)
        {
            return kOverflow;
        }
        if (a == 0 || a == 1) 
        {
            result = 1;
            return kSuccess;
        }

        int sub_res = 0;
        int status = factorial(a - 1, sub_res);
        if (status != kSuccess) return status; 

        if (__INT_MAX__ / a < sub_res) 
        {
            return kOverflow; 
        }

        result = a * sub_res;
        return kSuccess;
    }
}

