
#include <iostream>
int partition(std::vector<int>& a,int high,int low)
{
    int pivot =a[low];
    int i=low;
    int j=high+1;
    while(i<j)
    {
        while(a[i]<pivot)
        {
            i++;
        }   
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            std::swap(a[i],a[j]);
        }
        std::swap(a[low],a[j]);
        return j;

    }
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}