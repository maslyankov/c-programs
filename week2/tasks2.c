#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*1) Напишете програма, която намира разликата на двете най-големи числа в масив.*/
/*
int difference(unsigned array[]){
  unsigned biggest=array[0], second=array[1];
  if (biggest<second) {
    biggest = array[1];
    second = array[0];
  }

  for (size_t i = 2; i < 11; i++) {
    if(biggest<array[i]) biggest = array[i];
  }
  printf("biggest: %u\nsecond: %u \n", biggest, second);
  return biggest - second;
}  not working*/

/*2) Напишете програма, която прочита от клавиатурата число N и след него N на брой цели числа. Нека програмата ги запазва в дима
ничен масив.*/

/*3) Напишете функция, която получава масив като аргумент и свъща средноаритметичното на всички стойности в масива.*/

unsigned averageOfArray(unsigned array[], size_t count){
        unsigned sum=0;
        for (size_t i = 0; i < count; i++) {
                sum=+array[i];
        }
        return sum/count;
}

/*4) Напишете функция, която приема параметър стринг и връща броя на буквите в него(без да прави разлика между главни и малки).*/

unsigned isLetter(char string){
        return ((string <= 'Z' && string >= 'A') || (string <= 'z' && string >= 'a'));
}

unsigned lettersCount(char *string){
        unsigned count=0;
        for ( ; *string; string++)
                if(isLetter(*string)) ++count;/* (65) A - (90) Z, (97) a - (122) z*/
        return count;
}

/* 5) Напишете функция, която приема параметър стринг и връща броя на думите в него. */

unsigned wordsCount(char *string){
        unsigned count=0;
        for ( ; *string; string++)
                if( isLetter(*string) && !isLetter(*(string+1)) ) count++;
        return count;
}

/* 6) Напишете функция, която приема текст и дума и връща индекса на първото срещане на думата в текста или -1 ако думата не се съдържа в текста. Забранено е използването функциите от string.h(с изключение на strlen).*/

int findWord(char *string, char *word){
        char *word1=word;
        unsigned index;

        for (index=0; *string; string++, index++)
                if ((*string == *word1) && *string) {
                        /*printf("index: %d\n%c =?= %c\n", index, *string , *word1); */ /*Debugging*/
                        if (!( *(word1+1) )) return index - strlen(word);
                        ++word1;
                } else {word1=word;}
        return -1;
}

/*7) Напишете функция, която приема параметър текст и дума и връща индекса на последното срещане на думата в текста или -1 ако думата не се съдържа в текста. Забранено е използването функциите от string.h(с изключение на strlen).*/

int findWordLast(char *string, char *word){
        char *word1=word;
        unsigned index;
        unsigned lastIndex=0;

        for (index=0; *string; string++, index++)
                if ((*string == *word1) && *string) {
                        /*printf("index: %d\n%c =?= %c\n", index, *string , *word1); */ /*Debugging*/
                        if (!( *(word1+1) )) {
                                lastIndex = index - strlen(word);
                                word1=word;
                        }
                        ++word1;
                } else {word1 = word;}
        if (lastIndex) return lastIndex; else return -1;
}

/*8) Напишете функция, която приема параметър тескт и връща масив,
елементите на който са съответно думите от текста(всяка от тях терминирана, разбира се).*/

unsigned isLetterOrNumber(char string){
        return ((string >= 'A' && string <= 'Z') ||
                (string >= 'a' && string <= 'z') ||
                (string >= '0' && string <= '9'));
}

