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
#define mod 1000000007
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

ll findopern(vector<ll>& prefix,ll target, ll idx){
	ll n = prefix.size();
	ll start = (idx?prefix[idx-1] : 0);
	ll till_end = prefix[n-1] - start;
	if(till_end >= target){
		//find the idx that 
		ll j = lower_bound(prefix.begin()+idx,prefix.end(),start + target) - prefix.begin();
		return (j-idx+1);
	}
	else{
		ll intial_operns = n-idx;
		target -= till_end;
		ll iterateoperns = target/prefix[n-1];
		target -= iterateoperns*prefix[n-1];
		ll it = lower_bound(prefix.begin(),prefix.end(),target) - prefix.begin();
		ll finalOperns = (it+1);
		return (intial_operns + iterateoperns*n + finalOperns);
	}
}
int main() {
   init_code();
   		ll ans = -1;
        readll(n);
        readll(p);
       	vl(arr,n,0);
       	read_vec(arr);
       	ll sum = 0;
       	vl(prefix,n,0);
       	fr(0,n){
       		sum += arr[i];
       		prefix[i] = sum;
       	};
       	// ll r = (p/sum + 1)*n;
       	ll operns = inf;
       	fr(0,n){
       		ll op = findopern(prefix,p,i);
       		if(operns>op){
       			operns = op;
       			ans = i;
       		};
       	};
       	ans++;
       	cout<<ans;
       	cout<<" "<<operns;
        cout<<"\n";
   return 0;
}
