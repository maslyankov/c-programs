#include <stdio.h>
#include <string.h>
/*2) Напишете програма, която получава като параметри два стринга и връща първата позиция, на която двата стринга се различават един от друг. Ако двата стринга са еднакви, програмата да не връща нищо.
*/

unsigned compareStrings(char* string0, char* string1){
        unsigned index;
        for (index=0 ; *string0; string0++, string1++, index++)
                if(*string0 != *string1) return index;
}

int main(int argc, char const *argv[]) {
        /* code */

        char* gosho1 = "Gosho";
        char* gosho2 = "Gosho";
        char* pesho1 = "GosPesh";

        printf("First attempt: %d \n",compareStrings(gosho1, gosho2));

        printf("Second attempt: %d \n",compareStrings(gosho1, pesho1));

        return 0;
}
