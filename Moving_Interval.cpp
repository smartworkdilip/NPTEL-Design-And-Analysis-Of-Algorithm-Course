/*
Question-
   Moving Intervals

There are C cakes in a row, numbered from 1 to C. There are N children, each of whom have selected a consecutive set of cakes to eat. That is, Child i has decided to
eat all the cakes from Si to Ei, end points inclusive. If there is a cake which appears in some two childrens' set, then they will fight because both of them want to eat
that cake, and you don't want that to happen.

You will be given an integer K which will be either 0 or 1. If K is 0, then you should find out if some two children will fight. Print "Good" if no one fights, and "Bad"
if someone fights.

If K is 1, then you can persuade at most one child to change his decision to some other set of cakes. But the number of cakes that he eats must be the same.
That is, if Child i had initially decided that he wants to eat the cakes from Si to Ei, then you could persuade the child to instead eat the cakes from X to Y instead,
for any valid X and Y (ie. 1 ≤ X ≤ Y ≤ C), provided that the number of cakes is the same (ie. Ei - Si + 1 = Y - X + 1). If after persuading at most 1 Child to change his
decision, no fights happen, then print "Good". But if no matter what you do, someone will fight, then print "Bad".

Input format
The first line of each test case contains three integers C, N and K denoting the number of cakes, number of children and K, respectively.

The i-th of the next N lines contains two space separated integers Si and Ei which denotes the initial decision of Child i.
That is, Child i wants to eat from cake Si to cake Ei.

Output format
For each test case, output a single line containing "Good" or "Bad".
Constraints
1 ≤ T ≤ 10
1 ≤ C ≤ 109
1 ≤ N ≤ 105
0 ≤ K ≤ 1
1 ≤ Si, Ei ≤ C

*/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

struct student{
	ll x, y;
};
student st[N];

bool cmp(student xx, student yy){
       return  xx.x < yy.x;
}

vector<ll> v;

int main(int argc, char const *argv[]){
	ll c, n, k, o1 = -1, o2 = -1, prev = 1, flag = 0, oc1 = 0, oc2 = 0;
	cin >> c >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> st[i].x >> st[i].y;
	}
	sort(st, st + n, cmp);
	for (int i = 0; i < n - 1; ++i){
		if(st[i].y >= st[i + 1].x){
		       flag = 1;
		       o1 = i;
		       o2 = i + 1;
		       v.push_back(i);
		}
	}
	if(!flag){
	       return cout <<"Good",0;
	}
	if((k==0 && flag) ||(v.size() > 2)){
	       return cout << "Bad",0;
	}
	if(v.size() == 2 && v[0] + 1 != v[1]){
	       return cout << "Bad",0;
	}
	st[n].x = c + 1;
	st[n].y = c + 1;
	for(int i = 0;i < n; ++i){
	       if((st[i].x >= st[o1].x && st[i].x <= st[o1].y) || (st[i].y >= st[o1].x && st[i].y <= st[o1].y)){
                     ++oc1;
	       }
	       if((st[i].x >= st[o2].x && st[i].x <= st[o2].y) || (st[i].y >= st[o2].x && st[i].y <= st[o2].y)){
                     ++oc2;
	       }
	}
	if(oc1 > oc2){
	       o2 = o1;
	}
	else if(oc2 > oc1){
	       o1 = o2;
	}
	for (int i = 0; i < n + 1; ++i){
	       if(i == o1){
	              continue;
	       }
		if((st[i].x - prev) >= (st[o1].y - st[o1].x + 1)){
			return cout <<"Good",0;
		}
		prev = st[i].y + 1;
	}
	prev = 1;
	for (int i = 0; i < n + 1; ++i){
	       if(i == o2){
	              continue;
	       }
		if((st[i].x - prev) >= (st[o2].y - st[o2].x + 1)){
			return cout <<"Good",0;
		}
		prev = st[i].y + 1;
	}
	return cout << "Bad",0;
}
