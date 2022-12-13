# include <iostream>
# include <vector>
# include <cmath>
# include "SortingAlgos.h"

using namespace std;

void printVector(vector<int> A)
{
    for (int i=0; i<A.size()-1; i++)
    {
        cout << A[i] << ", ";
    }
    cout << A[A.size()-1] << endl;
}

/*
Insertion sort
1. Left to right
2. Compare each item to its predecssor
3. If key element < predecessor, swap and compare it to the elements before

Time complexity: O(n^2)

for i:1 to length(A)-1
    j=i
    while j>0 and A[j-1]>A[j]
        swap A[j] and A[j-1]
        j=j-1
*/

vector<int> insertionSort(vector<int> A)
{
    for (int i=0; i<A.size(); i++)
    {
        int j=i;
        while (j>0 && A[j-1]>A[j]) //sorts all elements before i
        {
            int temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
            j--;
        }
    }
    return A;
}

/* 
Selection sort
1. Left to right
2. Three pointers: current minimum, current element in sorted partition, current element in unsorted partition
3. Update current minimum
4. Swap current minimum to sorted partition when current element reaches the end of array

Time complexity: O(n^2)

for (j=0;j<n-1;j++)
    int iMin=j;
    for (i=j+1;i<n;i++)
        if (a[i]<a[iMin])
            iMin=i;
    if (iMin!=j)
        swap(a[j],a[iMin]);
*/

vector<int> selectionSort(vector<int> A)
{
    for (int i=0;i<A.size()-1;i++) //i: current element in sorted partition
    {
        int minimum = i;
        for (int j=i+1;j<A.size();j++) //j: current element in unsorted partition
        {
            if (A[j]<A[minimum])
            {
                minimum = j;
            }
        }
        if (minimum != i) //there is an element in the unsorted partition that is less than the current minimum
        {
            int temp = A[i];
            A[i] = A[minimum];
            A[minimum] = temp;
        }
    }
    return A;
}

/*
Bubble sort
1. Left to right
2. Compare two consecutive elements (A[n+1] and A[n])
3. Swap if the A[n+1]>A[n]
4. Sorted partition forms at the end of the vector

Time complexity: O(n^2)

for i from 1 to n
    for j from 0 to n-1
        if a[j]>a[j+1]
            swap(a[j],a[j+1])
*/

vector<int> bubbleSort(vector<int> A)
{
    for (int i=1;i<A.size();i++) //no. of times the bubble iterates
    {
        for (int j=0;j<A.size()-1;j++) //no. of steps for each bubble iteration
        {
            if (A[j]>A[j+1])
            {
                int temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
    return A;
}

/*
Merge sort
1. Done recursively (divide and conquer)
2. Continuously split array in half into individual items
3. Sort and merge

Time complexity: O(nlogn)

mergesort(array a)

    if (n==1)
        return a
    
    array1 = a[0]...a[n/2]
    array2 = a[n/2+1]...a[n]

    array1 = mergesort(array1)
    array2 = mergesort(array2)

    return merge(array1,array2)

merge(array a,array b)

    array c

    while (a and b are not empty)
        if (a[0]>b[0])
            add b[0] to the end of c
            remove b[0] from b
        else
            add a[0] to the end of c
            remove a[0] from a

    while (a has elements)
        add a[0] to the end of c
        remove a[0] from a
    
    while (b has elements)
        add b[0] t the end of c
        remove b[0] from b
    
    return c
*/

vector<int> mergeSort(vector<int> A)
{
    int i;

    if (A.size()==1)
    {
        return A;
    }
    
    //split the vector
    vector<int> part1,part2;
    for (i=0;i<A.size()/2;i++)
    {
        part1.push_back(A[i]);
    }
    for (i=A.size()/2;i<A.size();i++)
    {
        part2.push_back(A[i]);
    }

    //recursive call to further split the vector
    part1 = mergeSort(part1);
    part2 = mergeSort(part2);
    
    //merge and sort separated items
    return merge(part1,part2);
}

vector<int> merge(vector<int> part1, vector<int> part2)
{
    vector<int> merged;
    
    //part1 and part2 themselves are already sorted
    while(part1.size()!=0 && part2.size()!=0)
    {
        if (part1[0]>part2[0])
        {
            merged.push_back(part2[0]);
            part2.erase(part2.begin());
        }
        else
        {
            merged.push_back(part1[0]);
            part1.erase(part1.begin());
        }
    }

    //at this point either part1 or part2 is empty
    //append the remaining elements of the non-empty vector to the merged vector
    while (part1.size()!=0)
    {
        merged.push_back(part1[0]);
        part1.erase(part1.begin());
    }

    while (part2.size()!=0)
    {
        merged.push_back(part2[0]);
        part2.erase(part2.begin());
    }

    return merged;
}

/*
Heap sort
Heap: ordered binary tree
Max heap: parent > child
1. Build max heap (O(n)) - creates max heap from unsorted vector to find the largest element
2. Remove largest element
3. Heapify (O(logn)) - called n-1 times
4. Remove largest element
5. Repeat steps 3 and 4
6. Sorted partition forms at the end of the vector

Time complexity: O(nlogn)

heapsort(array a)

    buildmaxheap(a)

    for i=n to 1
        swap (a[1],a[i])
        n--
        heapify(a, 1)

buildmaxheap(array a)
    n = a.size()
    for i = floor(n/2) to 1
        heapify(a,i)

heapify(array a, int i)

    left = 2i
    right = 2i+1

    if (left<=n) and (a[left]>a[i])
        max = left
    else
        max = i
    
    if (right<=n) and (a[right]>a[max])
        max = right

    if (max!=i)
        swap(a[i],a[max])
        heapify(a,max)
*/

void buildMaxHeap(vector<int> A)
{
    int n=A.size();

    for (int i=floor(n/2);i>0;i--)
    {
        heapify(A,i);
    }
}

void heapify(vector<int> A, int parent)
{
    int leftChild = 2*parent;
    int rightChild = 2*parent+1;
    int max;

    if (leftChild<A.size() && (A[leftChild]>A[parent]))
    {
        max = leftChild;
    }
    else
    {
        max = parent;
    }

    if (rightChild<=A.size() && (A[rightChild]>A[max]))
    {
        max = rightChild;
    }

    if (max!=parent)
    {
        int temp = A[parent];
        A[parent] = A[max];
        A[max] = temp;
        heapify(A,max);
    }
}

vector<int> heapSort(vector<int> A)
{
    buildMaxHeap(A);
    int n = A.size();

    for (int i=n;i>0;i--)
    {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        n--;
        heapify(A,i);
    }
    return A;
}
