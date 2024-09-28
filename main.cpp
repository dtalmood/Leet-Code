#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>       // For std::cout
#include <unordered_map>  // For std::unordered_map
#include <unordered_set>  // For std::unordered_set
#include <set>            // For std::set
#include <map>            // For std::map
#include <vector>         // For std::vector
#include <string>         // For std::string

// RUN CODE WITH FOLLOWING COMMAND: g++ -std=c++11 main.cpp -o main
using namespace std;

bool checkIfPalindrome();
bool pairToUniqueSum();
vector<int> sortCombineTwoInputs();
bool findSubSequance();
void reverseString();
void sortedSquares();
void findLengthOfLongestSubarray();
void findLongestWithFlipingBit();
void findSubArrayWithSum();
void findMaxSumSubarrayOfLengthK();
void maxAveSubArray();
void maxConsecutiveOnes();
void prefixSumQuery();
void numWayToSplitArray();

int main() 
{
    bool boolResult;
    vector<int> vecResult;
    //result = checkIfPalindrome();
    //result = pairToUniqueSum();
    //vecResult = sortCombineTwoInputs();
    //boolResult = findSubSequance();
    //reverseString();
    //sortedSquares();
    //findLengthOfLongestSubarray();
    //findLongestWithFlipingBit();
    //findSubArrayWithSum();
    //findMaxSumSubarrayOfLengthK();
    //maxAveSubArray();
    //maxConsecutiveOnes();
    //prefixSumQuery();
    numWayToSplitArray();
}

