#
# minimal example makefile using winzling unit test framework
#
# Copyright (c) 2015 Johannes Vogel, 84n4n4j03[at]gmail.com
#
# MIT License (MIT)
#

C_SRC = \
example_test.c \
lib/winzling.c \

test: clean example_test
	./example_test

example_test:
	gcc $(C_SRC) -o example_test

clean:
	rm -f example_test

