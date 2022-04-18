#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int file1 = 0;
	int file2 = 1;
	int size = 4096; 
	if (argc == 2)
		file2 = open(argv[1], O_WRONLY | O_CREAT); 
	else if (argc == 3)
	{
		file1 = open(argv[1], O_RDONLY);
		file2 = open(argv[2], O_WRONLY | O_CREAT);
	}
	else if (argc == 4)
	{
		file1 = open(argv[1], O_RDONLY);
		file2 = open(argv[2], O_WRONLY | O_CREAT);
		size = atoi(argv[3]);
	}
	char block[size];
    	if (errno)
        {
		printf("Ошибка открытия");
        	return 1;
	}
	while(size = read(file1, block, size))
	{
        	if (errno)
        	{
			printf("Ошибка чтения");
        		return 1;
		}
    		if (checkBlock(block, size))
        		lseek(file2, size, SEEK_CUR);
    		else 
		{
			if (errno)
        		{
				printf("Ошибка записи");
       				return 1;
			}
       			write(file2, block, size);
		}
	}
	close(file1);
	close(file2);
}

int checkBlock(char *block,int size)
{
	int i = 0;
    	while (i < size)
	{
        	if (block[i] != 0)
            		return 0;
		i++;
	}
    	return 1;   
}
