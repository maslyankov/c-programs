#include <stdio.h>
#include <math.h>
#include <string.h>

/* 1) Напишете функция getBitAt, която получава като параметър число и индекс, и връща стойността на бит-а на съответния индекс в двоичния запис на числото.
*/

unsigned getBitAt(unsigned number,unsigned index){
  return !!(number & (1 << index));
}

/* 2) Напишете функция clearBitAt, която получава като параметър число и индекс, и занулява бит-а на съответния индекс в числото.
*/

unsigned clearBitAt(unsigned number,unsigned index){
  return number & ~(1 << index);
}

/* 3) Напишете функция raiseBitAt, която получава като параметър число и индекс, и "вдига" бит-а на съответния индекс в числото(под "вдига" ще разбираме да му присвои стойност 1).
*/

unsigned raiseBitAt(unsigned number,unsigned index){
  return number | (1 << index);
}

/* 4) Напишете функция flipBitAt, която получава като параметър число и индекс, и обръща бит-а на съответната пизиция в числото(съответно от 0 на 1 или от 1 на 0).
*/

unsigned flipBitAt(unsigned number,unsigned index){
  return number ^ (1 << index);
}

/* 5) Напишете функция setBitAt, която получава като параметри число, индекс и стойност. Функцията ви трябва да присвоява на бит-а на съответния индекс стойността, подадена като параметър. Как ще интерпретирате стойности, различни от 0 и 1, остава ваше решение. Забранено е използването на вече написаните функции.
*/

unsigned setBitAt(unsigned number,unsigned index, unsigned bit){
  unsigned nWithClearedBit = number & (~(1 << index));
  bit = !!bit;
  return nWithClearedBit | (bit << index);
}

/* 6) Напишете функция removeOdd, която получава като параметър число, и занулява всички бит-ове на нечетни позиции в числото. Позициите на битовете броим от младши към старши, започвайки от 0. Всички останали бит-ове(на четни позиции) трябва да бъдат запазени.
*/

unsigned removeOdd(unsigned number){
  unsigned mask = 0x55555555;
  return number & ~mask;
}

/* 7) Напишете функция, която получава като параметър число, и връща позицията на най-старшия вдигнат бит(под вдигнат бит ще разбираме такъв със стойност 1).
*/

unsigned getHighMSB(unsigned number){
  return 1;
}

/* 8) Напишете функция, която получава като параметър число и два индекса k и n и връща числото със занулени битове между позиция k и n.
*/
unsigned setBitsLow(unsigned number, unsigned k, unsigned n){ /* K < N */
  if(k>n) { /* If input is wrong k>n (lower is bigger than upper limit, we swap them) */
    printf("Auto correcting index numbers!\n");
    unsigned temp = n;
    n = k;
    k = temp;
  }
  unsigned mask=1;
  for (unsigned i = 1; i < n-k; i++) {
    /* code */
    mask=mask*2+1;
  }
  mask<<=k;

  return number & ~mask;
}


/* 9) Напишете функция, която получава като параметър число и индекс k и връща числото, което се получава от оригиналното число с премахнати всички битове след k-тия включително.
*/

unsigned removeBits(unsigned number, unsigned k){
  return number>>k;
}

/* 10) Напишете функция, която полуава едно число и отпечатва в конзолата побитовото му представяне.
*/

void printBinary(unsigned number){
  unsigned j,remove=0;
  for (int i = 31; i >= 0; i--){ /* Calculate how many of the bits on the left we do not need */
    j = number >> i;
    if (j & 1) break; else remove++;

  }

  for (int i = 31 - remove; i >= 0; i--){ /* Cycle through meaningful bits only */
    j = number >> i;
    (j & 1) ? printf("1") : printf("0");  /* print to console bit by bit */
  }
  printf("\n");
}

/* 11) Напишете функция, която получава едно число и отпечатва в конзолата шентнайсетичното му представяне.

unsigned j,bit,quatro;
for (int i = 0; i < 32; i+=4){
  printf("%d\n", quatro);
  quatro=0;
  for (unsigned k = 0; k < 4; k++) {
    j = number << i+k;
    bit= (j & 1) ? 1 : 0;
    quatro+=bit^k;
  }
}
*/
/*Not working properly, not printing numbers in hex */

void printHexEasy(unsigned number){
  printf("Hex of %d is %x\n", number, number);
}

void printHex(unsigned number){
  unsigned reminder;
  unsigned mask = 0;
  printf("0x");

  while (number) {
    mask |= (number & 0xF);
    mask <<= 4;

    number >>= 4;

  }
  mask >>= 4;

  while (number) {
    reminder = number%16;
    number /= 16;

    if (reminder < 10)
      printf("%d\n", reminder);
    else
      printf("%c\n", 'A' + reminder-10);
  }
  printf("\n");
}

