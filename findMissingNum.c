#include <stdio.h>
int findMissingNum(int n, int array[n])
{
    int expectedSum = 0;
    int realSum = 0;
    
    for (int i = 1; i <= n+1; ++i) expectedSum += i;
    for (int i = 0; i < 5; ++i) realSum += array[i];
    
    return expectedSum - realSum;
}


int main(void)
{
	int array1[5] = {1, 2, 4, 5, 6};
	int array2[7] = {3, 7, 1, 2, 8, 4, 5};
	int array3[4] = {1, 2, 3, 5};

	int expectedSum = 0;
	int realSum = 0;

	for (int i = 1; i <= 6; ++i) expectedSum += i;
	for (int i = 0; i < 5; ++i)  realSum += array1[i];
	
	int missingNum = expectedSum - realSum;

    printf("%d\n", missingNum);
    printf("%d\n", findMissingNum(5, array1));
}