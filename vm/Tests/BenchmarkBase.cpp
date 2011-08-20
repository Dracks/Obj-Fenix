#include<iostream>
#include <time.h>
//#include<string>
//#include"test2.h"

void test(){
	int i=0;
	do {
		i++;
	}while (i-1000000);
	printf("Hola Mon\n");
}

int main (void){
/*	test1* t1;
	void* t2;
	t2=&(test2::test2);
	t1=new t2();
	t1->show();
*/
	clock_t start, finish;
	start=clock();
	test();
	finish=clock();
	printf("Time: %f\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ));

	
	return 0;
}
