 /*************************************************************************
	> File Name: ioctl_fb.c
	> Author: free
	> Mail: fancanglang@foxmail.com 
	> Created Time: Sun 17 Jun 2018 04:10:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/fb.h>
#include <sys/ioctl.h>

int main(void)
{
	int fd;

	struct fb_var_screeninfo fb_info;

	fd = open("/dev/fb0", O_RDONLY);
	if(fd < 0)
	{
		perror("open fb0");
		exit(1);
	}

	ioctl(fd, FBIOGET_VSCREENINFO, &fb_info);
	printf("R=%d\nC=%d\n", fb_info.xres, fb_info.yres);

	close(fd);
	return 0;
}
