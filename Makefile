#
# minimal example makefile using winzling unit test framework
#
# Copyright (c) 2015 Johannes Vogel, 84n4n4j03[at]gmail.com
#
# MIT License (MIT)
#
# visit: https://github.com/84n4n4j03/winzling
#

default: example_test

%: clean %.c
	@echo compiling and running: $@
	@gcc $@.c lib/winzling.c -o out/example_test
	@./$@


clean:
	@rm -rf out/
	@mkdir out

