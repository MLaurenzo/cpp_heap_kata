#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v {2, 4, 8, 9, 1, 3, 7};
    for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
    cout << endl;
}