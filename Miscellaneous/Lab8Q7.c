#include<stdio.h>
#include<string.h>

char* strcompression(char a[],int n)
{
    // checking if all elements are the same
    int flag=0,i;
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
    {


        printf("%c%d",a[0],n);
    }
    else
    {
        int index;
        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                index=i;
                break;
            }
        }
        char b[500],c[500];
        for(i=0;i<index;i++)
            b[i]=a[i];
        for(i=index;i<n;i++)
            c[i-index]=a[i];
        return strcat( strcompression(b,index) ,  strcompression(c,n-index) );
    }
}

void main()
{
    char str[500];
    scanf("%s",str);
    int n;
    n=strlen(str);

    printf("%s",strcompression(str,n));
}
