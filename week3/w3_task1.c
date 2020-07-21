#include <stdio.h>
#include <string.h>

/*1) Напишете функция, която получава тект и отпечатва в конзолата броя на срещанията на всяка буква в текста.
    Пример:
        Вход: "Sample text"
        Изход: S -> 1
               a -> 1
               m -> 1
               p -> 1
               l -> 1
               e -> 2
               t -> 2
               x -> 1*/

void printLetters(char* string){
        unsigned encounters[256];

        memset(encounters, 0u, sizeof(encounters));     /* Fill with zeros */
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
