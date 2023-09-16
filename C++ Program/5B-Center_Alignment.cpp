#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> lines;
    int maxLength = 0;

    // Read input lines and find the maximum line length
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
        maxLength = max(maxLength, static_cast<int>(line.length()));
    }

    // Print the top border
    for (int i = 0; i < maxLength + 2; i++)
        cout << '*';
    cout << endl;

    int leftSpaces = 0;
    int rightSpaces = 0;
    bool bringLeft = true;

    // Print formatted text
    for (const string& s : lines) {
        cout << '*';

        int spaces = maxLength - s.length();

        if (spaces % 2 == 0) {
            // Even number of spaces
            leftSpaces = spaces / 2;
            rightSpaces = spaces / 2;
        } else {
            // Odd number of spaces
            if (bringLeft) {
                leftSpaces = spaces / 2;
                rightSpaces = spaces / 2 + 1;
            } else {
                leftSpaces = spaces / 2 + 1;
                rightSpaces = spaces / 2;
            }
            bringLeft = !bringLeft;
        }

        // Print left spaces
        for (int j = 0; j < leftSpaces; j++)
            cout << ' ';

        // Print the line
        cout << s;

        // Print right spaces
        for (int j = 0; j < rightSpaces; j++)
            cout << ' ';

        cout << '*' << endl;
    }

    // Print the bottom border
    for (int i = 0; i < maxLength + 2; i++)
        cout << '*';
    cout << endl;

    return 0;
}
