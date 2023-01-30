// http://usaco.org/index.php?page=viewproblem&cpid=1264
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct cow {
    int si, ti, ci;
};

struct conditioner {
    int ai, bi, pi, m;
};

int main() {
    int n, m, i, j, q, mxstl=-1, cst=0;
    bool satisfied=true;
    int valuefirst, valuesecond;
    cin >> n >> m;
    cow cows[n];
    conditioner conds[m];
    for (i=0;i<n;i++) {
        cin >> cows[i].si >> cows[i].ti >> cows[i].ci;
    }
    for (i=0;i<m;i++) {
        cin >> conds[i].ai >> conds[i].bi >> conds[i].pi >> conds[i].m;
    }
    for (i=0;i<n;i++) {
        mxstl = max(mxstl, cows[i].ti);
    }
    int stalltmp[mxstl+1]={0};
    // bubble sort
    bool swapped;
    for (i = 0; i < n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            valuefirst = conds[j].pi*max(0, min(cows[i].ti, conds[j].bi) - max(cows[i].si, conds[j].ai))/conds[j].m;
            valuesecond = conds[j + 1].pi*max(0, min(cows[i].ti, conds[j+1].bi) - max(cows[i].si, conds[j+1].ai))/conds[j+1].m;
            if (valuefirst < valuesecond)
            {
                swap(conds[j], conds[j+1]);
                swapped = true;
            }
        }
    
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
    for (i=0;i<m;i++) {
        for (j=conds[i].ai;j<=conds[i].bi;j++) {
            stalltmp[j]+=conds[i].pi;
        }
        cst+=conds[i].m;
        satisfied=true;
        for (j=0;j<n;j++) {
            for (q=cows[j].si;q<=cows[j].ti;q++) {
                if (stalltmp[q]<cows[j].ci) {
                    break;
                }
            }
            if (q==cows[j].ti+1 && satisfied) {
                satisfied=true;
            } else {
                satisfied=false;
            }
        }
        if (satisfied) {
            cout << cst;
            return 0;
        }
    }
    system("pause");
    return 0;
}