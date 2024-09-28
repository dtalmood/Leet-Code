int removeDuplicates(vector<int>& nums);


#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    return 0;
}




int removeDuplicates(vector<int>& nums) 
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150
    // Edge case: if the array has no elements or only one element
    if (nums.size() == 0)
        return 0;

    int j = 1; // pointer for the next position of unique element
    for (int i = 1; i < nums.size(); i++) // start from the second element
    {
        if (nums[i] != nums[i - 1]) // found a new unique element
        {
            nums[j] = nums[i]; // place the unique element at index j
            j++; // increment the position pointer for unique elements
        }
    }
    return j; // j is the number of unique elements
}

int maxProfit(vector<int>& prices) 
{
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
    int best = 0;
    int current = 0;
    
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i]>prices[i-1])
            best += prices[i]-prices[i-1];
    }
    return best;
}

void rotate(vector<int>& nums, int k) 
{
    // https://leetcode.com/problems/rotate-array/description/
    int n = nums.size();
    // Handle cases where k is greater than the size of the vector
    k = k % n;
    
    // If no rotation is needed, return early
    if (k == 0) {
        return;
    }
    
    queue<int> myQueue;
    
    // Push elements that will be shifted out of the array into the queue
    for(int i = n - k; i < n; i++) 
    {
        myQueue.push(nums[i]);
    }
    
    // Shift the rest of the elements to the right by k positions
    for(int i = n - k - 1; i >= 0; i--) 
    {
        nums[i + k] = nums[i];
    }
    
    // Fill the first k elements with the values from the queue
    for(int i = 0; i < k; i++) 
    {
        nums[i] = myQueue.front();
        myQueue.pop();
    }
}

bool containsDuplicate(vector<int>& nums) 
{
    //https://leetcode.com/problems/contains-duplicate/description/
    map<int,int> myMap;

    for(int i = 0; i <= nums.size()-1; i++)
    {
        myMap[nums[i]]++;
        cout << "Key: " << nums[i] << ", Value: " << myMap[nums[i]] << endl;
        if(myMap[nums[i]] >= 2)
            return true;
    }


    return false;    
}

int singleNumber(vector<int>& nums) 
{
    // https://leetcode.com/problems/single-number/description/
    unordered_map<int,int> myMap;
    
    for(int i = 0; i <= nums.size()-1; i++)
    {
        myMap[nums[i]]++;
        if(myMap[nums[i]] >= 2)
            myMap.erase(nums[i]);
    }

    return myMap.begin()->first;   
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    // https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
    map<int,int> myMap;
    int size1 =  nums1.size()-1;
    int size2 = nums2.size()-1;
    vector<int> result;

    for(int i = 0; i <= size1; i++)
    {
        myMap[nums1[i]]++;
    }
        

    for(int j = 0; j <= size2; j++)
    {
        auto itter = myMap.find(nums2[j]); // search the hashMap

        if(itter != myMap.end()) // check if value at location in nums2 exits in hashmap
        {
            cout << "Found Match" <<  endl;
            if(myMap[nums2[j]] > 0)
            {
                result.push_back(nums2[j]);
                myMap[nums2[j]]--;
            }
                
            else
                myMap.erase(nums2[j]);
        }
    }

    return result;    
}

vector<int> plusOne(vector<int>& digits) 
{
    // https://leetcode.com/problems/plus-one/
    bool run1 = true;
    bool run2 = false;
    int size = digits.size();

    if(digits.size() == 1 && digits[0] == 9)
    {
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }

    for(int i = size-1; i >= 0; i--)
    {
        if(run1)
        {
            run1 = false;
            if(digits[i] == 9)
            {
                digits[i] = 0;
                run2 = true;
                continue;
            }

            else
            {
                digits[i]++;
                return digits;
            }
        }
        
        else if(run2)
        {
            if(digits[i] == 9 && i != 0)
            {
                digits[i] = 0;
            }
            else if(digits[i] == 9 && i == 0)
            {
                digits[i] = 1;
                digits.push_back(0);
                return digits;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }

    }
    
    return digits;

}

void moveZeroes(vector<int>& nums) 
{  
    // https://leetcode.com/problems/move-zeroes/
    int j = 0;
    for(int i = 0; i <= nums.size()-1; i++)
    {
        if(nums[i] != 0)
        {
            nums[j]=nums[i];
            if(i != j)
                nums[i]=0;
            j++;
        }
    }
}

vector<int> twoSum(vector<int>& nums, int target) 
{
    // https://leetcode.com/problems/two-sum/
    int right = 0;
    int current = 0;
    vector<int> result;
    int size = nums.size()-1;

    for(int i = 0; i < size; i++)
    {
        int right = i+1;
        current = nums[i]+ nums[right];

        while(current < target && right <= size) // LOOP WHILE INVALID
        {
            current = nums[i];
            right++;
            current += nums[right];
        }
        if(current == target)
        {
            cout << "FOUND" << endl;
            result.push_back(i);
            result.push_back(right);
            return result;
        }
    }

    return result;
}