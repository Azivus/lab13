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
