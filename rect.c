#include <stdio.h>


int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
   c = a;
   a = b;
   b = c;
    printf("%d %d", a, b);
}

/*
int main()
{
   int a,b;

   scanf("%d %d", &a, &b);
   printf("%d\n", a + b);

   return (0);
}

*/