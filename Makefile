CC=gcc

CFLAGS=-Wall -Wmultichar

src=src/
build=build/
build_t=build_t/
bin=bin/

OBJECTS=$(addprefix $(build), main.o caesar_crypt.o caesar_decrypt.o Viginer_crypt.o Viginer_uncrypt.o random_symb.o vernam_crypt.o,vernam_decrypt.o)
OBJECTS_T=$(addprefix $(build_t), main_test.o Viginer_crypt.o Viginer_uncrypt.o vernam_crypt.o vernam_decrypt.o caesar_crypt.o caesar_decrypt.o)
EXE=bin/main

.PHONY: all clean test

all: build bin $(EXE)

test: bin build_t $(bin)main_test
	$(bin)main_test

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(build)main.o: $(src)main.c
	$(CC) $(CFLAGS) -c $(src)main.c -o $@

$(build)Viginer_crypt.o: $(src)Viginer_crypt.o $(src)Viginer.h
	$(CC) $(CFLAGS) -c $(src)Viginer_crypt.c -o $@

$(build)Viginer_uncrypt.o: $(src)Viginer_uncrypt.c $(src)Viginer.h
	$(CC) $(CFLAGS) -c $(src)Viginer_uncrypt.c -o $@

$(build)random_symb.o: $(src)random_symb.c $(src)vernam_crypt.h
	$(CC) $(CFLAGS) -c $(src)random_symb.c -o $@

$(build)vernam_crypt.o: $(src)vernam_crypt.c $(src)vernam_crypt.h
	$(CC) $(CFLAGS) -c $(src)vernam_crypt.c -o $@

$(build)vernam_decrypt.o: $(src)vernam_decrypt.c $(src)vernam_crypt.h
	$(CC) $(CFLAGS) -c $(src)vernam_decrypt.c -o $@

$(build)caesar_crypt.o: $(src)caesar_crypt.c $(src)caesar.h
	$(CC) $(CFLAGS) -c $(src)caesar_crypt.c -o $@

$(build)caesar_decrypt.o: $(src)caesar_decrypt.c $(src)caesar.h
	$(CC) $(CFLAGS) -c $(src)caesar_decrypt.c -o $@

$(bin)main_test: $(OBJECTS_T)
	$(CC) $(CFLAGS) $(OBJECTS_T) -o $@

$(build_t)main_test.o: test/main.c thirdparty/ctest.h $(src)Viginer.h $(src)vernam_crypt.h $(src)caesar.h
	$(CC) $(CFLAGS) -I thirdparty -I src -c test/main.c -o $@

$(build_t)Viginer_crypt.o: $(src)Viginer_crypt.c $(src)Viginer.h
	$(CC) $(CFLAGS) -c $(src)Viginer_crypt.c -o $@

$(build_t)Viginer_uncrypt.o: $(src)Viginer_uncrypt.c $(src)Viginer.h
	$(CC) $(CFLAGS) -c $(src)Viginer_uncrypt.c -o $@

$(build_t)random_symb.o: $(src)random_symb.c $(src)vernam_crypt.h
	$(CC) $(CFLAGS) -c $(src)random_symb.c -o $@

$(build_t)vernam_crypt.o: $(src)vernam_crypt.c $(src)vernam_crypt.h
	$(CC) $(CFLAGS) -c $(src)vernam_crypt.c -o $@

$(build_t)vernam_decrypt.o: $(src)vernam_decrypt.c $(src)vernam_crypt.h
	$(CC) $(CFLAGS) -c $(src)vernam_decrypt.c -o $@

$(build_t)caesar_crypt.o: $(src)caesar_crypt.c $(src)caesar.h
	$(CC) $(CFLAGS) -c $(src)caesar_crypt.c -o $@

$(build_t)caesar_decrypt.o: $(src)caesar_decrypt.c $(src)caesar.h
	$(CC) $(CFLAGS) -c $(src)caesar_decrypt.c -o $@

build:
	mkdir build

build_t:
	mkdir build_t

bin:
	mkdir bin

src:
	mkdir src

clean:
	rm -rf build build_t bin

