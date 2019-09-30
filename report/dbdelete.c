#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"
/*학번을 입력받아 해당 레코드를 삭제한다.*/
int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct student record;
	if (argc < 2){
		fprintf(stderr,"사용법 : %s file\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("삭제할 학생의 학번 입력: ");
		if (scanf("%d",&id)==1){
			lseek(fd,(long)(id - START_ID*sizeof(record)), SEEK_SET);
			if((read(fd, (char*)&record, sizeof(record)) > 0) && (record.id != 0)){
				record.id = '\0';
				record.score = '\0';
				*record.name = '\0';
				lseek(fd, (long)-sizeof(record), SEEK_CUR);
				write(fd, (char*)&record,sizeof(record));
			}
			else printf ("레코드 %d 없음 \n", id);
		}
		else printf("입력 오류\n");
		printf("계쏙하시겠습니까?(Y/N)");
		scanf("%c",&c);
	}
	while(c == 'y');
	close(fd);
	exit(0);
}

