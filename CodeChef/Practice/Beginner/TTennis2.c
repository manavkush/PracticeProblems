#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,a,b,l,count;
	char str[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		l=strlen(str);
		a=0,b=0,count=0;
		for(i=0;i<l;i++)
		{
			if(str[i]=='1')
			{
				a++;
			}
			else
			{
				b++;
			}
			if(a>=11 && a-b>=2)
			{
				count=1;
				break;
			}
			else if(b>=11 && b-a>=2)
			{
				count=0;
				break;
			}
		}
		if(count==1)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
}
