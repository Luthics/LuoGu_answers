#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

int a,b;
bool zs[100000001];

void prime(int b) {
    memset(zs,1,sizeof(zs));
    zs[1]=0;
    int n=sqrt(b);
    for(int i=2;i<=n;i++){
        if(zs[i]){
            for(int j=2;j<=b/i;j++)
                zs[i*j]=0;
        }
    }
}

bool hw(int x){
    int y=x,num=0;
    while (y!=0){
        num=num*10+y%10;
        y/=10;
    } 
    if (num==x) return 1;
    else return 0;
}

string gplus(string a,string b){
	while(a.size()<b.size()) a="0"+a;
	while(a.size()>b.size()) b="0"+b;
	int cd=a.size();
	int s[2000];
	for(int i=0;i<2000;i++) s[i]=0;
	string c="";
	for(int i=a.size()-1;i>=0;i--){
		s[cd-i-1]+=a[i]-'0'+b[i]-'0';
		if(s[cd-i-1]>0){
			s[cd-i]+=s[cd-i-1]/10;
			s[cd-i-1]%=10;
		}
	}
	if(s[cd]>0) cd++;
	for(int i=cd-1;i>=0;i--) c+=s[i]+'0';
	return c;
}

string gc(string a,string b){
	if(a=="0"||b=="0") return "0";
	int cd=a.size()+b.size();
	int s[10000],a1[10000],b1[10000];
	for(int i=0;i<2000;i++){
		s[i]=0;
		a1[i]=0;
		b1[i]=0;
	}
	for(int i=a.size()-1;i>=0;i--) a1[a.size()-i-1]=a[i]-'0';
	for(int i=b.size()-1;i>=0;i--) b1[b.size()-i-1]=b[i]-'0';
	for(int i=0;i<=a.size()-1;i++){
		for(int j=0;j<=b.size()-1;j++){
			s[i+j]+=a1[i]*b1[j];
			//cout << a1[i] << " " << b1[j];
		}
	}
	for(int i=0;i<cd;i++){
		if(s[i]>9){
			s[i+1]+=s[i]/10;
			s[i]%=10;
		}
	}
	for(int i=cd;i>=0;i--){
		if(s[i]==0) cd--;
		else break;
	}
	string c="";
	//cout << cd << " ";
	for(int i=cd;i>=0;i--) c+=s[i]+'0';
	return c;
}

string dd(string a){
	string b="";
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	return b;
}

string its(int a){
	string c="";
	while(a){
		c+=a%10+'0';
		a/=10;
	}
	c=dd(c);
	return c;
}

string jc(int a){
	string jg="1";
	for(int i=1;i<=a;i++){
		//cout << jg << " " << its(i) << " " << gc(jg,its(i)) << "|";
		jg=gc(jg,its(i));
		//cout << jg << "|"; 
	}
	//cout << endl;
	return jg;
}

int sm(string a,int b){
	int ans=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'==b) ans++;
	}
	return ans;
}

int main(){
	freopen("title.txt","r",stdin);
	cin >> a >> b;
	prime(b);
	//cout << zs[5];
	if(a>b) return 0;
	if(a%2==0) a++;
	for(int i=a;i<=b;i+=2){
		if(zs[i]==1&&hw(i)) cout << i << endl;
	}
}
