#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
/*	int file = open("t1.sh", O_RDWR);
	char buffer[1000] = {1};

	while (read(file, buffer, 999) > 0) {
		printf("%s\n", buffer);
	}

	lseek(file, 9, SEEK_SET);
	if (write(file, "WRITE_WRITE", 11) != 11) {
		write(2, "ERROR occurred!\n", 17);
	}

	lseek(file, 0, SEEK_SET);
	while (read(file, buffer, 999) > 0) {
		printf("%s\n", buffer);
	}

	close(file);
------------------------------

	char *args[2];
	int status = 0;

	args[0] = "cat";
	args[1] = 0;
	if (fork() == 0) {
		close(0);
		open("t.sh", O_RDONLY);
		execv("/bin/cat", args);
	}
	wait(&status);
	printf("status: %d\n", status);
------------------------------
	*/

	int fd = dup(1);
	write(1, "hello ", 6);
	write(fd, "world\n", 6);

	return 0;
}
