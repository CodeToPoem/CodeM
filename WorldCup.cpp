#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;
void read_basic(float(*basic)[16]) {
	for (int i = 0; i < 16;i++) {
		for (int j = 0; j < 16;j++) {
			cin>>basic[i][j];
		}
	}
	/*cout << endl;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			cout << basic[i][j] << " ";
		}
		cout << endl;
	}*/
}
void gen_order(int n, int level, vector<int> &order) {//problem1 n-1
	int step = 16 / level;
	order.clear();
	if (n%step <= step / 2&& n%step>=1) {
		for (int i = step / 2+1; i <= step ; i++) order.push_back(n/step*step+i);
	}
	else {
		for (int i = 1; i <= step / 2; i++) order.push_back((n - 1) / step*step + i);
	}
	/*cout<<"n= "<<n <<" "<<"level= "<<level<<" "<< "order is:";
	for (auto it : order) cout << it << " ";
	cout << endl;*/
}
//处理二维数组
void ComputeProbability(float(*basic)[16],int level, vector<int> &order, float* Level_before, float* Level_after) {//problem2 初始化变量Level_after[i],概率计算公式有问题
	for (int i = 0; i < 16; i++) {
		gen_order(i+1, level, order);
		Level_after[i] = 0;
		//cout << "level= " << level << " n= " << i + 1 << " " << "p= ";
		for (auto it : order) {
			Level_after[i] += basic[i][it-1] * Level_before[it-1]*Level_before[i];
			//cout << basic[i][it - 1] << "*" << Level_before[it - 1] << "+ ";
		}
		//cout<<"= "<< Level_after[i] << endl;
	}
	//cout << endl;

}
//int main() {
//	float basic[16][16];
//	float level8[16], level4[16], level2[16], result[16];
//	vector<int> order;
//	read_basic(basic);
//	//生成level8
//	for (int i =0; i < 8; i++) {
//		level8[2 * i] = basic[2 * i][2 * i + 1];
//		level8[2 * i + 1] = 1 - level8[2 * i];
//	}
//	/*cout << "---level 8 is: ";
//	for (auto it : level8) cout << it << " ";*/
//	
//	ComputeProbability(basic, 4,order, level8, level4);
//	ComputeProbability(basic, 2, order, level4, level2);
//	ComputeProbability(basic, 1, order, level2, result);
//	//cout << "The result is: ";
//	for (auto it : result) cout << it << " ";
//	//cout << endl;
//	
//	return 0;
//}
