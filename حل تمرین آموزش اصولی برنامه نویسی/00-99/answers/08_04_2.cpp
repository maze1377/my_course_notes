// C program to find minimum number of appends
// needed to make a string Palindrome
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// Checking if the string is palindrome or not
bool isPalindrome(char *str)
{
	int len = strlen(str);

	// single character is always palindrome
	if (len == 1)
		return true;

	// pointing to first character
	char *ptr1 = str;

	// pointing to last character
	char *ptr2 = str+len-1;

	while (ptr2 > ptr1)
	{
		if (*ptr1 != *ptr2)
			return false;
		ptr1++;
		ptr2--;
	}

	return true;
}

// Recursive function to count number of appends
int noOfAppends(char s[])
{
	if (isPalindrome(s))
		return 0;

	// Removing first character of string by
	// incrementing base address pointer.
	s++;

	return 1 + noOfAppends(s);
}

// Driver program to test above functions
int main()
{
	// char s[] = "abcdcb";
    char str[100];
    scanf("%s",str);
	printf("%d\n", noOfAppends(str));
	return 0;
}
