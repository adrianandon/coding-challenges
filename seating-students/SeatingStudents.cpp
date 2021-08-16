#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

int ArrayChallenge(int arr[], int arrLength) {

    //Special case, we have a single row
    if (arr[0] == 2)
        if (arrLength == 1)
            return 1;
        else
            return 0;

    //Calculate the maximum number of possible combinations (all desks are empty)
    int deskCombinations = 3 * (arr[0] - 4)/2 + 4;

    //Remove combinations for each occupied desk
    deskCombinations -= 3 * (arrLength - 1);

    //Account for first and last row desks
    for (int i = 1; i < arrLength; i++)
        if (arr[i] <= 2 || abs(arr[i] - arr[0]) < 2)
            deskCombinations++;
     
    return deskCombinations;

}

int main()
{

    int A[] = { 12, 2, 6, 7, 11 };
	
    int arrLength = sizeof(A) / sizeof(*A);
    
	auto combinations = ArrayChallenge(A, arrLength);
	
    return 0;
}
