.PHONY: clean all

all: emilia

emilia: bin/driver.o bin/parser.o bin/scanner.o bin/emilia.o
	clang++ -o emilia bin/driver.o bin/parser.o bin/scanner.o bin/emilia.o `llvm-config --cxxflags --ldflags --libs --libfiles --system-libs`

bin/emilia.o:  src/emilia.cpp src/driver.hpp
	clang++ -o bin/emilia.o -c src/emilia.cpp -I/usr/lib/llvm-15/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/lib/llvm-15/lib -lllvm-15
	
bin/parser.o: src/parser.cpp
	clang++ -o bin/parser.o -c src/parser.cpp -I/usr/lib/llvm-15/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
	
bin/scanner.o: src/scanner.cpp src/parser.hpp
	clang++ -o bin/scanner.o -c src/scanner.cpp -I/usr/lib/llvm-15/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
	
bin/driver.o: src/driver.cpp src/parser.hpp src/driver.hpp
	clang++ -o bin/driver.o -c src/driver.cpp -I/usr/lib/llvm-15/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 

src/parser.cpp, src/parser.hpp: src/parser.yy 
	bison -o src/parser.cpp src/parser.yy

src/scanner.cpp: src/scanner.ll
	flex -o src/scanner.cpp src/scanner.ll

clean:
	rm -f *~ bin/driver.o bin/scanner.o bin/parser.o bin/emilia.o emilia src/scanner.cpp src/parser.cpp src/parser.hpp
