#include <stdio.h>
#include <stdlib.h>

struct pak
{
    int a;
    char r[256];
    float b;
};

int main(int argc, char *argv[])
{
    int size;
    struct pak p;
    FILE *pFile;

    /* If the file name is not set */
    if (argc == 1)
	{
        printf("Please, enter the file name");
        exit(1);
    }

    /* Open the file */
    else
	{
		pFile= fopen(argv[1], "rb");
		while (fread(&p, sizeof(struct pak), 1, pFile)) 
		{
			printf("%d %s %f \n", p.a, p.r, p.b);
		}

        /* File size */
        fseek(pFile, 0, SEEK_END);
        size = ftell(pFile);
        fseek(pFile, 0, SEEK_SET);
        printf("File size: %d%s", size, " bytes");
        fclose(pFile);
    }

    return 0;
}
