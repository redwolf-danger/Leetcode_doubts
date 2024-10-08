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
 
int main() {
   init_code();
   int t = 1; cin >> t;
   while(t--){
   	// cout<<"\n\n--------+++++++++_______test case : "<<t+1<<endl;
        readstr(s);
        // cout<<"s is "<<s nl;
        read(k);
        int copy = k; 
        int n = s.size();
        int st = 0;
        int end = 0;
        set<pair<int,int>> digs;
        int cnt = 0;
        string ans;
        int iterations = 30;
        if(copy == 0){
        	cout<<s nl;
        	continue;
        };
        bool rest_copy = true;
        while(copy>0 && iterations--){
              	// cout<<"\n------------\n-------\nst = "<<st<<" and end = "<<end nl;
        	if( (end == (n)) && ((end-st)<= copy)){
        		rest_copy = false;
        		break;
        	};
 
        	for(;((end<=st+copy) && (end<n));end++){
        		// cout<<"inserting "<<(s[end]-'0')<<", "<<end nl;
        		digs.insert({s[end]-'0',end});
        	};
        // 	//find the lowest index 
        	int l_idx = -1;
        	auto it = digs.begin();
        	pair<int,int> smallest = *(it);
        	if(cnt == 0 && smallest.first == 0){
        		//0 is not allowed so 
        		// cout<<"0 not allowed wala " nl;
 
        			// it++;
        			it = digs.upper_bound({0,INT_MAX});
        			l_idx = (*(it)).second;
        	}
        	else{
        		l_idx = smallest.second;
        	};
        	// cout<<"cnt is "<<cnt nl;
        	// cout<<"l_idx is "<<l_idx nl;
        	// cout nl;
        	ans.pb(s[l_idx]);
        	// cout<<"ans is "<<ans nl;
        	// cout<<"pushing "<<s[l_idx]<<endl;
        	copy -= (l_idx - st);
        	// cout<<"copy is now"<<copy nl;
        	while(st<=l_idx && iterations--){
        		digs.erase({s[st]-'0',st});
        		st++;
        	};
        	// cout<<"start modified to "<<st nl; 
        	cnt++;
        };
        if(rest_copy){
        	while(st<n){
        		ans.pb(s[st]);
        		st++;
        	};
        };
        cout<<ans;
        cout<<"\n";
   }
   return 0;
}
