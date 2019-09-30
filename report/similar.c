#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE * fd1;
	FILE * fd2;
	int flag = 1, number = 0;

	if(argc != 3){
		fprintf(stderr, "use : %s test1, test2\n", argv[0]);
		exit(1);
	}
	if((fd1 = fopen(argv[1], "r")) == NULL){
		perror(argv[1]);
		exit(2);
	}
	if((fd2 = fopen(argv[2], "r")) == NULL){
		perror(argv[2]);
		exit(3);
	}

	while(1){
		number++;
		char c1 = fgetc(fd1);
		char c2 = fgetc(fd2);
		if(c1 != c2){
			printf("%d different\n", number);
			printf("first %d  : %c\n", number, c1);
			printf("second %d : %c\n", number, c2);
			flag = 0;
		}
		if(c1 == EOF || c2 == EOF) break;
	}
	if(flag)
		printf("Same.\n");
	else
		printf("Different.\n");
	fclose(fd1);
	fclose(fd2);
	exit(0);
}
