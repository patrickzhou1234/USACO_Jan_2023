// http://usaco.org/index.php?page=viewproblem&cpid=1263
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct cow {
    char breed;
    int ls;
};

int main() {
    int n, i, firstH=-1, lastH=-1, firstG=-1, lastG=-1, ct=0;
    cin >> n;
    cow cows[n];
    for (i=0;i<n;i++) {
        cin >> cows[i].breed;
    }
    for (i=0;i<n;i++) {
        cin >> cows[i].ls;
    }
    for (i=0;i<n;i++) {
        if (cows[i].breed=='H') {
            if (firstH==-1) {
                firstH=i;
                lastH=i;
            } else {
                lastH=i;
            }
        }
        if (cows[i].breed=='G') {
            if (firstG==-1) {
                firstG=i;
                lastG=i;
            } else {
                lastG=i;
            }
        }
    }
    bool perfectpair=false;
    if (cows[firstH].ls>lastH && cows[firstG].ls>lastG) {
        ct++;
        perfectpair=true;
    }
    if (cows[firstG].ls>lastG) {
        for (i=firstG-1;i>=0;i--) {
            if (cows[i].breed=='H' && cows[i].ls>firstG) {
                if (perfectpair && i==firstH) {
                    continue;
                }
                ct++;
            }
        }
    }
    if (cows[firstH].ls>lastH) {
        for (i=firstH-1;i>=0;i--) {
            if (cows[i].breed=='G' && cows[i].ls>firstH) {
                if (perfectpair && i==firstG) {
                    continue;
                }
                ct++;
            }
        }
    }
    cout << ct;
    system("pause");
    return 0;
}