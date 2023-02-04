// http://usaco.org/index.php?page=viewproblem&cpid=1264
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct cow {
    int si, ti, ci;
};

struct conditioner {
    int ai, bi, pi, m;
};

string incrementBin(string binstr) {
    int i, j, origlen;
    for (i=binstr.length()-1;i>=0;i--) {
        if (binstr[i]=='0') {
            binstr[i]='1';
            if (i!=binstr.length()-1) {
                for (j=i+1;j<binstr.length();j++) {
                    binstr[j]='0';
                }
            }
            break;
        }
    }
    if (i==-1) {
        origlen=binstr.length();
        binstr = '1';
        for (i=0;i<origlen;i++) {
            binstr+='0';
        }
    }
    return binstr;
}

int main() {
    int n, m, i, j, q, mncst=MAX_INT, cst, mxstl=-1;
    bool satisfied=true;
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
    string bin = "";
    for (i=0;i<m;i++) {
        bin+='0';
    }
    while (true) {
        for (i=0;i<m;i++) {
            if (bin[i]=='0') {
                break;
            }
        }
        if (i==m) {
            break;
        }
        cst=0;
        for (i=0;i<mxstl+1;i++) {
            stalltmp[i]=0;
        }
        for (i=0;i<m;i++) {
            if (bin[i]=='1') {
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
                    mncst = min(mncst, cst);
                }
            }
        }
        bin = incrementBin(bin);
    }
    cout << mncst;
    system("pause");
    return 0;
}