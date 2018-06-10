#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include "math.h"
using namespace std;
static int steps = 0;
int findneg(vector<int> &c, int index) {
	for (int i = index; i >= 0; i--)
		if (c[i] < 0) 	return i;
	return -1;
}
int findpos(vector<int> &c) {//right pos

	for (int i = c.size() - 1; i >= 0; i--)
		if (c[i] > 0) 	return i;
	return -1;
}
void processPos(vector<int> &c, int index) {
	int index_neg = findneg(c, index);
	while (index_neg >= 0) {

		if (-c[index_neg] > c[index]) {
			steps += c[index] * (index - index_neg);//顺序很重要
			c[index] = 0;
			c[index_neg] += c[index];



			//cout << steps<<endl;
			return;
		}
		else {
			steps -= c[index_neg] * (index - index_neg);
			c[index] += c[index_neg];
			c[index_neg] = 0;

			//cout << steps << endl;
		}
		index_neg = findneg(c, index);
		//cout << "c:";
		//for (auto it : c) cout << it << " ";
		//cout << endl;
		//cout << "pos: " << index << " neg " << index_neg << endl;

	}
	return;
}
void read_array() { //读数组
	int n = 0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	cout << "a:" << endl;
	for (int i = 0; i < n; i++) {
		cout << *(a + i) << " ";
	}
	delete[] a;
}
int main() {

	int n = 0;
	cin >> n;
	vector <int> a, c;
	int tmp = 0;
	for (int i = 0; i < n; i++) {

		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {

		scanf("%d", &tmp);
		c.push_back(a[i] - tmp);
	}


	//for (auto it : c) cout << it << " ";
	//cout << endl;

	int pos_index = findpos(c);
	//cout << pos_index << endl;
	while (pos_index>0 && findneg(c, pos_index) >= 0) {//两个条件
		processPos(c, pos_index);
		pos_index = findpos(c);//更新pos_index
	}


	if (findneg(c, c.size() - 1) >= 0) {
		for (int i = 1; i < c.size(); i++) {
			if (c[i] > 0) steps += i*c[i];
		}
		for (int i = 0; i < c.size(); i++) {
			if (c[i]<0) steps -= i*c[i];
		}
	}
	cout << steps;
	return 0;
}
