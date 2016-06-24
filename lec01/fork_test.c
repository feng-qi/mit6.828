#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int pid;

	pid = fork();
	if (pid > 0) {
		printf("parent: child = %d\n", pid);
		pid = wait();
		printf("child %d is done\n", pid);
	} else if (pid == 0) {
		printf("child: exiting\n");
		exit(1);
	} else {
		printf("fork error\n");
	}

	return 0;
}
