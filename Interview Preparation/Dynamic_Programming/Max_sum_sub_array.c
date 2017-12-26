#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a,i,n,max=0,cur=0,end,start,tsum=0,t;
	scanf("%d",&n);
	a=(int)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		cur+=a[i];
		if(cur<0)
		{
			cur=0;
		}
		else
		{
			if(cur>max)
			{
				max=cur;
				end=i;
			}
		}
	}
	t=end;
	while(end>=0)
	{
		tsum+=a[end--];
		if(tsum==max)
		{
			start=end+1;
			break;
		}
	}
	printf("The max sum is %d and starting index %d ending index %d \n",max,start,t);
	return 0;
}