char **alloc_char_array(unsigned rows, unsigned cols) {
        char **rp = NULL;
        unsigned j, k;

        rp = (char **)malloc(rows * sizeof (char *));
        if (!rp) goto bad0;

        for (j = 0; j < rows; j++) {
                rp[j] = (char *)malloc(cols * sizeof (char));
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

void dealloc_char_array(char **rp, unsigned rows) {
        unsigned j;

        for (j = 0; j < rows; j++)
                free(rp[j]);

        free(rp);

        return;
}


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

/*9) Напишете функция, която приема текст и речник (масив от символи) и замества всеки символ в текста със съответстващият на него символ в речника, ако той съществува в речника (приемаме, че ако за съответния символ стойността е отрицателно число, той не съществува в речника). (Подсказка: речника е с 256 елемента, всеки от които е число между 0 и 256 за съществуващите в него символи и отрицателно число за несъществуващите). */

char* replaceFromDict(char* string, char** dict){

}

/*10) Напишете функция, която получава параметър цяло число и връща дължината на най-дългата непрекъсната последователност от вдигнати битове в двоичното представяне на числото. */

/*11) Напишете функция, която получава параметър текст и връща дължината на най-дългата дума в текста. */


/*12) Напишете функция, която получава параметър текст и връща произведението на всички числа в текста. ВНИМАНИЕ! търси се ПРОИЗВЕДЕНИЕ на ЧИСЛАТА в текста, не на цифрите! */



/*13) Напишете функция, която получава параметър текст и дума и връща броя на срещанията на думата в текста или -1, ако тя не се среща в текста.*/
/* use strstr() */


/*14*) Идеално число ще наричаме цяло число, в двойчния запис на което няма две поредни единици. Напишете функция, която по дадено цяло число връща най-малкото идеално число, по-голямо или равно на даденото.*/
unsigned getBitAt(unsigned number,unsigned index){
  return !!(number & (1 << index));
}

int idealNumber(int inputNum){
        for (size_t i = 0; i < 1; i++) {
                if(false){

                }
        }
}

/*15) Напишете функция, която по даден текст връща нов текст, получен от символите на нечетни позиции в оригиналния текст.
    Пример:
        Вход: "This is a sample text 1234."
        Изход: "Ti sasml et13."*/


/* 16*) Напишете функция, която приема текст и речник(масив от думи) и връща броя на думите от текста, които се съдържат в речника.*/

unsigned wordCountFromDict(char* text, char** dict){
        unsigned count=0;
        char *word, *delims =" .\n";

        word = strtok(text, delims);
        while (word) {
                int dictIndex = 0;
                while (dict[dictIndex]) {
                        printf("%s is: %s ?= %s %d\n", "test", word, dict[dictIndex], strcmp(word, dict[dictIndex]) ); // Debugging
                        if ( !strcmp(word, dict[dictIndex]) ) {
                                ++count;
                                printf("%s %d\n", "Count is ", count);
                                break;
                        }
                        ++dictIndex;
                        printf("%s is: %s ?= %s %d\n", "test", word, dict[dictIndex], strcmp(word, dict[dictIndex]) ); // Debugging

                }
                word=strtok(NULL, delims);
                printf("%s\n", "after loop");
        }

        printf("%s\nCount is %d\n", "after loop2", count);
        return count;
}


void freeDict(char ** dict){
        int i = 0;
        while (**dict) {
                free(*dict);
                ++dict;
        }
}
/*17*) Напишете функция, която по даден текст намира най-дългата огледална дума в него(огледална наричаме дума, която се чете по еднакъв начин отляво и отдясно).
    Пример за огледална дума: "rotavator"

18) Напишете функция, която приема число в Big endian нотация и връща съответващото му число в Little endian нотация.

19*) Напишете функция, която без да използва никакви сравнения проверява дали едно число е положително или отрицателно(приемаме 0 за положително число). Забранени са всички оператори за сравнение! Разрешени са само аритметичните оператори и побитовите.*/


int main(int argc, char *argv[]) {
        /* Task 1 */
        printf("\n%s\n", "*** \t Task 1 \t ***");

        unsigned arr[11]={999, 10, 13, 98, 113, 170, 187, 26, 29, 51, 92};

        /* Task 4 & 5 */
        printf("\n%s\n", "*** \t Tasks 4,5 \t ***");

        char *myString = "Gosho e pich pich1 !";

        printf("String: %s \n letters count: %d\n letters and numbers count: %d\n words count: %d\n", myString,lettersCount(myString),lettersCount(myString), wordsCount(myString));

        printf("Is A letter or num? - %d\n", isLetterOrNumber('A'));

        printf("Is @ letter? - %d\n", isLetterOrNumber('@'));

        /* Task 6 & 7 */
        printf("\n%s\n", "*** \t Tasks 6,7 \t ***");

        printf("word pich is in place %d\n", findWord(myString, "pich"));

        printf("word pich is last seen in place %d\n", findWordLast(myString, "pich") );

        /* Task 8 */

        printf("\n%s\n", "*** \t Task 8 \t ***");


        char** wordsArray = getWords(myString);
        unsigned wCount = wordsCount(*wordsArray);

        printf("row 0 : %s\nrow 1: %s\n\n\n", wordsArray[0], wordsArray[1]);


        dealloc_char_array(wordsArray, wCount); /* not to forget to free allocated dynamic memory!!!*/

        /* Task 9 */
        printf("\n%s\n", "*** \t Task 9 \t ***");

        /* Task 14 */
        printf("\n%s\n", "*** \t Task 14 \t ***");


        /* Task 16 */
/*        printf("\n%s\n", "*** \t Task 16 \t ***");

        int i = 0;
        char dict[6][30]={"this", "is", "sample", "text", "lqlq"};

        char *dynamicDict[5];
        dynamicDict[0]=strdup("this");
        dynamicDict[1]=strdup("is");
        dynamicDict[2]=strdup("sample");
        dynamicDict[3]=strdup("text");
        dynamicDict[4]=strdup("lqlq");
        dynamicDict[5]='\0';


        char *text=strdup("This is sample text dasadsads!\n");

        printf("Word count from dict: %d", wordCountFromDict(text, dynamicDict));

        freeDict(dynamicDict);
        free(text);*/

        return 0;

error:
        return 1;
}
