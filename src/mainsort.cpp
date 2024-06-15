#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "../header/quicksort.h"
#include "../header/insertion.h"

void generate_csv(int n)
{
    std::ofstream file_insertion("insertion_times.csv");
    std::ofstream file_quicksort("quicksort_times.csv");

    file_insertion << "n,time\n";
    file_quicksort << "n,time\n";

    for (int i = 1; i <= n; i++)
    {
        std::vector<int> arr;
        for (int j = 0; j < i; j++)
        {
            arr.push_back(rand() % 100000);
        }

        std::vector<int> arr_insertion = arr;
        std::vector<int> arr_quicksort = arr;

        clock_t start = clock();
        insertion(arr_insertion);
        clock_t stop = clock();
        double insertion_time = (double)(stop - start) / CLOCKS_PER_SEC;

        start = clock();
        quicksort(arr_quicksort, 0, i - 1);
        stop = clock();
        double quicksort_time = (double)(stop - start) / CLOCKS_PER_SEC;

        file_insertion << i << "," << insertion_time << "\n";
        file_quicksort << i << "," << quicksort_time << "\n";
    }

    file_insertion.close();
    file_quicksort.close();
}

int main()
{
    std::vector<int> arr;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }

    std::vector<int> arr_insertion = arr;
    std::vector<int> arr_quicksort = arr;

    std::cout << "Input array for sorting: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    clock_t start = clock();
    insertion(arr_insertion);
    clock_t stop = clock();
    double duration = (double)(stop - start) / CLOCKS_PER_SEC;

    std::cout << "Sorted array by insertion sort: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr_insertion[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Time taken by insertion sort: " << duration << " seconds\n";

    start = clock();
    quicksort(arr_quicksort, 0, 9);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;

    std::cout << "Sorted array by quicksort: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr_quicksort[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Time taken by quicksort: " << duration << " seconds\n";
    generate_csv(10000);
    return 0;
}