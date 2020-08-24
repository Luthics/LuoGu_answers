#include <bits/stdc++.h>
using namespace std;

int n,l,r,a=0,b=0,sum=0;
int s[110];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		sum+=s[i];
	}
	cin >> l >> r;
	for(int i=1;i<=n;i++){
		if(s[i]>r) a+=s[i]-r;
		if(s[i]<l) b+=l-s[i];
	} 
	if(sum>n*r) cout << "-1";
	else cout << max(a,b);
	return 0;
}
