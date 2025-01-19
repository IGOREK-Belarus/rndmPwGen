start:
	mkdir build/
	gcc src/rndmpwgen.c -o build/rndmpwgen
launch:
	build/rndmpwgen
clear:
	rm -rf build