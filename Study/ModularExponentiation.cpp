int multiply(int x,int n)
{
    if(n==0)
        return 1;

    else if(n%2)
        return x*multiply( x*x, (n-1)/2 );
    else    return multiply(x*x,n/2);
}
