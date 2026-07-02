class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        string temp = s + s;
        return temp.find(goal) != string::npos;
        //temp.find(goal)!=string::npos  helps us to find substr 
    }
};