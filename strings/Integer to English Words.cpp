// LEETCODE 273

// EVERY PROBLEM IS SOLVABLE

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string ans = "";

        int groupIdx = 0;

        while(num > 0){
            if(num % 1000 != 0){
                string groupResult = "";

                int part = num % 1000;

                if(part >= 100){
                    groupResult += ones[part/100] + " Hundred ";
                    part %= 100;
                }

                if(part >= 20){
                    groupResult += tens[part/10] + " ";
                    part %= 10;
                }

                if(part > 0){
                    groupResult += ones[part] + " ";
                }

                groupResult += thousands[groupIdx] + " ";

                ans = groupResult + ans;
            }

            num /= 1000;
            groupIdx++;
        }

        int n = ans.length();

        while(ans[n-1] == ' '){
            ans.pop_back();
            n--;
        }


        return ans;

    }
};