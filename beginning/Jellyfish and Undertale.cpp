#include<stdio.h>
int main()
{
	int t;
	scanf ("%d",&t);
	for(int j=0;j<t;++j)
	{
		int n,arr[1000];
		long long int a,b,min,s;
		scanf ("%lld %lld %d",&a,&b,&n);
		s=b;
		for(long long int i=0;i<n;++i)
		{
			scanf ("%lld",&arr[i]);
			if(arr[i]<a-1)
			{
				min=arr[i];
			}
			else
			{
			    min=a-1;
			}
			s+=min;
		}
		printf("%lld\n",s);
	}
	return 0;
}