#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	malloc(*size);
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width
	int maxSize=10;
	char (*lines)[COLS]=malloc(maxSize*sizeof(*lines));
	// Read the file line by line into a buffer.
	char buffer[COLS];
	*size=0;

	while(fgets(buffer,COLS,in)){
		buffer[strcspn(buffer,"\n")]='\0';
		if(*size>=maxSize){
			maxSize=2;
			char(*temporary)[COLS]=realloc(lines,maxSize*sizeof(*lines));
			lines=temporary;
		}
	strcpy(lines[*size],buffer);
	(*size)++;

	}
	fclose(in);

    //   Trim newline.

	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	
	// Return pointer to the array.
	return lines;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{

	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
	for(int i=0;i<size;i++){

    	if(strstr(lines[i], target)){
			return lines[i];
		}
	}
	return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{

}

void free2D(char (*arr)[COLS])
{
	free(arr);
}
char * StringSearch2D(char *target, char (*lines)[COLS], int size)
{
    for (int i=0;i<size;i++)
    {
        if (strcmp(lines[i],target)==0)
        {
            return lines[i];
        }
    }
    return NULL;
}
