# include<stdio.h> 
# define MAX_SIZE 100 
  
  
void foo(char *str, int pos, int n, int open, int close) 
{ 
	if(close == n)  
	{
		printf("%s\n", str); 
		return; 
	}
	if(open < n) 
	{
		str[pos] = '('; 
		foo(str, pos + 1, n, open + 1, close); 
	}
	if(open > close)  
	{
		str[pos] = ')'; 
		foo(str, pos + 1, n, open, close + 1); 
	}  
}


int main() 
{ 
	int n;
	int i;
	char str[MAX_SIZE];

	i = -1;
	while (++i < MAX_SIZE)
		str[i] = 0;

	scanf("%d", &n);
	foo(str, 0, n, 0, 0); 
	return 0; 
} 