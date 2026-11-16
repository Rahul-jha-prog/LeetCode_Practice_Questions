#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string digitSum(string s, int k) {
        

        while (s.length() > k) {

            string temp = "";
            int sum = 0;

            for (int i = 0; i < s.length(); i++) {
                sum += (s[i] - '0');

                if ((i+1) % k == 0) {
                    temp += to_string(sum);
                    sum = 0;
                }
            }

            if (s.length() % k != 0) {
                temp += to_string(sum);
            }

            s = move(temp);//it helps us to shrink the original string s so that while loop condition become false at some point and it also helps us in for loop cause everytime s shrink it reduces the time that will required to traverse it 
        }

        return s;
    }
};