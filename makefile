cc=g++
object_flag= -c
output_flag= -o

main.out: bin main.o support.o
	${cc} out/main.o out/support.o ${output_flag} bin/main.out

main.o: out main.cpp
	${cc} ${object_flag} main.cpp ${output_flag} out/main.o

support.o: out support.cpp
	${cc} ${object_flag} support.cpp ${output_flag} out/support.o

out:
	mkdir -p out

bin:
	mkdir -p bin

clear:
	find . -name "*.o" -type f -delete