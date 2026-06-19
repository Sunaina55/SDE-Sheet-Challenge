#include <bits/stdc++.h>
using namespace std;

vector<int> generateRows(int row) {
    long long ans = 1;
    vector<int> ansRow;

    ansRow.push_back(1);

    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

int main() {
    int numRows;
    cin >> numRows;

    vector<vector<int>> triangle;

    for (int row = 1; row <= numRows; row++) {
        vector<int> temp = generateRows(row);
        triangle.push_back(temp);
    }

    for (auto &row : triangle) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}