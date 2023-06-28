## Assignment 5:
In this assignment, I programmed the MyString class, which is an object wrapper of a c-string.

Here is a list of the operations this class supports:

1. A length member function that returns the number of characters in the string.

2. Construction of a MyString from a const c-string.

3. Printing a MyString to a stream using an overloaded << (insertion) operator, which should simply print out its characters.

4. Overloaded square brackets [ ] operator allows direct access to the individual characters of the string. This operation range-checks and asserts if the index is out of bounds. There are two versions of this - one for only read access to the character, and one for modifiable access.

5. All six of the relational operators (<, <=, >, >=, ==, !=) are supported. Operations are based on alphabetical order.

6. Extraction operator: Just like the >> operator that reads C-strings, the class's >> operator skips any leading spaces and then read characters into the string up to the first whitespace character.

7. A read() function that works just like the getline() function works for c-strings; that is, it places everything up to but not including the delimiting character (which is a parameter) into the calling object, and it also consumes (and discards) the delimiting character.

8. Concatenation operator which can handle either a MyString object or a c-string on either side of the operator.

9. += operator that combines both concatenation and assignment.

## Assignment 8 Part 2
Wrote a recursive function named isAPalindrome that takes a single MyString argument and two arguments that are bounds on MyString indices. The function examines the part of the argument between the two bounds (including the bounds) and return true if this part of the argument is a palindrome, false if it is not a palindrome.
