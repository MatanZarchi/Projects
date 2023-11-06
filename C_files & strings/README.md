# Projects
# 5 questions

# Question 1
Write a function called split. The function will receive a lowercase letter and a string str containing several words (a word is a sequence of non-space characters separated from other words by one or more spaces).
The function must produce a dynamic array of dynamic strings so that each string is a word that appears in str and starts with a letter or the capital letter corresponding to the letter (the string that will be in position 0 in the array of strings will be the first word, the string that will be in position 1 in the array of strings will be the second word, etc., according to the order of their appearance in str).
For example, for Rony Goodman got a good mark""str= and letter='g' the function will create an array with the following three strings:

Goodman

got

good


# Question 2
Write a function called clearDigitsAndSpaces that accepts a string and creates a new string. The new string will be the same as the original string but will not include digits and spaces. 
Examples:
For a function call like this:
char *newString = clearDigitsAndSpaces("abcd2 34fty 78 jurt#");
The function will return the following string:   abcdftyjurt#

# Qustion 3:
Section A:
Writing a function called createFile that accepts a string containing the name of a text file.
The function creating a file with this name and writing into the file a sequence of characters received from the keyboard

Section B:
Completing the body of the following function so that it reads a text file whose name is included in the filename string, and returns the most frequent letter in the file (the letter that appears in the file the most times) among the letters 'A' through 'Z'
The function must return the common letter in uppercase format.
If several letters with the same maximum frequency are found, the function must return the largest letter according to the lexicographic order, i.e. the letter closest to the end of the alphabet. If there are no letters in the file received as a parameter, the function will return a null character ('\0').
Example: for a file with the content

d=AB+C-a/(b+c+a+bc)

D=2-a-b

c=6+d

The function will return 'C' (each of the letters 'A', 'B' and 'C' appear 4 times but the ASCII code of 'C' is greater than the ASCII codes of 'A' and 'B').


# Question 4
Writing a decoding function called decode that accepts a string that contains an encrypted text consisting of several words.
The function must decode the text according to the following method:
In each word, 1 must be subtracted from the ASCII value of the first character, 2 must be subtracted from the ASCII value of the second character, etc. The profits must be left in place.
For example, the string "bc8 d" will be replaced by "aa5 c".


# Question 5
Writing a function named memoryReport that accepts the two strings: declaration and filename.
The declaration string will implement a simple line of declarations of variables in the C language.
The function must calculate the amount of memory to be allocated for each variable from declaration and save the results in a text file for recording a report whose name is the content of the filename string.
For example, the following run demonstrates the function's output to a file (in red) for two possible declaration strings (the program's input lines):
int x, y;

x requires 4 bytes
y requires 4 bytes

char c, *cptr, carray[80];

c requires 1 byte
cptr requires 4 bytes
carriage requires 80 bytes



