class Solution {
public:
    void move(const string& s, int& ind, int& jump) {
        while (ind >= 0) {
            if (s[ind] == '#') {
                jump++;
                ind--;
            }
            else if (jump > 0) {
                jump--;
                ind--;
            }
            else {
                break;
            }
        }
    }
    
    bool backspaceCompare(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        int jump_s = 0;
        int jump_t = 0;
        int i = ns - 1;
        int j = nt - 1;
        while (i >= 0 || j >= 0) {
            move(s, i, jump_s);
            move(t, j, jump_t);
            if (i >= 0 && j >= 0) {
                if (s[i] == t[j]) {
                    i--;
                    j--;
                }
                else {
                    return false;
                }
            }
            else if (i >= 0) {
                return false;
            }
            else if (j >= 0) {
                return false;
            }
            else {
                return true;
            }
        }
        return true;
    }
};
