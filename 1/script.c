#include <stdio.h>

int main()
{
	FILE *fin;
      	fin = fopen("fileA", "w");
	int x = 0;
	while(x < 4*1024*1024+1)
	{
		x++;
		fprintf(fin, "%c", '\x00');
	}
	fseek(fin, 0, SEEK_SET);
	fprintf(fin, "%c", '\x01');
	fseek(fin, 10000, SEEK_SET);
	fprintf(fin, "%c", '\x01');
	fseek(fin, 4*1024*1024, SEEK_SET);
	fprintf(fin, "%c", '\x01');	
	fclose(fin);
}
