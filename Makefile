ARGS=-I/usr/lib/llvm-15/include -std=c++17 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS
ARGS2=-I/usr/lib/llvm-15/include -std=c++17 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS

.PHONY: clean all

all: kfe

kfe: bin/driver.o bin/parser.o bin/scanner.o bin/kfe.o bin/ifExprAST.o bin/seqAST.o bin/functionAST.o bin/prototypeAST.o bin/exprAST.o bin/numberExprAST.o bin/variableExprAST.o bin/binaryExprAST.o bin/unaryExprAST.o bin/callExprAST.o bin/printAST.o bin/varExprAST.o bin/whileExprAST.o bin/forExprAST.o
	clang++ -o kfe bin/driver.o bin/parser.o bin/scanner.o bin/kfe.o bin/ifExprAST.o bin/seqAST.o bin/functionAST.o bin/exprAST.o bin/numberExprAST.o bin/prototypeAST.o bin/variableExprAST.o bin/binaryExprAST.o bin/unaryExprAST.o bin/callExprAST.o bin/printAST.o bin/varExprAST.o bin/whileExprAST.o bin/forExprAST.o `llvm-config --cxxflags --ldflags --libs --libfiles --system-libs` 

bin/kfe.o: src/kfe.cc src/driver.hh src/AST/Utils/LogError.hh
	clang++ -o bin/kfe.o -c src/kfe.cc $(ARGS2)
	
bin/parser.o: src/parser.cc
	clang++ -o bin/parser.o -c src/parser.cc $(ARGS2)
	
bin/scanner.o: src/scanner.cc src/parser.hh
	clang++ -o bin/scanner.o -c src/scanner.cc  $(ARGS) 
	
bin/driver.o: src/driver.cc src/parser.hh src/driver.hh
	clang++ -o bin/driver.o -c src/driver.cc $(ARGS2) 

bin/ifExprAST.o: src/AST/IfExprAST.cc src/AST/IfExprAST.hh 
	clang++ -o bin/ifExprAST.o -c src/AST/IfExprAST.cc  $(ARGS) 
	
bin/seqAST.o: src/AST/SeqAST.cc src/AST/SeqAST.hh 
	clang++ -o bin/seqAST.o -c src/AST/SeqAST.cc  $(ARGS) 
	
bin/prototypeAST.o: src/AST/PrototypeAST.cc src/AST/PrototypeAST.hh 
	clang++ -o bin/prototypeAST.o -c src/AST/PrototypeAST.cc  $(ARGS) 

bin/functionAST.o: src/AST/FunctionAST.cc src/AST/FunctionAST.hh 
	clang++ -o bin/functionAST.o -c src/AST/FunctionAST.cc  $(ARGS) 
	
bin/exprAST.o: src/AST/ExprAST.cc src/AST/ExprAST.hh 
	clang++ -o bin/exprAST.o -c src/AST/ExprAST.cc  $(ARGS) 
	
bin/numberExprAST.o: src/AST/NumberExprAST.cc src/AST/NumberExprAST.hh 
	clang++ -o bin/numberExprAST.o -c src/AST/NumberExprAST.cc  $(ARGS) 
	
bin/variableExprAST.o: src/AST/VariableExprAST.cc src/AST/VariableExprAST.hh 
	clang++ -o bin/variableExprAST.o -c src/AST/VariableExprAST.cc  $(ARGS) 
	
bin/binaryExprAST.o: src/AST/BinaryExprAST.cc src/AST/BinaryExprAST.hh 
	clang++ -o bin/binaryExprAST.o -c src/AST/BinaryExprAST.cc  $(ARGS) 

bin/unaryExprAST.o: src/AST/UnaryExprAST.cc src/AST/UnaryExprAST.hh 
	clang++ -o bin/unaryExprAST.o  -c src/AST/UnaryExprAST.cc  $(ARGS) 
	
bin/callExprAST.o: src/AST/CallExprAST.cc src/AST/CallExprAST.hh 
	clang++ -o bin/callExprAST.o -c src/AST/CallExprAST.cc  $(ARGS) 
	
bin/forExprAST.o: src/AST/ForExprAST.cc src/AST/ForExprAST.hh 
	clang++ -o bin/forExprAST.o -c src/AST/ForExprAST.cc  $(ARGS) 
	
bin/printAST.o: src/AST/PrintAST.cc src/AST/PrintAST.hh 
	clang++ -o bin/printAST.o -c src/AST/PrintAST.cc  $(ARGS) 
	
bin/varExprAST.o: src/AST/VarExprAST.cc src/AST/VarExprAST.hh 
	clang++ -o bin/varExprAST.o -c src/AST/VarExprAST.cc  $(ARGS) 
	
bin/whileExprAST.o: src/AST/WhileExprAST.cc src/AST/WhileExprAST.hh 
	clang++ -o bin/whileExprAST.o -c src/AST/WhileExprAST.cc  $(ARGS) 
	
bin/arrayExprAST.o: src/AST/ArrayExprAST.cc src/AST/ArrayExprAST.hh 
	clang++ -o bin/arrayExprAST.o -c src/AST/ArrayExprAST.cc  $(ARGS) 
	
bin/arrayAssignExprAST.o: src/AST/ArrayAssignExprAST.cc src/AST/ArrayAssignExprAST.hh 
	clang++ -o bin/arrayAssignExprAST.o -c src/AST/ArrayAssignExprAST.cc  $(ARGS) 
	
src/parser.cc, src/parser.hh: src/parser.yy 
	bison -o src/parser.cc src/parser.yy -Wcounterexamples

src/scanner.cc: src/scanner.ll
	flex -o src/scanner.cc src/scanner.ll

clean:
	rm -f bin/*.o*
	rm src/parser.cc src/scanner.cc src/parser.hh
