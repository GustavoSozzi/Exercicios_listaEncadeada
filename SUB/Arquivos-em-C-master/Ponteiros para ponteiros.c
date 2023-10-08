#include<stdio.h>
int main(){
	float pi=3.1415,*pf,**ppf;
	pf=&pi;
	ppf=&pf;
	printf("\n%X",&pi);
	printf("\n%X",&ppf);
	printf("\n%X",&pf);
	
	return 0;
}
