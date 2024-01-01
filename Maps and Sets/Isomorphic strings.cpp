// GFG POTD
/*
bool areIsomorphic(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    if (n != m) {
        return false;
    }

    unordered_map<char, char> charMap;

    for (int i = 0; i < n; i++) {
        // If str1[i] is already mapped
        if (charMap.find(str1[i]) != charMap.end()) {
            // Check if the mapping is correct
            if (charMap[str1[i]] != str2[i]) {
                return false;
            }
        } else {
            // Check if str2[i] is already used
            for (auto it : charMap) {
                if (it.second == str2[i]) {
                    return false;
                }
            }

            // Map str1[i] to str2[i]
            charMap[str1[i]] = str2[i];
        }
    }

    return true;
}

*/