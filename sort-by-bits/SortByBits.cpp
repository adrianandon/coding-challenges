#include <iostream>
#include <vector>
#include <map>

using namespace std;

int countOneBits(int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

bool insertIfSmallerOEqual(vector<int>& bitsSorted, vector<int>::iterator it, int newVal)
{
    auto iteratorValBits = countOneBits(*it);
    auto newValBits = countOneBits(newVal);

    if (iteratorValBits < newValBits)
    {
        bitsSorted.emplace(it + 1,newVal);
        return true;
    }
    else if (iteratorValBits == newValBits)
    {
        if (*it <= newVal)
        {
            bitsSorted.emplace(it + 1, newVal);
            return true;
        }
    }
    return false;
}

void bitsInsertionSort(vector<int>& bitsSorted, int val)
{
    if (bitsSorted.empty())
    {
        bitsSorted.push_back(val);
        return;
    }
    auto it = prev(bitsSorted.end());

    while (it != bitsSorted.begin())
    {
        if (insertIfSmallerOEqual(bitsSorted, it, val))
            return;
        it--;
    }
   
    if (!insertIfSmallerOEqual(bitsSorted, it, val))
        bitsSorted.emplace(it, val);
    
}

class Solution {
public:
    
    auto sortByBits(vector<int>& arr) {
        vector<int> bitsSorted;

        for (auto i : arr)
            bitsInsertionSort(bitsSorted, i);

        return bitsSorted;
    }

};

int main()
{
    Solution s;

    vector<int> arr = { 1111,7644,1107,6978,8742,1,7403,7694,9193,4401,377,8641,5311,624,3554,6631 };     
   
    auto result = s.sortByBits(arr);
    
    
    for (auto i : result)
        cout << i << " ";
    
}