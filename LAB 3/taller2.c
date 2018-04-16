#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int fd;
	pid_t pid;
	int num;
	if ((pid = fork()) < 0) {
		perror("fork falló");
		exit(-1);
	} else if (pid == 0) {
		for (num=0; num<20; num++) {
			printf("hijo: %d\n", num);
                        sleep(1);
		}
	} else {
		for (num=0; num<20; num+=3) {
			printf("padre: %d\n", num);
                        sleep(1);
		}
	}
}
