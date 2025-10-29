/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Prevent overflow
            
            int res = guess(mid);
            
            if (res == 0) {
                return mid;           // Found the number
            } else if (res < 0) {
                right = mid - 1;      // Target is lower
            } else {
                left = mid + 1;       // Target is higher
            }
        }
        return -1; // Should never reach here
    }
};