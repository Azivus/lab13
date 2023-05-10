# **Лабораторна робота 13.**

# **Панкеєв Владислав Олексійович 922-Б**

# **Завдання**
```
Для запам’ятовування числа Пі іноді використовують наступну російську фразу:
"это я знаю и помню прекрасно Пи многие знаки мне лишни напрасны".
 Число букв у кожному слові – це наступна цифра числа: "это" – 3, "я" – 1, "знаю" – 4 і т. д.
 Розробити програму, яка за зазначеним алгоритмом буде видавати число, використовуючи будь-який текст.
```

## **Основна частина:**

### **Вміст файлу main.c**

```c
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
```
### **Вміст файлу lib.c**
```c
#include <stdio.h>
#include <string.h>

long int CreateConst(char str[])
{	
	int number_letter;
	long int res = 0;
	
	if(*(str) == '\0')
		return 0;
	
	for(int i = 0, j = 0; *(str + i) != '\0';i++)    
	{		
		number_letter = 0;
		
		for(j = 0;*(str + i) != ' '; i++, j++)
		{	
			if( (*(str + i) >= 'a' && 'z' >= *(str + i)) || (*(str + i) >= 'A' && 'Z' >= *(str + i)) || (*(str + i) >= '0' && '9' >= *(str + i)) )
			{
			}
			else if(strncmp(&*(str + i),"А", 2) >= 0 && strncmp(&*(str + i),"я", 2)  <= 0){
			
				number_letter++;
				j++;
				i++;
			}
			else if(strncmp(&*(str + i),"ї", 2) == 0 || strncmp(&*(str + i),"Ї", 2) == 0 || 
				strncmp(&*(str + i),"є", 2) == 0 || strncmp(&*(str + i),"Є", 2) == 0 || 
				strncmp(&*(str + i),"і", 2) == 0 || strncmp(&*(str + i),"І", 2) == 0 || 
				strncmp(&*(str + i),"ґ", 2) == 0 || strncmp(&*(str + i),"Ґ", 2) == 0){
			
				number_letter++;
				j++;
				i++;
			}
			else
				break;									
		}
		number_letter = j - number_letter;
		
		if(number_letter != 0)
		{	
			if(number_letter >= 10)
			{
				res = (res * 100) + number_letter;
			}
			else
				res = (res * 10) + number_letter;
		}
	}
	return res;
}
```
### **Вміст файлу lib.h**
```c
Це файл, який містить декларацію функції CreateConst.

 param a[] - масив у якому зберігається строка яку ввів користувач.

long int CreateConst(char a[]);
```
### **Вміст файлу test.c**
```c
#include "../src/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <math.h>
#define EPSILON 0.000001


START_TEST(test_CreateConst_easysentence)
{	
	char test_str[] = "Я закінчив школу";
	long int expected_res = 185;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_DEquestion)
{	
	char test_str[] = "Was ist das?";
	long int expected_res = 333;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_truesentence)
{	
	char test_str[] = "Шо нам ті кулі, нас ракети не беруть.";
	long int expected_res = 23243626;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_numbersentence)
{	
	char test_str[] = "Мені 18 років";
	long int expected_res = 425;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_nosentence)
{	
	char test_str[] = "\0";
	long int expected_res = 0;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


Suite *lab_test_suite(void)
{
	Suite *s;
	TCase *tc_CreateConst;

	s = suite_create("lab13");

	tc_CreateConst = tcase_create("CreateConst");

	tcase_add_test(tc_CreateConst, ttest_CreateConst_easysentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_DEquestion);
	tcase_add_test(tc_CreateConst, test_CreateConst_truesentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_numbersentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_nosentence);

	suite_add_tcase(s, tc_CreateConst);

	return s;
}


int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;


	s = lab_test_suite();
	sr = srunner_create(s);


	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);


	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
```
### **Структура проекту лабораторної роботи:**
```   
lab13
├── Doxyfile
├── Makefile
├── README.md
├── assets
│   └── text.txt
├── test
│   └── test.c
└── src
    ├── lib.c
    ├── lib.h
    └──	main.c
```

![Program work result](https://github.com/Azivus/lab13/blob/main/photo_2023-05-09_15-38-06.jpg)