bool checkIfPalindrome()
{
    string myStr = "racecar";
    int left = 0;
    int right = myStr.length()-1;
    while(left < right)
    {
        cout << "Left = " << myStr[left] << endl;
        cout << "Right = " << myStr[right] << endl;
        
        if(myStr[left] != myStr[right])
        {
            cout << "Found that word is Not Palindrome" << endl;
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool pairToUniqueSum()
{
    /*
        Given a sorted array of unique integers and a target integer(goal),
        Return true if there exists a pair of numbers that sum to target, false otherwise.
    */
     
    int myArr[] = {1, 2, 3, 4, 5, 6, 7 , 8, 9};
    int goal = 4;
    int left;
    int right = sizeof(myArr) / sizeof(myArr[0]);
    

    for(left = 0; left <= right; left++)
    {
        while(right >= left )
        {
            if(myArr[right]+myArr[left]==goal)
            {
                cout << "Unique Pair Found! " << myArr[left] << " and " << myArr[right] << endl;
                return true;
            }
                
            right--;
        }
    }
    return false;

}

vector<int> sortCombineTwoInputs()
{
    /*
        Given two sorted integer arrays arr1 and arr2, return a new 
        array that combines both of them and is also sorted.
    */
    vector<int> myVec1 = {1, 2, 3};
    vector<int> myVec2 = {4, 5, 6, 7, 8};

    vector<int>::iterator itterOne = myVec1.begin();
    vector<int>::iterator itterTwo = myVec2.begin();
    vector<int> result;

    // Merge the two arrays in sorted order
    while(itterOne != myVec1.end() && itterTwo != myVec2.end())
    {
        if(*itterOne < *itterTwo)
        {
            result.push_back(*itterOne);  // Push the smaller value from myVec1
            itterOne++;  // Move the iterator of myVec1
        }
        else
        {
            result.push_back(*itterTwo);  // Push the smaller value from myVec2
            itterTwo++;  // Move the iterator of myVec2
        }
    }

    // If there are remaining elements in myVec1, add them
    while(itterOne != myVec1.end())
    {
        result.push_back(*itterOne);
        itterOne++;
    }

    // If there are remaining elements in myVec2, add them
    while(itterTwo != myVec2.end())
    {
        result.push_back(*itterTwo);
        itterTwo++;
    }

    for(auto i = result.begin(); i != result.end(); ++i)
    {
        cout << *i << ", ";
    }
    return result;  // Return the merged sorted result
}

bool findSubSequance()
{
    /*
        Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
        Note: 
           - A subsequence of a string is a sequence of characters that can be 
             obtained by deleting some (or none) of the characters from the original string
    */
    

    string strOne = "abzd";
    string strTwo = "abcXXtyzzXXX";

    int StrOneSize = strOne.length();
    int current = 0;

    for(int i = 0; i < strTwo.size(); i++)
    {
        if(strOne[current] == strTwo[i])
        {
            current++;
        }
    }
    if(current == strOne.length())
    {
        cout << "Found Subsequance" << endl;
        return true;
    }
        
    cout << "Subsequance not found" << endl;
    return false;
}

void reverseString()
{
    /*
    
    Write a function that reverses a string. The input string is given as an array of characters s.

    */
    vector<char> myStr = {'h', 'e', 'l','l', 'o'};
    vector<char>::iterator itter = myStr.end()-1;
    vector<char> result;

    while(itter != myStr.begin())
    {
        cout << "Added " << *itter << endl;
        result.push_back(*itter);
        itter--;
    }
    result.push_back(*itter);

    for(auto i = result.begin(); i != result.end(); ++i)
    {
        cout << *i << ", ";
    }
}

void sortedSquares()
{
    /*
        Given an integer array nums sorted in non-decreasing order, return an array of the squares 
        of each number sorted in non-decreasing order.
    */

   vector<int> nums = {-4, -1, 0, 3, 10};
   vector<int> result;

   for(auto it = nums.begin(); it != nums.end(); it++)
   {
       result.push_back(*it * *it);
   }
    sort(result.begin(),result.end());
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] <<", ";
    }
}

void findLengthOfLongestSubarray()
{
     // find length of longest subarray whos sum = k 
    int nums[] = {1, 2, 1, 1, 2, 5, 6, 1, 1, 1, 1, 1, 1};
    int k = 7;
    
    int left = 0;
    int right;
    int current = 0;
    int best = 0;
    int size = sizeof(nums)/sizeof(nums[0]);
    
    for(right = 0; right < size; right++)
    {

        current = nums[right];
        cout << "Current = " << current << endl;
        while(left < right)// loop while invalid 
        {
            current += nums[left];
            if(current == k)
            {
                cout << "Found, right = " << right << "left = " << left << endl;
                best = right - left + 1;
                cout << "Current Best = " << best  << endl;
            }
            left++;
        }
        left = 0;
    }

    cout <<"Final = " << best << endl;
}

void findLongestWithFlipingBit()
{
    /*
        Given String s = Zeros or One's, If you flip only a single Zero --> what is longest subarray
    */
    string s = "0001000";
    int highScore = 0;
    int left = 0;
    int current;
    int zeroCount;

    for (left = 0; left < s.size(); left++)  // fixed: no need to go beyond the string size
    {
        current = 0;
        zeroCount = 0;
        int right = left;

        while (right < s.size() && zeroCount <= 1)  // loop until we hit more than 1 zero or reach the end
        {
            if (s[right] == '0') 
                zeroCount++;

            if (zeroCount == 2) // we see too many zeros, break out of while loop
                break;

            current++;
            right++;
        }

        if (current > highScore)
        {
            cout << "New HighScore, current = " << current << endl;
            highScore = current;
        }
    }
    
    cout << "Length of longest = " << highScore << endl;
}

void findSubArrayWithSum()
{
    /*
        Given an array of positive integers nums and an integer k, return the number of 
        subarrays where the product of all the elements in the subarray is strictly less than k.
    */
   int nums[] = {10, 5, 2, 6};
   int length = sizeof(nums)/sizeof(nums[0]);
   int k = 100;
   int left = 0, answer = 0, current = 1;
   
   for(int right = 0; right < length; right++)
   {
        current *= nums[right];
        
        while(current >= k) // Loop while Invalid: we move left until its valid again
        {
            current /= nums[left];
            left++;
        }
        // Skiping Loop above means that Current = valid 

        answer += right-left+1;
   }    
    cout << "Number of Valid Subarrays: " << answer <<endl;
}

void findMaxSumSubarrayOfLengthK()
{
    /*
        Given an integer array nums and an integer k, find the sum 
        of the subarray with the largest sum whose length is k.
    */
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(nums)/sizeof(nums[0]);
    int k = 4;
    int answer = 0;
    int current = 0;

    for(int i = 0; i < k; i++)
    {
        current+= nums[i];
    }

    for(int i = k; i < length; i++)
    {
        current -= nums[i-k];
        current += nums[i];
        answer = max(answer, current);
    }
    cout << "Answer = " << answer << endl;

}

void maxAveSubArray()
{
    /*
        You are given an integer array nums consisting of n elements, and an integer k.
        Find a contiguous subarray whose length is equal to k
    */
   vector<int> vect = {1,12,-5,-6,50,3};
   int k = 4;
   int length = vect.size();
   float ans = 0;
   float current = 0;

   for(int i = 0; i < k; i++)
   {
        current += vect[i];
        cout << "Itter :" << i << endl;
        cout << vect[i] <<endl;
   }
        
   current /= k;
   ans = max(ans,current);
   cout << "Ans :" << ans << endl;
   current *= k;
   
   for(int i = k; i < length; i++)
   {
        current -= vect[i-k];
        current += vect[i];
        current /= k;
        ans = max(ans,current);
        cout << "New Ans :" << ans << endl;
        current *= k;
   }

   cout << "Final Ans = " << ans << endl;
}

void maxConsecutiveOnes()
{
    /*
        Given a binary array nums and an integer k, 
        return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
    */
    vector<int> nums = {000011};
    int k = 2;
    int length = nums.size();
    int left = 0, answer = 0, current = 0, numOfZeros = 0;
    for(int right = 0; right < length; right++)
    {
        if(nums[right] == 0)
            numOfZeros++;
            
        while(numOfZeros > k)// loop while invalid 
        {
            if(nums[left] == 0)
                numOfZeros--;

            left++;
            
        }
        
         
        answer = max(answer, right-left+1);
    }
    cout << "answer = " << answer << endl;
}

void prefixSumQuery()
{
    vector<int> nums = {1, 6, 3, 2, 7, 22};
    vector<vector<int>> queries = {{0,3}, {2,5}, {2,4}};
    int limit = 13;
    int queriesLength = queries.size();
    vector<bool> result;

    for(int i = 0; i < queriesLength; i++)
    {
        vector<int> current = queries[i];
        //cout << current[0] << " and " << current[1] << endl;
       int j = current[0];
       int k = current[1];
       int value; 
       for(j; j<k;j++)
       {
            value += nums[j];
       }
       
       if(value < limit)
            result.push_back(true);
       else
            result.push_back(false);
    }

    for(int i = 0; i <= result.size()-1; ++i)
    {
        if(result[i] == true)
            cout << "Index " << i << ": True" << endl;
        else 
            cout << "Index " << i << ": False" << endl;
    }

}

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map <int,int> dict;
    int length = nums.size();
    vector<int> result;
    for(int i = 0; i < length; i++)
    {
        int value = target - nums[i];

        if(dict.find(value) != dict.end())
        {
            int temp = dict[value];
            result.push_back(temp);
            result.push_back(i);
            break;
        }
        dict[nums[i]] = i;
    }
    return result;
}
    

