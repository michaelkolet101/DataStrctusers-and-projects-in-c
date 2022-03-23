#include <stdio.h> 
 


int BrokenCalc(int startValue, int target)
{
    int ret = 0;
    
    while(target != startValue)
    {
        ++ret;
        
        if (target % 2 == 0)
        {
            target /= 2;
        }
        else
        {
            ++target;
        }
    }
    return ret;
    
}	


int main(void) 
{ 
	int num1 = 3;
	int tar = 10;

	int ans = BrokenCalc(num1, tar);

	if (ans == 3)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	return(0);			 
}

