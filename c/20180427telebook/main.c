#include "telebook_def.h"
#include <stdio.h>

int main(void)
{
	char fn[50];
	scanf("%s", fn);
	Telebook *head;
	head = Insert(&head, fn);

}