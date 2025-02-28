#include <stdio.h>
#include <unistd.h>

//    128 |  64  |  32  |  16  |  8  |  4  |  2  |   1 |
//
//	0    0      1      1       1    1     1     0
//
//
//

void print_bit(unsigned char oc)
{

	int i = 0;
	int ix[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	char is[8];
	char tmp[8];	
	while(i < 8)
	{
		if (oc >= ix[i])
		{
			oc = oc - ix[i];
			is[i] = '1';
			write(1, "1", 1);
		}
		else
		{	
			is[i] = '0';
			write(1, "0", 1);
		}
		i++;
	}
	int half = 4;
	
	write(1, "\n", 1);
	write(1, "\n", 1);
	
	i = 0;
	while(half < 8)
	{
		tmp[i] = is[half];
		if (is[half] == '1')
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
		half++;
	}
	int j = 0;
	while(j <= 3)
	{
		tmp[i] = is[j];
		if(is[j] == '1')
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
		j++;
	}
	write(1,"\n", 1);
	i = 0;
	int n = 0;
	while (i < 8)
	{
		if(tmp[i] == '1')
			n +=  ix[i];
	       	i++;	
	}
	printf("%d\n", n);
}
	

int  main ()
{
	print_bit(62);
	return 0;
}
