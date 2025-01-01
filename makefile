CC = g++
SRCS =  src/arithmetic/*.cpp src/magic/*.cpp src/api/*.cpp src/http/*.cpp

bob:
	@echo "getting ready..."
	@$(CC) main.cpp $(SRCS) -o bob -lcurl

run:
	@./bob
