// http://usaco.org/index.php?page=viewproblem&cpid=1265
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, j, frcor=0, bckcor=0;
    cin >> n;
    string strs[n];
    for (i=0;i<n;i++) {
        cin >> strs[i];
    }
    for (i=0;i<n;i++) {
        frcor=0, bckcor=0;
        if (strs[i].length()>=3) {
            if (strs[i].at(0)=='M') {
                frcor++;
            }
            if (strs[i].at(1)=='O') {
                frcor++;
            } else {
                cout << -1 << "\n";
                continue;
            }
            if (strs[i].at(2)=='O') {
                frcor++;
            }
        } else {
            cout << -1 << "\n";
            continue;
        }
        if (strs[i].length()>=6) {
            if (strs[i].at(strs[i].length()-3)=='M') {
                bckcor++;
            }
            if (strs[i].at(strs[i].length()-2)=='O') {
                bckcor++;
            } else {
                cout << -1 << "\n";
                continue;
            }
            if (strs[i].at(strs[i].length()-1)=='O') {
                bckcor++;
            }
        }
        if (frcor>bckcor) {
            cout << strs[i].length()-frcor;
        } else {
            cout << strs[i].length()-bckcor;
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}