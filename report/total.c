#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>
#define BUF 512

int main(int argc, char *argv[])
{
	FILE * fd;
	char str[] = {};
	char ch;
	int i = 0;
	int number = 0;
	
	if(argc == 1){
		if((fd = fopen("file.txt", "w+")) == NULL){
			perror("file.txt");
			exit(1);
		}
		printf("file contents \n");
		while(fgets(str, BUF, stdin) != NULL){
			fprintf(fd, "%s", str);
		}	
	}
	else if((fd = fopen(argv[1], "rw")) == NULL){
		perror(argv[1]);
		exit(2);
	}
	fseek(fd, 0, SEEK_SET);
	i = 0;
	while(1){
		ch = fgetc(fd);
		if(ch == ' ')number--;
		if(ch == EOF) {
			number--;
			break;
		}
		str[i] = ch;
		i++;
		number++;
	}
	printf("file text : %d\n", number);
	number = 0;
	
	i = 0;
	while(str[i] != '\0'){
		while(isspace(str[i]))
			i++;
		if(str[i] != '\0')number++;
		while(!isspace(str[i]) && str[i] != '\0')i++;
	}
	number--;
	printf("file word : %d\n", number);
	number = 0;
	
	fseek(fd, 0, SEEK_SET);
	i = 0;
	while(1){
		if(str[i] == '\n') number++;
		else if(str[i] == EOF){
		       	break;
		}
		i++;
	}
	printf("file line : %d\n", number);

	fclose(fd);
	exit(0);
}
