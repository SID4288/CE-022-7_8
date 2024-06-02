#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include"../header/quicksort.h"
#include "../header/insertion.h"
int main()
{
    std::vector<int> arr,arr1;
    int n=5;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100);
    }
    std::cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    insertion(arr);
    std::cout << "After insertion sorting: ";
     for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr1.push_back(rand() % 100);
    }   
     std::cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    quicksort(arr1,0,n-1);
    std::cout << "After quick sorting: ";
     for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
}