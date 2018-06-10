#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

int BuyN() {
	//freopen("1.in","r",stdin);
	int n = 0, m = 0;
	scanf("%d%d", &n,&m);
	double sum_origin=0, discount1=0, discount2=0;
	//scanf("%d", &m);
	/*vector<int> items;
	vector<int> item_flags;
	map<int, int> discount;
	for (int i = 0; i < n; i++) {
		int item = 0, item_flag = 0; scanf("%d %d", &item, &item_flag); 
		items.push_back(item);
		item_flags.push_back(item_flag);
	}
	for (int i = 0; i < m; i++) {
		int origin = 0, decrease = 0;
		scanf("%d%d", &origin, &decrease);
		discount.insert(make_pair(origin, decrease));

	}
	cout << "item:" << endl;
	for (auto it : items) cout << it << " ";
	cout << endl;
	for (auto it : item_flags) cout << it << " ";
	cout << endl;
	cout << "discount:" << endl;
	for (auto it : discount)
		cout << "(" << it.first << "," << it.second << ") ";
	cout << endl;*/
	int item = 0, item_flag = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &item, &item_flag);
		sum_origin += item;
		if (item_flag) discount1 += 0.2*item;
	}
	int origin = 0, decrease = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &origin, &decrease);
		if (sum_origin >= origin&&discount2<decrease) discount2 = decrease;

	}

	cout.setf(ios::fixed);                      //功能和下一行的fixed功能一样，同时写没关系
	cout << fixed << setprecision(2)<< sum_origin - max(discount1, discount2) << endl;
	return 0;
}