/* SPOJ http://www.spoj.com/problems/SHPATH/  
    https://github.com/cacophonix/SPOJ/blob/master/SHPATH.cpp
    */
#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

#define  MAXT 10
#define MAXN 10000
#define RANGECHECK(x,a,b) assert(a<=x && b>=x)

inline void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned int T; cin>>T;
    RANGECHECK(T, 1, MAXT);
    while(T--)
    {
        unsigned long long n; cin>>n;
        RANGECHECK(n, 1, MAXN);
        
        vector <string> placenames(n);
        int details[n][n];
        
        for(int row=0; row<n; row++)
            for(int col=0; col<n; col++)
                details[row][col]=0;
            
        
        
        for(int ind=0; ind<n; ++ind) {
            cin>>placenames[ind];
            int noOfNeig; cin>>noOfNeig;
            
            while(noOfNeig--) {
                int neig; cin>>neig;
                cin>>details[ind][neig-1];
               
            }
        }
        
        for(int i=0; i<n; ++i) {
            cout<<placenames[i]<<"  ";
            for(int col=0; col<n; col++) {
                cout<<details[i][col]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