char repeatedCharacter(string s) 
{
    // We want to return the first letter to appear twice
    // Sets are perfect for checking if something exists
    unordered_set<char> seen;
    for(char c: s)
    {
        if(seen.find(c) != seen.end())
        {
            return c;
        }
        else
        {
            seen.insert(c);
        }
    }    
    return ' ';    
}

bool checkIfPangram(string sentence) 
{
    // https://leetcode.com/problems/check-if-the-sentence-is-pangram/

    // Is all letters of the alphabet in sentence? 
    // We are Checking for Existance so use a SET

    set<char> mySet(sentence.begin(),sentence.end());

    if(mySet.size()==26)
        return true;
        
    return false;
}

int missingNumber(vector<int>& nums) 
{
    // https://leetcode.com/problems/missing-number/
    
    // We wat to see if there is a number missing 
    // We are checking for the existasnce of something
    // Sets are good for checking for existance 

    
    set<int> mySet(nums.begin(),nums.end()); // set is in ascending order 
    
    int i = 0;
    for(auto x: mySet)
    {
        if(i != x)
            return i;
        i++;
    }
    return i;
}

int countElements(vector<int>& arr) 
{
    /*
        https://leetcode.com/problems/counting-elements/
    
    Note: 
        - Frequancy Matters, Sets do not keep track of frequancy 
        - Do not use a Set 
        - COUNT = USE A HASHMAP
        - use a hash Man instead to keep track of frequancy 
    */

    map<int,int> myHash;
    int answer = 0;
    
    // populate our hashmap
    for(auto x: arr)
        myHash[x]++;

    for(auto x: myHash)
    {
        cout << "Key: " << x.first << " Value: " << x.second << endl;
        int key = x.first;
        if(myHash.find(key+1) != myHash.end()) // see if key +1 is in array
        {
            // if x+1 is in array we add x.second becuase 
            // x.second tell us number of times that key was seen in the array
            answer += x.second;
        }    
    
    }
    return answer;
}



