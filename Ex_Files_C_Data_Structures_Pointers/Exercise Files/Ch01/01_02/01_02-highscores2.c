#include <stdio.h>

int main(void)
{
	float highscore[5] = {993.86,682.01,
	 639.60,310.45,123.25};
	puts("Here are the high scores:");
	for(int x=0;x<5;x++)
		printf("#%d %.2f\n",x+1,highscore[x]);

	return 0;
}

