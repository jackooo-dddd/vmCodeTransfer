#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void usage(){
	printf("Usage: sortThem increasing|decreasing [NUMBER ...]\n");
	exit(1);
}


int isIncreasing(int a, int b){
	if(a<b)return 1;
	return 0;
}
int isDecreasing(int a, int b){
	if(a>b)return 1;
	return 0;
}

/** 
 * the sort function takes a pointer to a compare function as well
 * as a pointer to an array of integers and a length. Sort uses
 * the compare function (one of isIncreasing or isDecreasing) 
 * to sort the array of integers.
 */

// FIX THIS FUNCTION TO MATCH THE ABOVE COMMENT
void sort(int a[], int n){  
	int i1,i2;
	for(i1=0;i1<n-1;i1++){
		for(i2=i1+1;i2<n;i2++){
			// if a[i1] > a[i2], swap a[i1] to the right
			// after the inner loop terminates, the a[i1] is graunteed to be smallest among a[i1:]
			if(isIncreasing(a[i1], a[i2])==0){
				int temp=a[i2];
				a[i2]=a[i1];
				a[i1]=temp;
			}
		}
	}
}

int main(int argc, char ** argv){

	// define a pointer to one of compareIncreasing or compareDecreasing
	// FIX THIS BY DEFINING A FUNCTION POINTER
	int n=argc-2;
	int a[n];
	int i;

	if(argc<=1)usage();
	if(argc>=2){
		if(strcmp(argv[1], "increasing")==0){
			// FIX THIS BY ASSIGNING TO THE FUNCTION POINTER
			// Want sort point to a function sort increasingly
		} else if(strcmp(argv[1], "decreasing")==0){
			// FIX THIS BY ASSIGNING TO THE FUNCTION POINTER
			// Want sort point to a function sort decreasingly
		} else {
			usage();
		}
	}
	for(i=2;i<argc;i++){
		a[i-2]=atoi(argv[i]);
	}

	sort(a,n);  // FIX THIS TO USE THE FUNCTION POINTER DEFINED ABOVE

	for(i=0;i<n;i++){
		printf("%d\n", a[i]);
	}
	exit(0);
}
