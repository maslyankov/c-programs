#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*1) Напишете програма, която получава като параметър от командния ред име на
текстов файл и отпечатва в конзолата текста от файла по една дума на ред.*/

void removeTermNull(char* string){
        unsigned pos, i;
        for (i=0; *string; string++, ++i) pos = i+1;

        printf("before: %s\n", string);


        printf("Position of null term: %d\n", pos);

        *(string+pos+1)='';
}

void printWordsLineByLineFromFile(char* fileName){
        printf("Reading from: %s\t---\n", fileName);

        int fd;
        ssize_t num;

        char buf[64];

        removeTermNull(fileName);

        fd = open(fileName, O_CREAT | O_TRUNC | O_RDWR);
        if (fd < 0) {
                perror("open");

        } else printf("fd %d\n", fd);

        num = read(fd, buf, sizeof (buf));
        if (num < 0) perror("read");
        else printf("read %ld\n", num);


}

int main(int argc, char const *argv[]) {
        char file_name[200];
        printf("%s\n", "Input filename:");
        fgets(file_name, 200, stdin);

        printWordsLineByLineFromFile(file_name);



        return 0;
}
