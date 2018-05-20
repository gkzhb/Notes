struct telebook
{
	char num[4];
	char name[10];
	char phonenum[15];
	char email[20];
	struct telebook *next;
};
typedef struct telebook Telebook;