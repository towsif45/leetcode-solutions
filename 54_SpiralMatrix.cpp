class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = matrix[0].size(), y = matrix.size();
        int right = 0, down = x-1, left = y-1, up = 0;
        vector<int> ans;

        while(ans.size() < x*y){
            for(int i=up; i<=down && ans.size() < x*y; i++){
                // cout << "Moving right" << endl;
                // cout << matrix[right][i] << endl;
                
                ans.push_back(matrix[right][i]);
            }
            right++;
            for(int i=right; i<=left && ans.size() < x*y; i++){
                // cout << "Moving down" << endl;
                // cout << matrix[i][down] << endl;
                
                ans.push_back(matrix[i][down]);
            }
            down--;
            for(int i=down; i>=up && ans.size() < x*y; i--){
                // cout << "Moving left" << endl;
                // cout << matrix[left][i] << endl;
                ans.push_back(matrix[left][i]);
            }
            left--;
            for(int i=left; i>=right && ans.size() < x*y; i--){
                // cout << "Moving up" << endl;
                // cout << matrix[i][up] << endl;
                ans.push_back(matrix[i][up]);
            }
            up++;
        }
        
        return ans;

    }
};