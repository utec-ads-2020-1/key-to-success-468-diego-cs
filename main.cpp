#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;
    string line;
    
    while (n--) {
        getline(cin, line); // reads every empty line

        /* std::unordered_map -> time complexity insertion O(1) */
        unordered_map<char, int> line1freq;
        unordered_map<char, int> line2freq;     
        cin >> line; // reads not encoded line
        for (const auto& letter : line)
            line1freq[letter]++;
        cin >> line; // reads encoded line
        for (const auto& letter : line)
            line2freq[letter]++;
    
        /* maps sorted by counts */
        map<int, char> sorted_line1freq;
        map<int, char> sorted_line2freq;
        for (auto it = line1freq.begin(); it != line1freq.end(); ++it)
            sorted_line1freq.insert(make_pair(it->second, it->first));      
        for (auto it = line2freq.begin(); it != line2freq.end(); ++it)
            sorted_line2freq.insert(make_pair(it->second, it->first));

        /* unordered_map encoded letter by letter */
        unordered_map<char, char> encoded;        
        for (auto it1 = sorted_line1freq.begin() ,it2 = sorted_line2freq.begin(); it1 != sorted_line1freq.end() , it2 != sorted_line2freq.end(); ++it1, ++it2)
            encoded.insert(make_pair(it2->second, it1->second));
        for (const auto& letter : line)
            cout << encoded[letter];
        (n != 0) ? cout << endl << endl : cout << endl;
    }

    return 0;
}