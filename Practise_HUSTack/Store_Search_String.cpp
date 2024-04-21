#include<bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<string> database;

    string key;
    while (cin >> key && key != "*") {
        database.insert(key);
    }
    
    string cmd, k;
    while (cin >> cmd >> k && cmd != "***") {
        if (cmd == "find") {
            if (database.find(k) != database.end()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (cmd == "insert") {
            if (database.find(k) != database.end()) {
                cout << "0" << endl;
            } else {
                database.insert(k);
                cout << "1" << endl;
            }
        }
    }
    
    return 0;
}
