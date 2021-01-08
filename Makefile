target=test
inc=./

${target}:test.o keyvalue.o
	gcc $^ -o ${target} -I ${inc}

test.o:test.c
	gcc -c $^ -o $@
keyvalue.o:keyvalue.c
	gcc -c $^ -o $@

clean:
	rm *.o
	rm ${target}

.PHONY:clean
