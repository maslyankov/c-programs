#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned isLetter(char string) {
    return ((string < 'Z' && string > 'A') || (string < 'z' && string > 'a'));
}

unsigned wordsCount(char* string) {
    unsigned count = 0;
    for (; *string; string++)
        if (isLetter(*string) && !isLetter(*(string + 1))) count++;
    return count;
}

unsigned isLetterOrNumber(char string) {
    return ((string < 'Z' && string > 'A') || (string < 'z' && string > 'a') || (string < '9' && string > '0'));
}

char** alloc_char_array(unsigned rows, unsigned cols) {
    char** rp = NULL;
    unsigned j, k;

    rp = (char**)malloc(rows * sizeof(char*));
    if (!rp) goto bad0;

    for (j = 0; j < rows; j++) {
        rp[j] = (char*)malloc(cols * sizeof(char));
        if (!rp[j]) goto bad1;
    }

    return rp;

bad1:
    for (k = 0; k < j; k++)
        free(rp[k]);
    free(rp);
bad0:
    return NULL;
}

void dealloc_char_array(char** rp, unsigned /* smenqm tipa*/ rows) { /*TUK, AKO ISKASH ROWS DA TI E CHAR, TO I 'J' trqbva da e ot syshtiq tip*/
    unsigned j;

    for (j = 0; j < rows; j++)
        free(rp[j]);

    free(rp);

    return;
}


char** getWords(char* string) {
    char** wordsArr = alloc_char_array(wordsCount(string), 30);

    if (!wordsArr)
    {
        return NULL;
    }

    unsigned index0 = 0u, index1 = 0u;

    /*

    wordsArr[index0][index1]
    index0 - word in arrayOfWords
    index1 - letter in current word

    */
    printf("%s\n", "Before for loop");

   // unsigned index0 = 0u, index1 = 0u;


    for (;*string; *string++)/*Kakvo pravi <++string> ?*/ {

       // printf("%c\n", *string);

        if (isLetterOrNumber(*string)) {

            *(*(wordsArr + index0) + index1) = *string;
            //wordsArr[index0][index1] = *string;

            ++index1;
            //printf(" %s\n", "First if");
        }
        else {

            *(*(wordsArr + index0) + index1) = '\0';
            printf("%s" " ", wordsArr[index0]);
            ++index0;
            index1 = 0u;
        }
       // printf("%s\n", "After ifs");
    }
  //  printf("%s\n", "After loop");
    return wordsArr;

//error:
//   return NULL;
}

/*1.) Zashto ne pishesh int main(){..return}?*/
int main(void) {
    /* Task 8 */

   char myString[] = "Gosho e pich pich1 !";

    char** wordsArray = getWords(myString);

    dealloc_char_array(wordsArray, 30);

    return 0;
}