vector<int> intersection(vector<vector<int>>& nums) 
{
    /*
        https://leetcode.com/problems/intersection-of-multiple-arrays/
        - We need to keep track of frequancy
        - Set = Good for checking if element exists  (no Frequency tracking )
        - Hash = good for counting
    */
    map<int,int> myHash;
    vector<int> result;

    int size = nums.size();
    
    // populate our hashmap
    for(auto x: nums)
    {
        for(auto y: x)
        {
            myHash[y]++;
        }
    }
        
    
    //if value associated with key != size key is not in every set 
    for(auto x: myHash)
    {
        if(x.second == size)
            result.push_back(x.first);
    }

    return result;
}


bool areOccurrencesEqual(string s) 
{
    /*
        https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

    Set:
        1. Does not keep track of frequancy
        2. Good for checking if element exists

    Hash: 
        1. Keep track of frequancy 

    */
    unordered_map<char,int> myMap;
    
    // Populate Map
    for(auto x: s)
        myMap[x]++;
        
    bool grabfirst = true;
    int value = 0;
    for(auto y: myMap)
    {
            cout << "Key: " << y.first << " Value: " << y.second << endl;
            cout << "Value: " << value << endl;
        if(grabfirst)
        {
            value = y.second;
            cout << "New Value: " << value << endl;
            grabfirst = false;
        }
        if(value != y.second)
            return false;
        
        value = y.second;
    }


    return true;
}


// DO THIS AGAIN LATER

int subarraySum(vector<int>& nums, int k) 
    {
        /*
            https://leetcode.com/problems/subarray-sum-equals-k/
            Set: Good for check if element exsits , no frequency check
            HashMap: Keeping track / Counting
            We are tokd to track numebr of subarays, perfect for sliding window 
        */

        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        
        for (int num: nums) 
        {
            curr += num;
            if(counts.find(curr-k) != counts.end())
                ans += counts[curr - k];
            counts[curr]++;
        }
        
        return ans;
      
      
    }

vector<vector<int>> findWinners(vector<vector<int>>& matches)
{
    /*
        https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
        My Idea:
            we have Map Key is Player Vale is Wins/losses
            We iterate through winner first
                Winner Key all = 1(does matter how many wins just that they won)
            We iterate over lossers
                Loss 1: Value = 0
                Loss 2: Value = -1
    */

    map<int,int> myMap;
    vector<vector<int>> result(2);

    //itterate through winner
    for(auto x: matches)
        myMap[x[0]] = 1;
    
    for(auto x: matches)
    {
        // first Check, if the player that lost ever won a single match
        if(myMap.find(x[1]) == myMap.end()) 
            myMap[x[1]] = 0;

        else
            myMap[x[1]]--;
        
    }
    for(auto x: myMap)
    {
        cout << "Key = " << x.first << ", Value = " << x.second << endl;
    }
        
    for(auto x: myMap)
    {
        if(x.second == 1) // never lost a match
        {
            result[0].push_back(x.first);
        }

        else if(x.second == 0) // lost a single match
        {
            result[1].push_back(x.first);
        }
        
    }
    return result;
}

