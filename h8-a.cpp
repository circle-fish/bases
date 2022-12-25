#include<iostream>
#include<cstring>
using namespace std;
 
int d[2005][2005];
 
/*
输入的两个字符数组为a[], b[]，从下标为0开始初始化
长度分别为length_a, length_b 
数组d[m][n]存放从a[1:m] 变为 b[1:n]所需要的最少操作
递归公式：
	d[i][j] = 0,    i=0或j=0 时(即数组的第一行和第一列均为0)
	1<=i<=length_a， 1<=j<=length_b 
	d[i][j] = d[i-1][j-1],  a[i-1] == b[j-1]  
	d[i][j] = min(d[i-1][j-1]+1, d[i][j-1]+1, d[i-1][j]+1),   a[i-1] != b[j-1]
最优值：d[length_a][length_b]
*/
 
int min(int a, int b, int c){
	int temp = a;
	if(temp > b){
		temp = b;
	}
	if(temp > c){
		temp =c;
	}
	return temp;
}
 
int edit(char *a, char *b){
	int length_a = strlen(a);
	int length_b = strlen(b);
	for(int i = 0; i <= length_a; i++){
		d[i][0] = i;
	}
	for(int i = 0; i <= length_b; i++){
		d[0][i] = i;
	}
	for(int i = 1; i <= length_a; i++){
		for(int j = 1; j <= length_b; j++){
			if(a[i-1] == b[j-1]){
				//d[i][j] = d[i-1][j-1];
				d[i][j] = min(d[i-1][j-1], d[i][j-1]+1, d[i-1][j]+1);
			}
			else{
				d[i][j] = min(d[i-1][j-1]+1, d[i][j-1]+1, d[i-1][j]+1);
			}
		}
	}
	return d[length_a][length_b];
}
 
int main(){
	char a[2000], b[2000];
	cin>>a>>b;
	cout<<edit(a, b);
}
