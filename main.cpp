#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


int itemFinder(string inputString, char query) {
    for(int i = 0; i < inputString.length(); i++) {
        if (inputString.at(i) == query) {
            return i; 
        }
    }
    return -1;
}

int itemFinder(string inputString, string query) {
    int stringLength = inputString.length();
    int queryLength = query.length();

    if (stringLength == 0 && queryLength > 0) {
        return -1;
    }

    if (queryLength == 0) {
        return 0;
    }

    for(int i = 0; i <= stringLength - queryLength; i++) {
        bool found = true; 
        
        for (int w = 0; w < queryLength; w++) {
            if (inputString[i + w] != query[w]) {
                found = false;
                break;
            }
        }

        if (found) {
            return i;
        }
    }
    return -1;
}

int main() {

    assert(itemFinder("The quick brown fox", 'e') == 2);
    assert(itemFinder("The quick brown fox", 'z') == -1);
    assert(itemFinder("The quick brown fox", ' ') == 3);

    assert(itemFinder("The quick brown fox", "quick") == 4);
    assert(itemFinder("The quick brown fox", "quiet") == -1);
    assert(itemFinder("The quick brown fox", "") == 0);
    assert(itemFinder("", "quick") == -1);
    assert(itemFinder("The quick brown fox", "The") == 0);

    assert(itemFinder("The five boxing wizards jump quickly", 'e') == 2);
    assert(itemFinder("The five boxing wizards jump quickly", 'z') == -1);
    assert(itemFinder("The five boxing wizards jump quickly", ' ') == 3);

    assert(itemFinder("The five boxing wizards jump quickly", "five") == 4);
    assert(itemFinder("The five boxing wizards jump quickly", "frog") == -1);
    assert(itemFinder("The five boxing wizards jump quickly", "") == 0);
    assert(itemFinder("", "boxing") == -1);
    assert(itemFinder("The five boxing wizards jump quickly", "The") == 0);
    
    return 0;
}