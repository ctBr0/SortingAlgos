# ifndef SORTINGALGOS_H
# define SORTINGALGOS_H

# include <vector>
# include <iostream>

using namespace std;

void printVector(vector<int> A);
void buildMaxHeap(vector<int> A);
void heapify(vector<int> A, int parent);
vector<int> insertionSort(vector<int> A);
vector<int> selectionSort(vector<int> A);
vector<int> bubbleSort(vector<int> A);
vector<int> mergeSort(vector<int> A);
vector<int> merge(vector<int> A, vector<int> B);
vector<int> heapSort(vector<int> A);



# endif
