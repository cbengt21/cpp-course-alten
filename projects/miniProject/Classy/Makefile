normal: main.cpp sudoku_solver.o sudoku_reader.o
	@echo -- Building a.out from $^
	g++ main.cpp sudoku_solver.o sudoku_reader.o -Iinclude -o a.out

%.o: src/%.cpp
	@echo -- Compiling $< into $@
	g++ $< -c -Iinclude
