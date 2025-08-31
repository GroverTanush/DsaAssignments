#include <iostream>
#include <algorithm>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    if (areAnagrams(s1, s2)) cout << "Yes, Anagrams";
    else cout << "Not Anagrams";

    return 0;
}