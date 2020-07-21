/*4) Напишете функция, която получава като параметър текст
и връща броя на срещанията на всяка дума в текста.
*/

/*Get words count*/
unsigned wordsCount(char *string){
        unsigned count=0;
        for ( ; *string; string++)
                if( isLetter(*string) && !isLetter(*(string+1)) ) count++;
        return count;
}

/*Get array of words in string*/
char** getWords(char *string){
        char** wordsArr = alloc_char_array(wordsCount(string), 30);
        if (!wordsArr) goto error11;

        unsigned index0=0u, index1=0u;

        /*

        wordsArr[index0][index1]
        index0 - word in arrayOfWords
        index1 - letter in current word

        */
        for( ;*string; ++string){/* Go through the text string */
                if ( isLetterOrNumber(*string) ) {            /* if it's a space or number */
                        *(*(wordsArr + index0) + index1) = *string;     /* save current letter in dynarray */
                        /* wordsArr[index0][index1] = *string */
                        ++index1;                                       /* go to next letter space in dyn array of current word */
                } else if(index1 != 0) {
                        *(*(wordsArr + index0) + index1) = '\0';
                        /* wordsArr[index0][index1] = term null */
                        ++index0;                                        /* go to next word space in dyn array */
                        index1=0u;
                }
        }

        return wordsArr;

error11:
        return NULL;
}



/* reusing old funcs */

void printWords(char* string){
        typedef struct encounters {
                char* word;
                unsigned count = 0;
        } encounters;

        encounters word1


     /* Fill with zeros */
        for ( ; *string; string++)     /* Iterate through the text */
                encounters[ (unsigned) *string ]++;

        for (size_t i = 0; i < 256; i++)
                if (encounters[i] != 0)
                        printf("'%c' -> %d | ", (char) i, (unsigned) encounters[i]);

        printf("\n\n");
}

int main(int argc, char const *argv[]) {
        /* code */

        char* text = "Gosho e pich glqlq";

        printf("String: %s\n\n", text);
        printLetters(text);

        return 0;
}
