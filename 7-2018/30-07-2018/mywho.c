#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

void show_info(struct utmp *message_save);

int main()
{
	struct utmp message_save;
	int fd_utmp;
	int message_save_len = sizeof(message_save);

	if((fd_utmp = open(UTMP_FILE, O_RDONLY)) < 0)
	{
		perror(UTMP_FILE);
		exit(1);
	}

	while(read(fd_utmp, &message_save, message_save_len) == message_save_len)
		show_info(&message_save);

	close(fd_utmp);
	return 0;
}

void show_info(struct utmp *message_save)
{
	if(message_save->ut_type != USER_PROCESS)
		return ;
	printf("%-8.8s", message_save->ut_name);
	printf("\t");
	printf("%-8.8s", message_save->ut_line);
	printf("\t");
	printf("%12.12s", ctime(&message_save->ut_time) + 4);
	printf("\t");
#ifdef SHOWHOST
	printf("(%s)", message_save->ut_host);
#endif
	putchar('\n');
}
