#!/bin/sh

clang -c -emit-llvm musl-tests.c

cd libc-testsuite

rm *.bc
for file in *.c; do clang -c -emit-llvm $file; done
llvm-link -o ../musl-tests.bc ../musl-tests.bc basename.bc dirname.bc env.bc \
		fcntl.bc fdopen.bc fnmatch.bc fscanf.bc fwscanf.bc mbc.bc \
		memstream.bc popen.bc pthread.bc qsort.bc sem.bc setjmp.bc \
		snprintf.bc socket.bc spawn.bc sscanf.bc stat.bc string.bc \
		strtod.bc strtol.bc swprintf.bc time.bc ungetc.bc wcstol.bc

cd ..
