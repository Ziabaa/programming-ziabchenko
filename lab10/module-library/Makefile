CC = clang
LAB_OPTS = -I./src src/lib.c
C_OPTS = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla 

clean:
	rm -rf dist
prep:
	mkdir dist

compile: lib.a test.bin

test.bin: test/test.c
	$(CC) $(C_OPTS) $(LAB_OPTS) $< -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -lcheck -lm -lrt -lpthread -lsubunit

lib.a:
	$(CC) -c $(C_OPTS) $< src/lib.c -o ./dist/lib.o
	ar rsc dist/liblib.a ./dist/lib.o
	cp dist/liblib.a ../lib
	cp src/lib.h ../lib

test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

all: clean prep compile check