/* 12) Напишете функция, която приема едно число и база (<= 10) и връща числото, преобразувано в бройна система със съответната база. Пример: number=25(десетична), base=7, result=34(7-мична бройна система) */
void changeBase(int number, unsigned base){
  int originNumber = number;
  char base_digits[16] =
  	 {'0', '1', '2', '3', '4', '5', '6', '7',
  	  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  int output[64];
  int next_digit, index=0;

  /* Convert to base */
  while (number != 0) {
  	 output[index] = number % base;
  	 number /= base;
  	 index++;
  }


  index--;  /* back up to last entry in the array */
  printf("\n\n%d[10] in base %d is: ", originNumber, base );
  for(  ; index >= 0 ; index--) { /* go backward through array */
    printf("%c", base_digits[output[index]]);
  }
  printf("\n");
}


/*13) Напишете функция, която получава като параметър число и връща на стандартния изход разбиването на числото като сума от степени на двойката.*/

void getDivisionsOfTwo(unsigned number){
    unsigned mask = 1;
    for (size_t i = 0; i < count; i++) {
      printf("%s + ", ((number | mask) * 2 ^ i) );
      mask <<= 1;
    }
}

/*14) Напишете функция, която получава като параметър число k и връща маска, която има вдигнати всички битове на позиции, кратни на k.*/

unsigned createMask(unsigned k){
  unsigned mask=1u;

  for (size_t i = 1; i < sizeof(mask)*8/k; i++) {
    mask |= (mask << k*i);
  }

  return mask;
}

/*15) Напишете функция, която получава като параметър число. Неговите битове ще третираме така - първите 5 бита(най-младшите) представляват едно число(5 bit-ово), следващите 5 - друго число и тн. Изведете на стандартния изход числата, "закодирани" в оригиналното число.*/



/*16) Параметизирайте горната задача, т.е. вместо 5, използвайте параметър k.*/



/*17) Напишете програма, която получава като параметър две числа. Приемаме, че в тях е закодиран текст, като най-старшите 8 бита на първото число са първата буква, следващите 8 са втората и тн. с двете числа. Изведете на стандартния изход текста, закодиран в двете числа. Тествайте програмата си.(Примери за тестване: 0x54455354, 0x31323334)*/



/*18*) Напишете функция, която получава като параметър две числа, и връща като резултат броя позициите в бит-овото представяне на числата, на които двете числа имат различни стойности. Водещите нули да се игнорират(тоест броенето да започне от най-старшия вдигнат бит на по-голямото число).
Пример:
Вход: 15 9
Изход: 2
Обяснение: 15 -> 1111, 9 -> 1001, двете числа имат различни бит-ове на позиции 1 и 2.*/



/*19) Имплементирайте масив за съхранение на 7-битови неотрицателни числа. Използвайте масив от 7 елемента тип unsigned(unsigned data[7]). Имплементирайте следните функционалности:
    - add(unsigned data[7], unsigned number, unsigned index) - добавя 7-битовото число number в масива data на позиция index(между 0 и 31, тъй като числата са 32*7бита, точно колкото е unsigned[7])
    - get(unsigned data[7], unsigned index) - връща 7-битовото число на съответния индекс
    - sum - връща сумата на числата от масива
    - remove - премахва число от масива. Премахването става, като на мястото на числото се записват нули.*/
/*
use bitwise shifting
*/




/*20) Добавете поддръжка на отрицателни числа към вече написаните функционалности (na 19-ta). Използвайте 2-комплементата(2s complement).*/

/*21) Имплементирайте наново функция, която връща позицията на най-старшия бит в числото, използвайки двоично търсене(binary search). Анализирайте разликата в скоростта на изпълнение на двете функции.*/




int main(int argc, char const *argv[]) {
  printf("Hello %s\n\n", "world!");
  /* code */

  printf("Bit at 2 for 5 is %d\n\n", getBitAt(5,2));

  printf("Number is %d\nClear bit returns ", 5);

  printf("\n\nReady number is: %d\n\n", setBitAt(111, 4, 1));


  printf("1023 in binary is \n\n");

  printBinary(1023);

  printf("with lowered bits between 2 and 4: %d\n printBinary(setBitsLow(...)): \n",setBitsLow(1023,2,4));

  printBinary(setBitsLow(1023,2,4));

  printf("dsaasdasd\n");

  printf("printHex(): \n");
  printHex(256);

  printf("printHex(1023): ");
  printHex(1023);


  printf("\n\nNew Hex func: ");
  changeBase(1023, 16);

  printBinary(createMask(5));

  return 0;
}
