strtest: stringy.c 
	gcc stringy.c -o strtest
	./strtest
run: strtest
	./strtest