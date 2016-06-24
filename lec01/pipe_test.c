#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
	int p[2];
	pipe(p);
	char buffer[100] = {0};
	int count = 0;

	if (fork() == 0) {
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);	/* must close before read, or read never ends */
		while ((count = read(0, buffer, 100)) > 0) {
			write(1, buffer, count);
		}
		exit(0);
	} else {
		write(p[1], "hello world\n", 12);
		close(p[0]);
		close(p[1]);
	}
	wait(&count);

	return 0;
}
