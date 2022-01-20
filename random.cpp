#include <stdio.h>
int main(){
	int a,b,c;
	int i;
	for(i=1;i<=907555;i++){
		a=random()%6;
		b=rand()%6;
		c=rand()%6;
	}
	printf("%d + %d + %d =%d",a,b,c,(a+b+c));
	}
