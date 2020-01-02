#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
// 8th Dec 2019
//не совсем работает
void clear (char *str, int n)
{
    int i;

    i = -1;
    while (++i < n)
        str[i] = '\0';
}


int main()
{
    char buf;
    char str[30];
    int ret;
    int i, j;
    int a[2];

    clear(str, 30);
    i = 0;
    j = 0;
    while ((ret = read(0, &buf, 1)))
    {
        if (buf == '\n')
            break;
        else if (buf == ' ' || buf == '\t')
        {
            a[j] = atoi(str);
            clear(str, 30);
            j++;
        }
        if (j == 2)
            break;
        str[i] = buf;
        i++;
    }
    printf("%d  %d", a[0], a[1]);

    return (0);
}
*/

//Чтение двух чисел из stdin
#include <stdio.h>

int main(void)
{
  int v[2];
  int i;
  
  i = 0;
  while (i < 2)
  {
    scanf("%d", &v[i]);  
    i++;
  }
  printf("%d", v[0] + v[1]);

  return (0);
}


