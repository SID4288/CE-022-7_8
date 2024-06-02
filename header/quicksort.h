
#include <iostream>
int partition(a,int high,int low)
{
    int pivot =high/2;
    int i=low;
    int j=high+1;
    while(i<j)
    {
        while(a[i]<a[pivot])
        {
            i++;
        }   
        while(a[j]>a[pivot])
        {
            j--;
        }
        if(i<j)
        {
            std::swap(a[i],a[j]);
        }
        s

    }
}