In this assignment, I programmed several functions dealing with c-strings.

1. This function finds the last index where the target char can be found in the string. it returns -1 if the target char does not appear in the string. The function should be case sensitive (so 'b' is not a match for 'B').

int lastIndexOf(const char* inString, char target)

2. This function alters any string that is passed in. It should reverse the string. If "flower" gets passed in it should be reversed in place to "rewolf". For efficiency, this must be done "in place", i.e., without creating a second array.

void reverse(char* inString)


3. This function finds all instances of the char 'target' in the string and replace them with 'replacementChar'. It returns the number of replacements that it makes. If the target char does not appear in the string it should return 0.

int replace(char* inString, char target, char replacementChar)


4. This function returns true if the argument string is a palindrome. It returns false if it is not. A palindrome is a string that is spelled the same as its reverse. For example "abba" is a palindrome. So are "hannah" and "abc cba" and "b" and "n$aa$n" and "" (empty string).

Do not get confused by white space characters, punctuation, or digits. They should not get any special treatment. "abc ba" is not a palindrome. It is not identical to its reverse. (Note, this may be different from other definitions of palindrome. The reason for choosing this definition is actually to make the function easier: you can just write the code without ever thinking about whether the characters are letters or not. If you had to skip over spaces and other non-letters, the code would be more complex.)

Your function should not be case sensitive. For example, "aBbA" is a palindrome.
You must solve this problem "in place", i.e., without creating a second array. As a result, calling your reverse() function from this function isn't going to help.
bool isPalindrome(const char* inString)


5. This function converts the c-string parameter to all uppercase.
void toupper(char* inString)


6. This function returns the number of letters in the c-string.
int numLetters(const char* inString)
