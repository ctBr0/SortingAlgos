# include <iostream>
# include "../include/SortingAlgos.h"
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

    vector<int> original;
    bool cont = false;
    while (!cont)
    {
        switch (input)
        {
            case 1:
                original = {435,341,54,54,35463,56,3245,65,88976,67857,546,43,213,4,325,42,2345,5467,27,456,87,548};
                cont = true;
                break;
            case 2:
                cout << "Enter the size of the vector: (Recommended: 1000)" << endl;
                cin >> input;
                for (int i=0;i<input;i++)
                {
                    original.push_back(rand()%100);
                }
                cont = true;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }

    //original array
    cout << "Original: (" + to_string(original.size()) + " elements)" << endl;
    printVector(original);

    //array to be sorted
    vector<int> newArr;

    //execution time
    time_point<steady_clock> start, stop;
    microseconds duration;

    //insertion sort
    cout << "Insertion sort: (O(n^2))" << endl;
    start = steady_clock::now();
    newArr = insertionSort(original);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newArr);

    //selection sort
    cout << "Selection sort: (O(n^2))" << endl;
    start = steady_clock::now();
    newArr = selectionSort(original);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newArr);

    //bubble sort
    cout << "Bubble sort: (O(n^2))" << endl;
    start = steady_clock::now();
    newArr= bubbleSort(original);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newArr);

    //merge sort
    cout << "Merge sort: (O(nlogn))" << endl;
    start = steady_clock::now();
    newArr= mergeSort(original);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newArr);

    //heap sort
    cout << "Heap sort: (O(nlogn))" << endl;
    start = steady_clock::now();
    newArr = heapSort(original);
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newArr);

    //heap sort
    cout << "Quick sort: (O(nlogn))" << endl;
    start = steady_clock::now();
    newArr = quickSort(original,0,original.size());
    stop = steady_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    printVector(newArr);

    return 0;
}