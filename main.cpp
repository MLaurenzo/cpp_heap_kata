#include <iostream>
#include <vector>

#include "heap_utils.h"

using namespace std;

int main()
{
    vector<int> v {2, 4, 8, 9, 1, 3, 7};

    heapify(v);

    sort(v);

    int a = 0, b = 1;
}