#include <stdio.h>
int main()
{
	char A[] = "fkindingkk";
	int b = 0;
	for(int i = 0; A[i] != '\0'; i++){
		int x = 1;
		x = x << (A[i] - 97);
		if((b & x) > 0){
			printf("%c is duplicate \n",A[i]);
		}
		else{
			b = b | x;
		}
	}
	return 0;
}