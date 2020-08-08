#include <iostream>
#include <list>
#include <malloc.h>
using namespace std;


class jh {
public:
	//int getListLength();
	//void printArray(int *yuan);
	//void printList();
	//int *connectArray(int *yuan, int add);
	//void get(int start, int end, int *lasti);

	list<int*> lis;


	jh(int length){
		get(1, length, NULL);
	}
	int getListLength() {
		list<int*>::iterator itor;
		int l1 = 0;
		for (itor = lis.begin(); itor != lis.end(); itor++) {
			l1++;
		}
		return l1;
	}
	void printList() {
		list<int*>::iterator itor;
		for (itor = lis.begin(); itor != lis.end(); itor++) {
			printArray(*itor);
			list<int*>::iterator i_itor;
			i_itor = itor;
			i_itor++;
			if (i_itor != lis.end()) {
				printf("\n");
			}
		}
	}
	void printArray(int *yuan) {
		int length = *yuan;
		for (int i = 1; i < length; i++) {
			printf("%d ", *(yuan + i));
		}
	}
	/*
	连接一个数组和一个整数
	*/
	int *connectArray(int *yuan, int add) {
		int *ret;
		if (yuan == NULL) {
			ret = (int*)calloc(2, sizeof(int));
			*ret = 2;
			*(ret + 1) = add;
		}
		else
		{
			int length = *yuan;
			ret = (int*)calloc(length + 1, sizeof(int));
			*ret = length + 1;
			for (int i = 1; i < length; i++) {
				*(ret + i) = *(yuan + i);
			}
			*(ret + length) = add;
		}
		return ret;
	}
	void get(int start, int end, int *last) {
		for (int i = start; i <= end; i++) {
			int *now;
			now = connectArray(last, i);
			lis.push_back(now);
			if (i != end) {
				get(i + 1, end, now);
			}
		}
	}
};
int main() {
	int max;
	cin >> max;
	jh jh1(max);
	jh1.printList();
	printf("\n理论输出%d,实际输出%d(不包含空集)", int(pow(2, max)), jh1.getListLength());
}.xpp
