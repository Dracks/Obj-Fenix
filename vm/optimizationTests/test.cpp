#include<iostream>
#include <time.h>
#include <stdlib.h>

#define N 100000000

#define kInstructions 20

void *optable[kInstructions];

int vrand[N];

int test1(){
	int a=0;
	for (int i=0; i<N; i++){
		switch(vrand[i]){
			case 0:
				a++;
				break;
			case 1:
				a+=2;
				break;
			case 2:
				a-=1;
				break;
			case 3:
				a-=2;
				break;
			case 4:
				a+=3;
				break;
			case 5:
				a-=3;
				break;
			case 6:
				a+=4;
				break;
			case 7:
				a-=4;
				break;
			case 8:
				a+=5;
				break;
			case 9:
				a-=6;
				break;
			case 10:
				a+=10;
				break;
			case 11:
				a+=12;
				break;
			case 12:
				a-=11;
				break;
			case 13:
				a-=12;
				break;
			case 14:
				a+=13;
				break;
			case 15:
				a-=13;
				break;
			case 16:
				a+=14;
				break;
			case 17:
				a-=14;
				break;
			case 18:
				a+=15;
				break;
			case 19:
				a-=16;
				break;
		}
	}
	return a;
}

int test2(){
	int a=0;
		optable[0]=&&gt0;
		optable[1]=&&gt1;
		optable[2]=&&gt2;
		optable[3]=&&gt3;
		optable[4]=&&gt4;
		optable[5]=&&gt5;
		optable[6]=&&gt6;
		optable[7]=&&gt7;
		optable[8]=&&gt8;
		optable[9]=&&gt9;
		optable[10]=&&gt10;
		optable[11]=&&gt11;
		optable[12]=&&gt12;
		optable[13]=&&gt13;
		optable[14]=&&gt14;
		optable[15]=&&gt15;
		optable[16]=&&gt16;
		optable[17]=&&gt17;
		optable[18]=&&gt18;
		optable[19]=&&gt19;
	int i=-1;
	end:
	i++;
	while (i<N){
	//for (int i=0; i<N; i++){
		goto *optable[vrand[i]];
		gt0:
			a++;
			goto end;
		gt1:
			a+=2;
			goto end;
		gt2:
			a-=1;
			goto end;
		gt3:
			a-=2;
			goto end;
		gt4:
			a+=3;
			goto end;
		gt5:
			a-=3;
			goto end;
		gt6:
			a+=4;
			goto end;
		gt7:
			a-=4;
			goto end;
		gt8:
			a+=5;
			goto end;
		gt9:
			a-=6;
			goto end;
		gt10:
			a+=10;
			goto end;
		gt11:
			a+=12;
			goto end;
		gt12:
			a-=11;
			goto end;
		gt13:
			a-=12;
			goto end;
		gt14:
			a+=13;
			goto end;
		gt15:
			a-=13;
			goto end;
		gt16:
			a+=14;
			goto end;
		gt17:
			a-=14;
			goto end;
		gt18:
			a+=15;
			goto end;
		gt19:
			a-=16;
			goto end;
		//end:
		//	a=a;
	}
	return a;
}


int main (void){
	clock_t start, finish;
	int result;
	printf("initializing vector\n");
	for (int i=0; i<N; i++){
		vrand[i]=rand() % kInstructions; 
	}
	start=clock();
	result=test1();
	finish=clock();
	printf("Test 1\nTime: %f\nResult: %d\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ), result);
	start=clock();
	result=test2();
	finish=clock();
	printf("Test 2\nTime: %f\nResult: %d\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ), result);
	start=clock();
	result=test1();
	finish=clock();
	printf("Test 1\nTime: %f\nResult: %d\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ), result);
	start=clock();
	result=test2();
	finish=clock();
	printf("Test 2\nTime: %f\nResult: %d\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ), result);

	
	return 0;
}
