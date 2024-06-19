#!/bin/bash

#make:
	cd ..
	make re
	cp testers/push_swap_test/tester.py ./tester.py
	cp testers/checker_linux ./checker_linux
	clear

	python3 tester.py

	rm ./tester.py
	rm ./checker_linux
	make fclean > /dev/null 2>&1