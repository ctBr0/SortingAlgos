# include <iostream>
# include "SortingAlgos.h"
# include <vector>
# include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
    int input;

    cout << "1. Hardcoded vector" << endl;
    cout << "2. Randomized vector with no. of elements decided by user" << endl;
    cout << "Select an option: " << endl;

    cin >> input;

    vector<int> A;
    bool cont = false;
    while (!cont)
    {
        switch (input)
        {
            case 1:
                A = {435,341,54,54,35463,56,3245,65,88976,67857,546,43,213,4,325,42,2345,5467,27,456,87,548};
                cont = true;
                break;
            case 2:
                cout << "Enter the size of the vector: (Recommended: 1000)" << endl;
                cin >> input;
                for (int i=0;i<input;i++)
                {
                    A.push_back(rand()%100);
                }
                cont = true;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }

    //original array
    cout << "Original: " << endl;
    printVector(A);

    //array to be sorted
    vector<int> newA;

    //execution time
    time_point<steady_clock> start, stop;
    microseconds duration;

    //insertion sort
    cout << "Insertion sort: (O(n^2))" << endl;
    start = steady_clock::now();
    newA = insertionSort(A);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newA);

    //selection sort
    cout << "Selection sort: (O(n^2))" << endl;
    start = steady_clock::now();
    newA = selectionSort(A);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newA);

    //bubble sort
    cout << "Bubble sort: (O(n^2))" << endl;
    start = steady_clock::now();
    newA = bubbleSort(A);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newA);

    //merge sort
    cout << "Merge sort: (O(nlogn))" << endl;
    start = steady_clock::now();
    newA = mergeSort(A);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newA);

    //heap sort
    cout << "Heap sort: (O(nlogn))" << endl;
    start = steady_clock::now();
    newA = heapSort(A);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newA);

    return 0;
}


