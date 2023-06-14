//Stefan Wallin
//School of Computer Science
//swalli2@mimi.cs.mcgill.ca 

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//checking if user entered two command-line arguments
	if (argc != 3) {
		printf("Error: Incorrect number of inputs\n");
		printf("Usage: ./anagram <word1> <word2>\n");

		return 2;
	}
	
	//saving command-line arguments to variables
	char* word1s = argv[1];
	char* word2s = argv[2];

	//if words are not the same length then they are not anagrams
	if (strlen(word1s) != strlen(word2s))
	{
		printf("Not an anagram\n");
		
		return 1;
	}

	char word1a[strlen(word1s) + 1];
       	char word2a[strlen(word2s) + 1];

	//putting characters of strings into arrays
	int i;
	for (i = 0; i <= strlen(word1s) - 1; i++) {
		word1a[i] = word1s[i];
		word2a[i] = word2s[i];
	}

	//adding terminating character to end of array
	word1a[i] = '\0';
	word2a[i] = '\0';
	

	int first[26] = {0}, second[26] = {0}; 
	
	//putting characters of arrays into another array
	//in alphabetical order (sorting arrays)
	i = 0;
	while (word1a[i] != '\0') {
		first[word1a[i] - 'a']++;
		i++;
	}

	i = 0;
        while (word2a[i] != '\0') {
                second[word2a[i] - 'a']++;
                i++;
        }	
	
	//comparing sorted arrays
	for (i = 0; i < 26; i++) {
		if (first[i] != second[i]) {
			printf("Not an anagram\n");

                	return 1;
		}
	}
	
	printf("Anagram\n");

	return 0;
}
