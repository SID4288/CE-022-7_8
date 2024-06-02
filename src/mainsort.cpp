#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../header/insertion.h"
int main()
{
    std::vector<int> arr;
    int n=50;
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
    std::cout << "After sorting: ";
     for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

}