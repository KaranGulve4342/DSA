// LEETCODE 537

class Solution {
public:
    pair<int, int> parse(string num){
        int i = num.find('+');
        double real = stoi(num.substr(0, i));
        double imaginary = stoi(num.substr(i+1, num.size()-1));
        pair<int, int> result(real, imaginary);
        return result;
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> a = parse(num1);
        pair<int, int> b = parse(num2);

        int realA = a.first;
        int imgA = a.second;
        int realB = b.first;
        int imgB = b.second;

        return to_string(realA*realB - imgA*imgB) + '+' + to_string(realA*imgB + realB*imgA) + 'i';
    }
};