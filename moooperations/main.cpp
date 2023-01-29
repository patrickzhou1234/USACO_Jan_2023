// http://usaco.org/index.php?page=viewproblem&cpid=1265
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, j, mxcor=0, cor=0;
    bool mf=false;
    cin >> n;
    string strs[n];
    for (i=0;i<n;i++) {
        cin >> strs[i];
    }
    for (i=0;i<n;i++) {
        mxcor=0, mf=false;
        if (strs[i].length()>=3) {
            for (j=0;j<=strs[i].length()-3;j++) {
                cor=0;
                if (strs[i].at(j)=='M') {
                    cor++;
                }
                if (strs[i].at(j+1)=='O') {
                    cor++;
                    mf=true;
                }
                if (strs[i].at(j+2)=='O') {
                    cor++;
                }
                mxcor = max(mxcor, cor);
            }
        } else {
            cout << -1 << "\n";
            continue;
        }
        if (!mf) {
            cout << -1 << "\n";
            continue;
        }
        cout << strs[i].length()-mxcor;
        cout << "\n";
    }
    system("pause");
    return 0;
}