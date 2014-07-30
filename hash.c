#include <stdio.h>
#include <string.h>

static const char hashtable[256] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

     0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,
    16,17,18,19,20,21,22,23,24,25,26,27,28,29, 0, 0,
     0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,
    16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,30,

    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,

    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
    31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
};

int main(int argc, char **argv)
{
	int i, hash = 0;
	char *arg = NULL;

	if (argc < 3)
	{
		fprintf(stderr, "usage: %s c|n arg1 <arg2>...\n", argv[0]);
		return (-1);
	}
        switch(argv[1][0])
        {
            case 'c':
                for ( i = 1; i < argc; i++)
                {
                    arg = strdup(argv[i]);
                    hash = (((arg)[0]&31)<<5 | ((arg)[1]&31));
                    printf("%s: %d\n", arg, hash);
                }
                return (0);
            case 'n':
                for ( i = 1; i < argc; i++)
                {
                    arg = strdup(argv[i]);
                    hash = hashtable[(unsigned char)((arg)[1])]<<5 | (arg[1] ? hashtable[(unsigned char)((arg)[2])] : 0);
                    printf("%s: %d\n", arg, hash);
                }
                return (0);
            default:
		fprintf(stderr, "usage: %s c|n arg1 <arg2>...\n"i, argv[0]);
		return (-1);
        }
}