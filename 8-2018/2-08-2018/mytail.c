#include <stdio.h>
#include <stdlib.h>
 
int  buffersize = 20;
 
int main(int argc, char* argv[])
{
    if (argc < 2)
        printf("arguments to short!\n");
 
    char *filename = argv[1];
    int num = 5;
    if (argc == 3)
        num = atoi(argv[2]);
    printf("file : %s\n", filename);
    printf("num is : %d\n", num); 
    FILE *file = fopen(filename, "r");
    if ( file == NULL)
        perror("file open error");
    fseek(file, SEEK_SET, SEEK_END);
    int filesize = ftell(file);
    printf("file %s size is %d\n", filename, filesize);
 
    char res[5000];
    char buffer[buffersize];
    int now = 0, flag = 0;
    int ith = 0;
    int i, j = 0;
    while (now < num && ftell(file))
    {
 
        if (ftell(file) < buffersize)
            buffersize = ftell(file);
        if ( fseek(file, -buffersize , SEEK_CUR) == -1)
            perror("fseek error\n");
        int nread = 0;
        int n = 0;
        while (nread != buffersize)
        {
            n = fread(buffer+nread, 1, buffersize-nread, file);
            nread += n;
        }
        for (i = nread - 1; i >= 0; --i)
        {
            if (buffer[i] == '\n')
            {
                ++now;
                if (now == num + 1)
                {
                    flag = 1;
                    break;
                }
            }
            res[ith++] = buffer[i];
        }
        if (flag)
            break;
        fseek(file, -buffersize , SEEK_CUR);
    }
    fclose(file);
    for (i = ith; i >= 0; --i)
    {
        putchar(res[i]);
    }
    return 0;
}
