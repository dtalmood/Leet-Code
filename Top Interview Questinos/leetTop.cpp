int removeDuplicates(vector<int>& nums);


#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
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

bool isValidSudoku(vector<vector<char>>& board) 
{
    // https://leetcode.com/problems/valid-sudoku/
    
    // Validate rows 
    set<char> mySet;
    for(int row = 0; row < 9; row++)
    {
        mySet.clear(); // clear set at the beginning of each row
        for(int col = 0 ; col < 9; col++)
        {
            char current = board[row][col];
            if(current != '.') // Ensure we are not looking at empty location 
            {
                if(mySet.find(current) == mySet.end()) // Check for duplicates
                    mySet.insert(current);
                else
                    return false;
            }
        }
    }

    // Validate columns (corrected)
    for(int col = 0; col < 9; col++)
    {
        mySet.clear(); // clear set at the beginning of each column
        for(int row = 0 ; row < 9; row++)
        {
            char current = board[row][col]; // This is the correct order for column validation
            if(current != '.')
            {
                if(mySet.find(current) == mySet.end()) 
                    mySet.insert(current);      
                else
                    return false;
            }
        }
    }

    // Validate 3x3 sub-boxes
    vector<vector<int>> startPosition = {
        {0,0},{0,3},{0,6},
        {3,0},{3,3},{3,6},
        {6,0},{6,3},{6,6}
    };
    for(const auto box : startPosition)
    {
        int x = box[0];
        int y = box[1];

        mySet.clear(); // clear set at the beginning of each 3x3 sub-box
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                char current = board[x+row][y+col]; // Access 3x3 grid starting from x, y
                if(current != '.')
                {
                    if(mySet.find(current) == mySet.end()) 
                        mySet.insert(current);      
                    else
                        return false;
                }                    
            }
        }
    }

    return true; // If no issues found, the board is valid
}

void reverseString(vector<char>& myArr) 
{
    // https://leetcode.com/problems/reverse-string/
    int left = 0; 
    int right = myArr.size()-1;
    if(left == right)
        return;
    
    while(left < right)
    {
        char temp = myArr[right];
        myArr[right] = myArr[left];
        myArr[left]=temp;
        left++;
        right--; 
    }

}

int reverse(int x) 
{
    // https://leetcode.com/problems/reverse-integer/
    int answer = 0;

    while(x != 0)
    {
        int lastElem = x % 10;  // get the last digit

        /*
            Check Overflow: 
                - int MAX = 2,147,483,647
                - dividiing INT_MAX / 10 = 214,748,364 
                - 214,748,364 is the largest value that we can safley multiply by 10
                - 214748364 * 10 = 2,147,483,640
                - Notice the last elemet are not equal      
                - 2,147,483,647 - 2,147,483,640 = 7
                - as long as the last value is no greater than 7 its valid 
                
        */

        if (answer > INT_MAX / 10 || (answer == INT_MAX / 10 && lastElem > 7)) {
            return 0;  // Overflow detected
        }
        if (answer < INT_MIN / 10 || (answer == INT_MIN / 10 && lastElem < -8)) {
            return 0;  // Underflow detected
        }

        answer = answer * 10 + lastElem;  // Reverse the number
        x /= 10;  // Remove the last digit from x
    }

    return answer;
}

int firstUniqChar(string s) 
{
    // https://leetcode.com/problems/first-unique-character-in-a-string/description/
    map<char,int> myMap;

    for(auto x: s)
        myMap[x]++;

    for(int i = 0;i <= s.length()-1; i++)
    {
        char current = s[i];
        auto loc = myMap.find(current);
        if(loc->second == 1)
            return i;
    }

    return -1;
}

bool isAnagram(string s, string t) 
{
    // https://leetcode.com/problems/valid-anagram/
    
    // we need to keep track of frequency so use a hashmap
    map<char, int> myMap;
    
    
    for(auto x : s) // populate our hashmap
        myMap[x]++;

    for(auto y: t)
    {
        myMap[y]--;
        if(myMap[y] == 0) // if after decrment value = 0 then erase key
            myMap.erase(y);
    }

    return !myMap.size(); // if size == 0 this means matching 
}

bool isPalindrome(string str) 
{
    // https://leetcode.com/problems/valid-palindrome/
    int right = str.length()-1;
    int left = 0;

    while(left < right)
    {
        cout << "str[left] = " << str[left] << " , str[right] = " << str[right] << endl;
        // ensure both are alphabetical
        if(isalnum(str[left]) && isalnum(str[right]))  
        {
            
            if(tolower(str[left]) != tolower(str[right]))
                return false;
            left++;
            right--;
        }
        else if(!isalnum(str[left]))
            left++;
        
        else
            right--;
        
    }
    return true;
}

int myAtoi(string s) 
{
    // https://leetcode.com/problems/string-to-integer-atoi/
    int answer = 0;


    // Remove leading white spaces 
    int index = 0;
    while(isspace(s[index]))
        index++;
    
    bool negative = false;
    
    // determine if + or - 
    
    if(s[index] == '-')
    {
        negative = true;
        index++;
    }
    else if(s[index] == '+')
        index++;
    
    // keep iterating until no digit is found
    while(isdigit(s[index]))
    {
        char x = s[index];
        int newval = x - '0';
        
        if (answer > INT_MAX / 10 || (answer == INT_MAX / 10 && newval > 7)) 
        {
            if(negative)
                return INT_MIN;
            return INT_MAX;  // Overflow detected
        }
            
            
        if (answer < INT_MIN / 10 || (answer == INT_MIN / 10 && newval < -8)) 
            return INT_MIN;  // Underflow detected
    
        answer = answer * 10 + newval;
        index++;
    }

    if(negative)
        return answer * -1;
    
    return answer;
}

 int strStr(string haystack, string needle) 
{
    // https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
    int needleSize = needle.size()-1; 
    int needlePointer = 0; 

    for(int i = 0; i <= haystack.size()-1; i++)
    {
        int index = i;
        while(needlePointer <= needleSize)
        {
            cout << "haystack[index] = " << haystack[index] << " , needle[needlePointer] = " << needle[needlePointer] << endl;
            if(haystack[index] == needle[needlePointer])
            {
                needlePointer++;
                index++;
            }
                
            else
                break;
        }
        
        if(needlePointer > needleSize)  
            return i;
        

        needlePointer = 0;
    }    

    return -1;
}

string longestCommonPrefix(vector<string>& strs) 
{
    // https://leetcode.com/problems/longest-common-prefix/
    int strSize = strs.size() - 1;
    string answer = "";
    
    if(strs.size() == 0) 
        return "";

    int minLength = INT_MAX;
    
    for(const auto& str : strs) 
        minLength = min(minLength, (int)str.length());
    

    // grab first char of first element in strs

    for (int i = 0; i < minLength; i++)
    {
        cout << "itteration " << i << endl;
        char current = strs[0][i];

        for(int j = 0; j <= strSize; j++)
        {
            cout << "strs["<< j<<"][" << i<< "] =" << strs[j][i] << endl;
            if(strs[j][i] != current)
            {
                cout << "fail" << endl;
                return answer;
            }
                
        
        }

        answer += current;
        cout << "answer = " << answer << endl; 

    }

    return answer;
}