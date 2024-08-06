// LEETCODE 468

class Solution {
public:
    string validIPAddress(string queryIP) {
        int n = queryIP.length();

        // Check for IPv4
        if (queryIP.find('.') != std::string::npos) {
            int dot = 0;

            for (int i = 0; i < n; ++i) {
                string temp = "";

                while (i < n && queryIP[i] != '.' && isdigit(queryIP[i])) {
                    temp += queryIP[i];
                    i++;
                }

                if (temp.empty() || temp.length() > 3 || (temp.length() > 1 && temp[0] == '0')) {
                    return "Neither";
                }
                
                int num = stoi(temp);
                if (num < 0 || num > 255) {
                    return "Neither";
                }

                if (i < n && queryIP[i] == '.') {
                    dot++;
                } else if (i < n && queryIP[i] != '.') {
                    return "Neither";
                }
            }

            return (dot == 3 && queryIP[n-1] != '.') ? "IPv4" : "Neither";
        } 
        
        // Check for IPv6
        else {
            int colon = 0;

            for (int i = 0; i < n; i++) {
                string temp = "";

                while (i < n && queryIP[i] != ':') {
                    if (!isxdigit(queryIP[i])) {
                        return "Neither";
                    }
                    temp += queryIP[i];
                    i++;
                }

                if (temp.length() == 0 || temp.length() > 4) {
                    return "Neither";
                }

                if (i < n && queryIP[i] == ':') {
                    colon++;
                }
            }

            return (colon == 7 && queryIP[n-1] != ':') ? "IPv6" : "Neither";
        }
    }
};
