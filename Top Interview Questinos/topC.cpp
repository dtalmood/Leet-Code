#include <iostream>
using namespace std;
// RUN COMMAND: g++ -std=c++11 topC.cpp -o topC

int main()
{
    cout << "Hello World" << endl;
    return 0;
}

// Section 1: Arrays 




// Question 1: 
int removeDuplicates(vector<int>& nums) 
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
    int j = 1;
    int count = 0;
    int size = nums.size();
    bool duplicate = false;
    for(int i = 1; i < size; i++)
    {
        if(nums[i] != nums[i-1])
        { 
            nums[j]=nums[i];
            j++;
        }
        
    }
    
    
    return j;
}
