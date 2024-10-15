/*
submission by: advaita soni
*/
#include <iomanip>
#include <ios>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 998244353
#define inf (1LL<<60)
//#define all(x) (x).begin(), (x).end()
//#define prDouble(x) cout << fixed << setprecision(10) << x
//#define triplet pair<ll,pair<ll,ll>>
//#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define readstr(x) string x;cin>>x
#define readll(x) long long x; cin>>x 
#define vi(name,n,d) vector<int> name (n,d)
#define vl(name,n,d) vector<long long> name (n,d)
#define nl <<"\n";
#define endl "\n"
#define flush cout.flush();

using namespace std;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


//assuming empty array
void read_vec(vector<ll>& arr){
 for(auto& it: arr){
 cin>>it;
 }
 };

 void print_arr(vector<ll>& arr){
 for(auto it:arr){
    cout<<it<<" ";
 };
 cout<<"\n";
 };

 ll factorial(ll n){
 	if(n <2)return 1;
 	ll ans = 1;
 	for(int i = 1;i<=n;i++){
 		ans = (ans*i)%mod;
 	};
 	return ans;
};

ll bin_power(ll num, ll p){
	if(p == 0){
		return 1LL;
	};
	ll res = bin_power(num,(p/2));
	res = ((res%mod)*(res%mod))%mod;
	if(p%2) return (res*num)%mod;
	return res;
}

int main() {
   init_code();
   int t = 1; cin >> t;
   while(t--){
        readll(n);
        vl(arr,n,0);
        read_vec(arr);;
        bool equal = true;
        ll maxi = -10;
        for(auto it: arr){
        	maxi = max(maxi,it);
        	if(it != arr[0]){
        		equal = false;
        		// break;
        	};
        };
        ll permutation = factorial(n);
        if(equal){
        	//find permutation
        	cout<<permutation nl;
        }
        else{
        	ll second_maxi = -1;
        	for(auto it: arr){
        		if(it!=maxi && it>second_maxi) second_maxi = it;
        	};
        	// cout<<"maxi = "<<maxi nl;
        	// cout<<"second_maxi = "<<second_maxi nl;
        	if(maxi-second_maxi>1){
        		cout<<0 nl;
        		continue;
        	};
        	int cnt = 0;
        	for(auto it: arr){
        		cnt += (it == second_maxi);
        	};
         int cnthighest = 0;
         for(auto it: arr){
            cnthighest += (it == maxi);
         };
         if(cnthighest == 1){
               ll modinv = bin_power(cnt+1,mod-2);
               ll ans = (permutation*modinv)%mod;
               cout<<(ans*cnt)%mod nl;
         }
         else{
            cout<<permutation nl;
         }
        
        }
   }
   return 0;
}
