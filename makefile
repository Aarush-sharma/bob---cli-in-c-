CC = g++
SRCS =  src/arithmetic/*.cpp src/magic/*.cpp 

bob:
	@echo "getting ready..."
	@$(CC) main.cpp $(SRCS) -o bob

run:
	@./bob