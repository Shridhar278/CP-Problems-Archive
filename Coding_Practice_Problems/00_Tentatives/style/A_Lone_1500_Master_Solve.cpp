#include <bits/stdc++.h>                      /*2 independent cases (start LEFT/RIGHT) both 1.CHECKED 2.VERFIED***************/
inline void fast_io() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); } int32_t main(){ fast_io(); int/************/
test;std::cin>>test; while(test--){int n, k;std::cin>>n;std::vector<int> arr; std::vector<int>strt;strt.push_back(1);/********/
int ar=1; std::vector <int> stlt; stlt.push_back(-1); int al=1; for (int i=0 ; i<n; i++) { std::cin>>k; arr.push_back/********/
(k);} for (int i=1;i<n; i++) { if(arr[i] == arr[i-1]) { strt.push_back(strt[i-1]*(-1)); stlt.push_back(stlt[i-1]*(-1)/********/
); } else if(arr[i] ==arr[i-1] -1) { if (strt[i-1]!= 1) { ar=0; } strt.push_back(strt[i-1]); if(stlt[i-1] != 1){al=0;/********/
}stlt.push_back(stlt[i-1]) ; } else if (arr[i] == arr[i-1] + 1) {if (strt[i-1] != -1) { ar=0; } strt.push_back(strt[i/********/
-1]); if(stlt[i-1]!=-1){al=0;}stlt.push_back(stlt[i-1]); } else {al=0;ar=0; break;}}/*final verification of suspected**********
solutions, since only counted difference POTENTIAL FLAWS like 3-2-2 example. #FINISHING TOUCH#*/int i=0; int count;/**********/
if (ar==1) {count=0 ; for(int j=0; j<n; j++) {if( i==j ) { count++; } else if (strt[j]==1) { count++; } } if(count !=/********/
arr[i]) {ar = 0;}} if(al==1){count=0; for(int j=0; j<n; j++){if(i==j){count++;}else if(stlt[j]==1){count++;}}if(count/********/
!=arr[i]){al=0;}}std::cout<<al+ar<<std::endl; } return 0;}/********************************************************************
************************************************************************THE MVP 1500 RATED 2155/C. The Ancient Wizards' Capes*/