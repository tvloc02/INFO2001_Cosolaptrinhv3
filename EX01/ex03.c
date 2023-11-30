#include<stdio.h> 
int main ()
{
	int a[5];
	int i,n,max,x,t,s;
	scanf("%d",&n);
	for (i=0;i<=n;i++)
		{
			printf("nhap pt thu a[%d] = ",i); 
			scanf("%d",&a[i]); 
			printf("\n"); 
		 } 
	for (i=0;i<=n;i++)
		{
			printf("   %d",a[i]); 
		 }
}
