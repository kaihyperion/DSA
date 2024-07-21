#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isUniqueChars(string str) {
        int checker = 0;
        for (char c : str){
            int val = c - 'a';
            if ((checker & (1 << val))){
                return false;
            }
            checker |= (1 << val);
        }
        return true;

    }

    bool permutation(string s, string t) {
        // check if two strings are permutation of each other
        // option 1: sort both the strings and check bool. sort -> o(nlogn)
        //option 2: count the occurence of characters and see if equal. iterate -> o(n)
        if (s.length() != t.length()){
            return false;
        }
        array<int, 128> count ;
        for (char c : s){
            count[c]++;
        }
        for (char c : t){
            count[c]--;
            if (count[c] < 0){
                return false;
            }
        }
        return true;
    }

    bool isPerfumationOfPalindrome(string phrase){
        // option 1: we can count the occurences and see if there is exactly 1 or 0 odd. if there is more, it cant craft palindrome
        // option 2: bit count. faster.
        int bitVector = 0;
        for (char c : phrase){
            int val = c - 'a';
            if (val < 0) return bitVector;

            int mask = 1 << val;
            if ((bitVector & mask) == 0) {
                bitVector |= mask;
            } else {
                bitVector &= ~mask;
            }
        }
        return bitVector == 0 || ((bitVector & (bitVector - 1)) == 0);

    }


        


};

int main() {
    Solution solution;

    // Test case 1
    cout << solution.isPerfumationOfPalindrome("tacoat") << endl;

    return 0;
}

