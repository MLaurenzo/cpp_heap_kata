#include "heap_utils.h"

#include <iostream>
#include <algorithm>

using namespace std;

void print(const vector<int>& v)
{
    int i = 0;
    for_each(v.begin(), v.end(), [](int e) { cout << e << " "; });
    cout << endl;
}

int getParentIndex(int currentIndex)
{
    return (currentIndex - 1) / 2;
}

int getLeftChildIndex(int currentIndex)
{
    return 2*currentIndex + 1;
}

int getRightChildIndex(int currentIndex)
{
    return 2*currentIndex + 2;
}

void sift_up(vector<int>& v, int currentIndex)
{
    while (currentIndex > 0)
    {
        int parentIndex = getParentIndex(currentIndex);

        if (v[parentIndex] >= v[currentIndex]) return;
        swap(v[parentIndex], v[currentIndex]);
        currentIndex = parentIndex;
    }
}

void sift_down(vector<int>& v, int heap_size)
{
    int currentIndex = 0;
    while (true)
    {
        int leftChildIndex = getLeftChildIndex(currentIndex);
        if (leftChildIndex > heap_size) return;

        int rightChildIndex = getRightChildIndex(currentIndex);
        if (rightChildIndex <= heap_size
                && v[currentIndex] < v[rightChildIndex]
                && v[rightChildIndex] > v[leftChildIndex])
        {
            swap(v[currentIndex], v[rightChildIndex]);
            currentIndex = rightChildIndex;
        }
        else
        {
            if (v[currentIndex] < v[leftChildIndex])
            {
                swap(v[currentIndex], v[leftChildIndex]);
                currentIndex = leftChildIndex;
            }
            else
            {
                return;
            }
        }
    }
}


void heapify(vector<int>& v)
{
    if (v.size() == 0) return;

    cout << "Heapifying: " << endl;
    for (int heapSize = 0; heapSize < v.size(); ++heapSize)
    {
        sift_up(v, heapSize);
        print(v);
    }
}

void sort(vector<int>& v)
{
    cout << "Sorting: " << endl;
    for (int endIndex = v.size()- 1; endIndex >= 0; --endIndex)
    {
        swap(v[0], v[endIndex]);
        sift_down(v, endIndex -1);
        print(v);
    }
}