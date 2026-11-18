#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//so core logic to solve this problem is suppose we have 2 length substr and 4 or 6,8 length substr so to make 2 length substr equal u only need to change one character or no character (means max 1 change required) and to make 4,6,8 length substr equal (evenlength-2) worst case scenario "1100" so we will parition the string into 2's group  
    int minChanges(string s) {
        int changes = 0;
        
        // Jump by 2 to check every atomic pair: (0,1), (2,3), (4,5)...
        for (int i = 0; i < s.length(); i += 2) {
            
            // If the pair doesn't match, we have to change exactly one character
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }
        
        return changes;
    }
};