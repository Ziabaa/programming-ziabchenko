CC = $(CLANG_PREFIX)clang++
LAB_OPTS = -I./src src/colleague.cpp src/worker.cpp
C_OPTS= $(MAC_OPTS) -std=c++14 -g -fsanitize=address -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Werror=vla  $(LAB_OPTS)

leak-check:
	ASAN_OPTIONS=detect_leaks=1 dist/main.bin
	ASAN_OPTIONS=detect_leaks=1 LLVM_PROFILE_FILE="dist/test.profraw" dist/test.bin

clean:
	rm -rf dist
prep:
	mkdir dist
compile:   main.bin test.bin

test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -lgtest_main -lgtest -lpthread

test: clean prep compile leak-check
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.cpp --format html > dist/coverage.html

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/main.bin
check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.cpp  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
all: clean prep compile leak-check

