#!/bin/bash

#make:
	cd testers
	git clone git@github.com:julien-ctx/push-swap-tester.git
	mv push-swap-tester/tester.py ../
	mv push-swap-tester/checker_linux ../
	rm -rf push-swap-tester

	cd ..
	chmod 777 checker_linux
	sed -i -- 's/checker_Mac/checker_linux/g' tester.py
	
	make re
	clear
	python3 tester.py
	
	rm ./tester.py
	rm ./checker_linux
	make fclean > /dev/null 2>&1