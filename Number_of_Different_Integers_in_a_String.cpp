#include <sstream>
#include <unordered_set>

class Solution {
public:
    int numDifferentIntegers(string word) {
        for (auto &c : word) {
            if (!isdigit(c)) {
                c = ' ';
            }
        }

        istringstream iss(word);
        string num;
        unordered_set<string> uniqueNums;

        while (iss >> num) {
            auto leadingZero = num.find_first_not_of('0');
            if (leadingZero != string::npos) {
                uniqueNums.insert(num.substr(leadingZero));
            } else {
                uniqueNums.insert("0");
            }
        }

        return uniqueNums.size();
    }
};