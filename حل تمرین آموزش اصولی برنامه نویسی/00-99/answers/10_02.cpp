#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_alphabet(char c){
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char clean_str(char str[]){
	int str_len = strlen(str);
	char tmp = '\0';
	if(!is_alphabet(str[str_len-1])){
		tmp = str[str_len-1];
		str[str_len-1] = '\0';
	}
	return tmp;
}

// Function to find and
// replace a word in File
void find_and_replace_in_file()
{
	FILE *inputfp, *outputfp;
	char word[100], ch, read[100], replace[100];
	int word_len, i, p = 0;

	inputfp = fopen("input.txt", "r");
	outputfp = fopen("output.txt", "w");
	if (inputfp == NULL || outputfp == NULL) {
		printf("Can't open file.");
		exit(0);
	}
	
	fgets(word, 100, inputfp);

	// removes the newline character from the string
	word[strlen(word) - 1] = word[strlen(word)];

	fgets(replace, 100, inputfp);
	
	// removes the newline character from the string
	replace[strlen(replace) - 1] = replace[strlen(replace)];

	// removes '-' from the start of the string.
	for(int i=1;i<=strlen(word);i++){
		word[i-1] = word[i];
	}

	for(int i=1;i<=strlen(replace);i++){
		replace[i-1] = replace[i];
	}

	// comparing word with file
	while (!feof(inputfp)) {
		int newline_sw = 0;

		fscanf(inputfp, "%s", read);
		if(fgetc(inputfp)=='\n'){
			newline_sw = 1;
		}
		char tmp = clean_str(read);
		if (strcmp(read, word) == 0) {

			// for deleting the word
			strcpy(read, replace);
			int len = strlen(read);
			read[len] = tmp;
			read[len+1] = 0;
		}

		// In last loop it runs twice
		fprintf(outputfp, "%s ", read);
		if(newline_sw){
			fprintf(outputfp, "\n");
		}
	}

	fclose(inputfp);
	fclose(outputfp);
}

// Driver code
int main()
{
	find_and_replace_in_file();

	return 0;
}