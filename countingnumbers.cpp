/*
submission by: advaita soni
*/
#include <iomanip>
#include <ios>
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define readstr(x) string x;cin>>x
#define nl <<"\n";
using namespace std;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

vector<vector<vector<ll>>> dp(20,vector<vector<ll>>(11,vector<ll>(2,-1))); 

string glob; 
ll answer(ll digits, ll prev, bool bounded){
	if(digits == 0) return 1;
	if(dp[digits][prev][bounded] != -1 && prev!=10){
		return dp[digits][prev][bounded];
	}
	if(!bounded){
		int lower = 0;
		int upper = 9;
		ll temp = 0;
		for(int this_dig = lower;this_dig<=upper;this_dig++){
			if(this_dig!=prev){
				temp += answer(digits-1,this_dig,bounded);
			};
		};
		dp[digits][prev][bounded] = temp;
	}
	else{
		int lower = glob[glob.size() - digits]-'0';
		int upper = 9;
		ll temp = 0;
		if(prev == 10 and lower == 0){
			for(int this_dig = lower;this_dig<=upper;this_dig++){
				if(this_dig == lower) temp += answer(digits-1,10,true);
				else temp += answer(digits-1,this_dig,false);
			}
		}
		else{
		for(int this_dig = lower;this_dig<=upper;this_dig++){
			if(this_dig!=prev){
				if(this_dig == lower){
					temp += answer(digits-1 ,this_dig, true);
				}
				else{
					temp += answer(digits-1,this_dig,false);
				};
			};
		};
		}
		dp[digits][prev][bounded] = temp;
	};
	return dp[digits][prev][bounded];
	return 0;
}

int main() {
   init_code();
   readstr(a);
   readstr(b);


   if(a == b){
    bool include_a = true;
   for(int i = 1;i<a.size();i++){
   	if(a[i] == a[i-1]) include_a = false; 
   };
   cout<<include_a nl;
   return 0;
   }   
   if(a.size()>b.size()){
   	int diff = a.size() - b.size();
   	string additional(diff,'0');
   		b = additional + b;

   }
   else if(b.size()>a.size()){
   	int diff = b.size() - a.size();
   string additional(diff,'0');
   		a = additional + a;
   };
   glob = a;
    ll t1 = answer(glob.size(),10,1);

   for(int digits = 0;digits<=19;digits++){
   	for(int dig = 0;dig<=10;dig++){
   		dp[digits][dig][1] = {-1};
   	};
   };

   glob = b;
   ll t2 = answer(glob.size(),10,1);
   ll ans = abs(t1 - t2);
   cout<<ans nl;
   return 0;
}
