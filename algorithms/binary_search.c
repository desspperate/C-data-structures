#include "./binary_search.h"

int bin_search(int* arr, unsigned long int length, int value)
{
    if (length == 0)
    {
        return NOT_FOUND;
    }
    int left_border = 0;
    int right_border = length - 1;

    while (left_border <= right_border)
    {
        int mid = (int)((left_border + right_border) / 2); 

        if (*(arr + mid) == value)
        {
            return mid;
        }
        else if (value > *(arr + mid))
        {
            left_border = mid + 1;
        }
        else 
        {
            right_border = mid - 1;
        }
    }

    return NOT_FOUND;
}