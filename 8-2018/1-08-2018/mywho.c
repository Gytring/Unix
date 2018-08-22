#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define NRECS 16
#define NULLUT ((struct utmp *)NULL)
#define UTSIZE (sizeof(struct utmp))
#define SHOWHOST

static char utmpbuf[NRECS *UTSIZE];
static int num_recs;
static int cur_rec;
static int fd_utmp = -1;

void showtime(time_t);
void show_info(struct utmp *message_save);

int main()
{
	struct utmp *utbufp;

	if(utmp_open(UTMP_FILE) == -1)
	{
		perror("UTMP_FILE");
		exit(1);
	}
	while((utbufp = utmp_next()) != ((strcut utmp *)NULL))
		show_info(utbufp);
	utmp_close();

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
	printf("%12.12s", ctime((time_t *)&message_save->ut_time) + 4);
	printf("\t");
#ifdef SHOWHOST
	printf("(%s)", message_save->ut_host);
#endif
	putchar('\n');
}
