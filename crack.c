#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

/*char * tryWord(char *plaintext, char **hashes, int size)
{
    // Hash the plaintext
    char *hash = md5(plaintext, strlen(plaintext));

    // Search for the hash in the hash array
    char *found = StringSearch2D(hash, hashes, size);

    free(hash); // Free memory allocated for the hash string

    return found ? strdup(found) : NULL; // Return a copy of the found hash or NULL
}*/
char * tryWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext
    char *hash = md5(plaintext,strlen(plaintext));  // hash plaintext, store in hash

    // Open the hash file
    FILE *hashed = fopen(hashFilename, "r");
     if (hashed==NULL) {
        free(hash);
        return NULL;
    }

    // Loop through the hash file, one line at a time.
     char line[1000];
    while(fgets(line, sizeof(line), hashed) != NULL){
        char *newline=strchr(line, '\n');//Sets a pointer for where the newline haracter is
        if (newline) *newline = '\0';
        if(strcmp(line, hash)==0){
            fclose(hashed);
            return(hash);
        }
    }
    fclose(hashed);
    free(hash);
    return NULL;




    // Attempt to match the hash from the file to the
    // hash of the plaintext.

    // If there is a match, you'll return the hash.
    // If not, return NULL.

    // Before returning, do any needed cleanup:
    //   Close files?
    //   Free memory?

    // Modify this line so it returns the hash
    // that was found, or NULL if not found.
    //return "0123456789abcdef0123456789abcdef";
}

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    char (*hashes)[HASH_LEN] = loadFile2D(argv[1], &size);
    //char **hashes = loadFile(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *pass =fopen(argv[2], "r");
    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.
int hashesCracked = 0;
    char word[PASS_LEN];
    while (fgets(word, sizeof(word), pass)) {
        // Remove newline character from the word
        word[strcspn(word, "\n")]='\0';
        // Hash the password and use binary search to find the hash
        char *hash=md5(word, strlen(word));
        char *found=StringSearch2D(hash, hashes, size);
        free(hash);

        if (found) {
            hashesCracked++;
            printf("%s %s\n",found,word);
        }
    }
    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
    fclose(pass);
    printf("%d hashes cracked\n", hashesCracked);
    free2D(hashes);
}


