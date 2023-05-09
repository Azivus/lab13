#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
	char str[1000];
	long int res = 0;
	
	printf("\nАut:Панкеєв Владислав Олексійович\nGr:КН-922Б\nLabnum:13\nТhem:Строки (Null-terminated C Strings)\n\n");
	printf("Створення числа через кількість букв та чисел у строці\n\n");
	
	fgets(str,1000,stdin);
	
	res = CreateConst(str);
	
	printf("Create num:%ld", res);

	return 0;
}

