int largestUniqueNumber(vector<int>& nums)
{
    /*
        https://leetcode.com/problems/largest-unique-number/

        Set = No Frequency, Good for checking if something exists
        Hash = Good for coutning frequancy 
    */
    map<int,int> myMap;

    for(auto x: nums) 
        myMap[x]++;
        
    for(auto it = myMap.rbegin(); it != myMap.rend(); it++)
    {
        if(it->second == 1)
            return it->first;

    }
    
    return -1;
}



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* middleNode(ListNode* head) 
{
    /*
        https://leetcode.com/problems/middle-of-the-linked-list/
    */
    ListNode* slow = head;
    ListNode* fast = head;
    
    // find the middle 
    while(fast != nullptr  && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

bool hasCycle(ListNode *head) 
{
    /*
        https://leetcode.com/problems/linked-list-cycle/
        
    */
    ListNode* slow = head;
    ListNode* fast = head;

    // We have this boolean becuase we want to prevent slow and fast to comapre when loop initally looks at head
    bool firstCase = false; 

    int i = 0;
    while(fast != nullptr && fast->next != nullptr)
    {
        cout << "Itteration " << i << endl;
        cout << "Slow = " << slow->val << " Fast = " << fast->val << endl; 
        if(slow == fast && firstCase)
        {
            cout << "Found Loop";
            return true;
        }
        firstCase = true;   

        slow = slow->next;
        fast = fast->next->next;
        i++;
    }   
    cout << "No Loop" << endl;

    return false; 
}

ListNode* removeNthFromEnd(ListNode* head, int n) 
{   
    ListNode* slow = head;
    ListNode* fast = head;
    for(int i = 0; i < n; i++)
        fast = fast->next;


    // if fast == nullptr already this means that we want to delete first element 
    if(fast == nullptr)
    {
        ListNode* tempHead = head;
        head = head->next
        delete tempHead;
        return head;
    }

    ListNode* prev = head;
    while(fast!= nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = slow->next;
    delete slow;
    return head;
}

bool isValid(string s) 
{
    // https://leetcode.com/problems/valid-parentheses/

    stack<char> stack;
    unordered_map<char, char> matching {{'(',')'}, {'{','}'}, {'[',']'}};
    
    // ({})
    for(auto c: s)
    {
        //This tell us if c is have ( or { or [ 

        if(matching.find(c) != matching.end())
        {   
            stack.push(c); // c is either ( or { or [ 
        }
        else
        {
            if(stack.size() == 0)
                return false;

            char top = stack.top();
            
            if(matching[top] != c)
                return false;

            stack.pop();     
        }
    }
    return stack.empty();
}

string removeDuplicates(string s) 
{
    // https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
    stack<char> stack;
    string answer = "";

    for(auto c: s)
    {
        if(stack.empty()) // if empty returns true else false
            stack.push(c);
        else
        {
            char previous = stack.top();
            if(previous == c)
                stack.pop();
            
            else
                stack.push(c);     
        }
    }   

    string result = "";
    while (!stack.empty())
    {
        // Doing this ensures we are adding elements from right to left 
        result = stack.top() + result; 
        stack.pop();
    }
    cout << result << endl;

    return result;
}

bool backspaceCompare(string s, string t) 
{
    // https://leetcode.com/problems/backspace-string-compare/
    stack<char> stackS;
    stack<char> stackT;

    for(auto x: s)
    {
        cout << x << endl;
        if(x == '#' && !stackS.empty())
        {
            cout << "pop " << stackS.top() << endl; 
            stackS.pop();
        } 
        else if(x != '#')
        {
            cout << "add " << x << endl;
            stackS.push(x);
        }
    }

    for(auto y: t)
    {
        cout << y << endl;
        if(y == '#' && !stackT.empty())
        {
            cout << "pop " << stackT.top() << endl; 
            stackT.pop();
        } 
        else if(y != '#')
        {
            cout << "add " << y << endl;
            stackT.push(y);
        }
    }

    // loop while stacks are not empt 
    while(!stackS.empty() && !stackT.empty())
    {
        int topS = stackS.top();
        int topT = stackT.top();
        if(topS != topT)
            return false;

        stackS.pop();
        stackT.pop();
    }
    return stackS.empty() && stackT.empty();
}


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

int maxDepth(TreeNode* root)
{
    // https://leetcode.com/problems/maximum-depth-of-binary-tree/
    
    // BASE CASE: We traverse to far and are looking at nothing 
    if(root == nullptr)
    {
        return 0; 
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return max(left,right)+1;
}

int target; 

bool hasPathSum(TreeNode* root, int targetSum)
{
    /*
        https://leetcode.com/problems/path-sum/
        Pre: Work is done On Current node before going to next 
        Post: We recursively call on the children first →  then perform logic on the current node
        In: First We first recursively call the left child → Then perform logic
    */
    target = targetSum;
    return dfs(root, 0);
}
bool dfs(TreeNode* node, int current)
{
    if (node == nullptr) {
        return false;
    }
    // BASE CASE: If we reach a child 
    if(node->left == nullptr && node->right == nullptr)
        return (current + node->val == target);
    
    bool left = dfs(node->left, current + node->val);
    bool right = dfs(node->right, current+node->val);

    return left || right;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* result = new ListNode(); // Dummy node
    ListNode* head = result;           // Store head of the result list

    // Traverse both lists
    while (list1 != nullptr && list2 != nullptr) 
    {
        if (list1->val > list2->val)
            {
            result->next = new ListNode(list2->val);
            list2 = list2->next;
        } 
        else 
        {
            result->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        result = result->next; // Move the result pointer forward
    }

    // If one list is not empty, append the rest
    if (list1 != nullptr) {
        result->next = list1;
    } else if (list2 != nullptr) {
        result->next = list2;
    }

    // Return the merged list, skipping the dummy node
    return head->next;
}

int maxProfit(vector<int>& prices) 
{
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


    // Left = Buy 
    // Right = Sell 
    int left = 0;
    int profit = 0;
    int maxProfit = 0;

    for(int right = 1; right < prices.size(); right++)
    {
        // Check if profitable 
        if(prices[left] < prices[right]) // If when We sell is greater than when we bought
        {
            profit = prices[right]-prices[left];
            maxProfit = max(maxProfit, profit);
        }
        else 
        {
            left++;
        }
        
    }
    return maxProfit;
}

bool isPalindrome(string s) 
{
    // https://leetcode.com/problems/valid-palindrome/description/
    int left = 0;
    int right = s.size() - 1;

    while (left < right) 
    {
        if(isalnum(s[left]))
            cout << "is Alpha";
        else
            cout << "Not Alpha";

        while (left < right && !isalnum(s[left])) 
        {
            cout << "LEFT++" << endl;
            left++;
        }
            
        // Move right index to previous alphanumeric character
        while (left < right && !isalnum(s[right])) 
        {
            cout << "RIGHT--" << endl;
            right--;
        }
        // Compare characters, ignoring case
        if (tolower(s[left]) != tolower(s[right]))
        {
            cout << s[left] << " and " << s[right] << endl;
            return false;
        } 
            
        left++;
        right--;
    }

    return true;
}

TreeNode* invertTree(TreeNode* root) 
{
    // https://leetcode.com/problems/invert-binary-tree/
    // BASE CASE:
    if(root == nullptr)
        return nullptr;

    auto temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);


    return root;
}

bool isAnagram(string s, string t) 
{
    // https://leetcode.com/problems/valid-anagram/
    map<char,int> myMapS;
    map<char,int> myMapT;

    for(auto x: s)
        myMapS[x]++;
    
    for(auto y: t)
        myMapT[y]++;
    
    if(myMapS == myMapT)
        return true;
    
    return false;   
}



int binarySearch(vector<int>& nums, int target) 
{
    // https://leetcode.com/problems/binary-search/submissions/1391514893/
    
    int left = 0;
    int right = nums.size()-1;
    cout << "right " << right << endl;
    while(left <= right)
    {
        int middle = left + (right - left) / 2;
        cout << middle << endl;
        
        if(nums[middle] == target) // we found target
            return middle;
        
        if(nums[middle] < target)
        {
            left = middle+1;
        }
        if(nums[middle] > target)
        {
            right = middle-1;
        }
    }
    
    return -1;
}

// TOP 150 Leet Code Questions


// Question 1: 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    //https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
    nums1.erase(nums1.begin()+m,nums1.end());

    for(auto x: nums2)
        nums1.push_back(x);

    sort(nums1.begin(),nums1.end());    
}