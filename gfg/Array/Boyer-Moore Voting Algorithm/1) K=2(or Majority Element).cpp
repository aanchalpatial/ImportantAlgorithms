//LEETCODE : 169

//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//You may assume that the array is non-empty and the majority element always exist in the array.

//**** 5 DIFFERENT APPROACHES ****

class Solution {
public:
    
    bool isMajorityElement(vector<int> nums, int ele){  //O(n)
        int cnt = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==ele) ++cnt;
        }
        if(cnt>nums.size()/2) return true;
        else return false;
    }
    
    int findOccurrences(vector<int> nums, int l, int h, int ele){
        int cnt = 0;
        for(int i=l;i<=h;++i){
            if(nums[i]==ele){
                ++cnt;
            }
        }
        return cnt;
    }
    
    int findMajorityElement(vector<int> nums, int l, int h){
        
        //if we know the majority element in the left and right halves of an array, we can
        //determine which is the global majority element in linear time.
        
        //base case : 
        if(l==h) return nums[l];
        
        int mid = l+(h-l)/2;
        int leftMajorityElement = findMajorityElement(nums, l, mid);
        int rightMajorityElement = findMajorityElement(nums, mid+1, h);
        if(leftMajorityElement==rightMajorityElement) return leftMajorityElement;
        else {
            //if left & right subarrays disagree on their majority elements then we have to
            //count occurences of left & right majority elements in the array &
            //return the one with highest occurence, if occurrence is same return
            //any one of them
            int leftCnt = findOccurrences(nums, l, h, leftMajorityElement);
            int rightCnt = findOccurrences(nums, l, h, rightMajorityElement);
            return leftCnt>rightCnt?leftMajorityElement:rightMajorityElement;
        }
    }
    
    
    int majorityElement(vector<int>& nums) {
        
        //method 1 : sorting
        //O(nlogn) time & O(1) space     -> 9 %
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
        
        
        //method 2 : hashmap
        //O(n) time & O(n) space     -> 37 %
        // unordered_map<int, int> mp;
        // for(int i=0;i<nums.size();++i){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]>nums.size()/2) return nums[i];
        // }
        // return -1;
        
        //method 3 : divide & conquer
        //O(nlogn) time & O(logn) space
        //TLE !!!
        //if we know the majority element in the left and right halves of an array, we can
        //determine which is the global majority element in linear time.
        //return findMajorityElement(nums, 0, nums.size()-1);
        
        //method 4 : randomization      -> 95 %
        //O(∞) & O(1) space
        //since majority element exists in more than n/2 indexes, it is highly likely to
        //choose a random index which is infact majority element
        /*
        Time complexity : 
        It is technically possible for this algorithm to run indefinitely (if we never
        manage to randomly select the majority element), so the worst possible runtime
        is unbounded. However, the expected runtime is far better - linear, in fact.
        */
        // int randomIndex = rand()%nums.size();
        // //since it is given that there is infact a majority element present in
        // //vector hence it is higly unlikely that infinite loop will never stop.
        // while(1){       //infinite loop
        //     if(isMajorityElement(nums, nums[randomIndex])) return nums[randomIndex];
        //     randomIndex = rand()%nums.size();
        // }
        
        //method 5 : Boyer-Moore Voting Algorithm   -> 95 %
        //**** BEST POSSIBLE SOLUTION ****
        //O(n) time & O(1) space
        //This method only works when the majority element does exist in the array.
        /*
        https://www.youtube.com/watch?v=n5QY3x_GNDg
                        OR
        Approach: This is a two-step process.
        The first step gives the element that maybe the majority element in the array. 
        If there is a majority element in an array, then this step will definitely return
        majority element, otherwise, it will return candidate for majority element.
        Check if the element obtained from the above step is majority element. This step 
        is necessary as there might be no majority element.
        
        Step 1: Finding a Candidate
        The algorithm for the first phase that works in O(n) is known as Moore’s Voting
        Algorithm. Basic idea of the algorithm is that if each occurrence of an element e
        can be cancelled with all the other elements that are different from e then e will
        exist till end if it is a majority element.

        Step 2: Check if the element obtained in step 1 is majority element or not.
        Traverse through the array and check if the count of the element found is greater 
        than half the size of the array, then print the answer else print “No majority element”.

        Algorithm:
        1) Loop through each element and maintains a count of majority element,
        and a majority index, maj_index
        2) If the next element is same then increment the count if the next element
        is not same then decrement the count.
        3) if the count reaches 0 then changes the maj_index to the current element 
        and set the count again to 1.
        4) Now again traverse through the array and find the count of majority element found.
        5) If the count is greater than half the size of the array, print the element
        6) Else print that there is no majority element
        */
        
        //step 1 : find candidate for majority element
        int candidate, cnt;
        for(int i=0;i<nums.size();){
            candidate = nums[i];
            cnt = 1;        // initial value of count
            while(cnt>0){
                ++i;
                if(i>nums.size()-1) break;
                if(candidate==nums[i]){
                    ++cnt;
                }else {
                    --cnt;
                }
            }
        }
        
        //step 2 : verify candidate
        int occ = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==candidate) ++occ;
        }
        return (occ>nums.size()/2)?candidate:-1;        
        
    }
};





