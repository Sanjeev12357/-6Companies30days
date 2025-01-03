class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        // Outer loop for the start index of the subarray
        for (int i = 0; i < n; i++) {
            // Inner loop for the end index of the subarray
            for (int j = i; j < n; j++) {
                bool ok = true; // Flag to check if subarray is increasing
                int lst = -1;   // Variable to keep track of the last element
                
                // Loop to check each element within or outside the subarray
                for (int k = 0; k < n; k++) {
                    if (k >= i && k <= j) {
                        // Elements within the subarray are skipped
                    } else {
                        ok &= (lst < nums[k]); // Check if the current element is greater than the last one
                        lst = nums[k];         // Update the last element
                    }
                }
                
                ans += ok; // Increment count if the subarray is "incremovable"
            }
        }
        return ans; // Return the total count of "incremovable" subarrays
    }
};


