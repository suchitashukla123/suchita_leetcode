class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int row = 0 ; row <= n-2 ; row++){
            for(int col = row+1 ; col <= n-1 ; col++){
                swap(matrix[row][col] , matrix[col][row]);
            }
        }
        for(int row = 0 ; row <= n-1 ; row++){
            reverse(matrix[row].begin() , matrix[row].end() );
        }
    }
};