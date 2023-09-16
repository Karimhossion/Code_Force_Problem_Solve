#include <iostream>
#include <string>
#include <unordered_map>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> userCounts;
 
    for (int i = 0; i < n; i++) {
        string username;
        cin >> username;
 
        if (userCounts.find(username) == userCounts.end()) {
            // User does not exist, register and print OK
            userCounts[username] = 1;
            cout << "OK" << endl;
        } else {
            // User exists, find the next available username
            while (userCounts.find(username + to_string(userCounts[username])) != userCounts.end()) {
                userCounts[username]++;
            }
 
            string newUsername = username + to_string(userCounts[username]);
            userCounts[username]++;
            cout << newUsername << endl;
        }
    }
 
    return 0;
}