#include <stdio.h>
#include <stdlib.h>

#define RUN_TEST(a) { \
extern int test_ ##a (void); \
int e = test_ ##a (); \
if (e) printf("%s test failed, %d error(s)\n", #a, e); \
else   printf("%s test passed\n", #a); \
err += e; \
}

int main(int argc, char** argv)
{
	int err=0;

	int i;
	if(argc != 2) {
		fprintf(stderr, "Usage: %s i\n", *argv);
		return 1;
	}

	i = atoi(argv[1]);

	switch(i) {
		case 0:
			RUN_TEST(fdopen);
			break;
		case 1:
			RUN_TEST(fcntl);
			break;
		case 2:
			RUN_TEST(fnmatch);
			break;
		case 3:
			RUN_TEST(fscanf);
			break;
		case 4:
			RUN_TEST(popen);
			break;
		case 5:
			RUN_TEST(socket);
			break;
		case 6:
			RUN_TEST(spawn);
			break;
		case 7:
			RUN_TEST(qsort);
			break;
		case 8:
			RUN_TEST(time);
			break;
		case 9:
			RUN_TEST(sscanf);
			break;
		case 10:
			RUN_TEST(snprintf);
			break;
		case 11:
			RUN_TEST(swprintf);
			break;
		case 12:
			RUN_TEST(stat);
			break;
		case 13:
			RUN_TEST(string);
			break;
		case 14:
			RUN_TEST(strtod);
			break;
		case 15:
			RUN_TEST(strtol);
			break;
		case 16:
			RUN_TEST(ungetc);
			break;
		case 17:
			RUN_TEST(wcstol);
			break;
		case 18:
			RUN_TEST(fwscanf);
			break;
		case 19:
			RUN_TEST(basename);
			break;
		case 20:
			RUN_TEST(dirname);
			break;
		case 21:
			RUN_TEST(memstream);
			break;
		case 22:
			RUN_TEST(mbc);
			break;
		case 23:
			RUN_TEST(setjmp);
			break;
		case 24:
			RUN_TEST(sem);
			break;
		case 25:
			RUN_TEST(pthread);
			break;
		case 26:
			/* env is last because it will break subsequent tests */
			RUN_TEST(env);
			break;
		default:
			printf("unknown test %d\n", i);
	}

	printf("\ntotal errors: %d\n", err);
	return !!err;
}
