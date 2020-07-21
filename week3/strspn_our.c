#include <string.h>
#include <stdio.h>
/*The  strspn() function calculates the length (in bytes) of the initial segment of s which consists entirely of
       bytes in accept.*/


size_t strspn_our(const char *s, const char *accept){
        char alphabet[255];

        size_t len;

        memset(alphabet, 0, sizeof(alphabet));

        for (len = 0; *(accept + len); len++)
                *(alphabet + (unsigned)*(accept + len)) = 1;

        for (len = 0; *(s+len); len++)
                if (!*(alphabet + (unsigned) *(s + len))) break;

        return len;

}

int main(int argc, char const *argv[]) {
        char *s = "1234asd";

        size_t length;
        int j;

        length = strspn_our(s, "012356789asdfg");

        printf("len %lu\n", length);

        for (j = 0; j < length; j++)
                printf("%c\n", *(s + j));


        return 0;
}
