class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int s : students) q.push(s);
        
        int index = 0;  
        int attempts = 0; 
        
        while (!q.empty() && attempts < q.size()) {
            if (q.front() == sandwiches[index]) {
                q.pop();
                index++;
                attempts = 0; 
            } else {
                q.push(q.front());
                q.pop();
                attempts++;
            }
        }
        
        return q.size(); 
    }
};
