#include <stdio.h>
#include "Hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{
	int input;
	HashTable h = newHashTable(7);
	scanf("%d", &input);
	printf("Displaying an empty hash table\n");
	display(h);
	add(h, 12);
	add(h, 54);
	add(h, 34);
	add(h, 70);
	add(h, 98);
	add(h, 41);
	add(h, 7);
	add(h, 16);
	add(h, 34);
	add(h, 78);
	add(h, 123);
	add(h, 21);
	add(h, 10);
	add(h, 17);
	printf("Displaying the hash table\n");
	display(h);
	printf("Removing 17 and 123\n");
	removeH(h, 17);
	removeH(h, 123);
	printf("Displaying the hash table\n");
	display(h);
	printf("contains(h,17) = %d\n", contains(h, 17));
	printf("contains(h,98) = %d\n", contains(h, 98));
	printf("Clearing hash table\n");
	clear(h);
	printf("Displaying the hash table\n");
	display(h);
	destroy(&h);
	return 0;
}