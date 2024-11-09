#include <stdio.h>
#include <stdbool.h>

bool checkPalindrome(char *word)
{
	char *startOfWord = word;
	char *finalOfWord = word;
	
	while (*(finalOfWord+1) != '\0') ++finalOfWord;

	while (startOfWord < finalOfWord)
	{
		printf("%d %d\n", *startOfWord, *finalOfWord);

        	if (*startOfWord != *finalOfWord) 
        	{
            		printf("%s is a palindrome\n", word);
            		return false;
        	}

       	 	++startOfWord;
        	--finalOfWord;
    	}
	
	printf("%s is not a palindrome\n", word);
	return true;
}	

int main()
{	
	checkPalindrome("racecar");
	checkPalindrome("hello");

}