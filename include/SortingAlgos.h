# ifndef SORTINGALGOS_H
# define SORTINGALGOS_H

# include <vector>
# include <iostream>

using namespace std;

void printVector(vector<int>);
vector<int> buildMaxHeap(vector<int>);
vector<int> heapify(vector<int>, int, int);
vector<int> insertionSort(vector<int>);
vector<int> selectionSort(vector<int>);
vector<int> bubbleSort(vector<int>);
vector<int> mergeSort(vector<int>);
vector<int> merge(vector<int>, vector<int>);
vector<int> heapSort(vector<int>);

# endif