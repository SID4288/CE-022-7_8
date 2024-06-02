partition(a,high,low)
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

    }
}