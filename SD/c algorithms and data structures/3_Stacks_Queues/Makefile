ASSIGNMENT=mystack
ASSIGNMENT_TEST=$(ASSIGNMENT)_test

UNITY_FOLDER=./mystacklib/Unity
INC_DIRS=-Imystacklib/src/
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES=mystacklib/src/$(ASSIGNMENT).c

ASSIGNMENT_FILES=$(SHARED_FILES) \
	      mystack/product/main.c \

ASSIGNMENT_TEST_FILES=$(SHARED_FILES) \
	           $(UNITY_FOLDER)/unity.c \
	           mystacklib/test/$(ASSIGNMENT)_test.c

HEADER_FILES=mystacklib/src/*.h

CC=gcc

SYMBOLS= -g -O0 -std=c99 -Wall -Wextra -Werror
TEST_SYMBOLS=$(SYMBOLS) -DTEST

VALGRIND=valgrind --leak-check=full --leak-check=summary --show-leak-kinds=all -s --track-origins=yes

.PHONY: clean test

all: $(ASSIGNMENT) $(ASSIGNMENT_TEST)

$(ASSIGNMENT): Makefile $(ASSIGNMENT_FILES)  $(HEADER_FILES)
	@$(CC) $(INC_DIRS) $(SYMBOLS) $(ASSIGNMENT_FILES) -o $(ASSIGNMENT)_exec

$(ASSIGNMENT_TEST): Makefile $(ASSIGNMENT_TEST_FILES)  $(HEADER_FILES)
	@$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(ASSIGNMENT_TEST_FILES) -o $(ASSIGNMENT_TEST)

run: $(ASSIGNMENT)
	@$(VALGRIND) ./$(ASSIGNMENT)

clean:
	@rm -f $(ASSIGNMENT) $(ASSIGNMENT_TEST)

test: $(ASSIGNMENT_TEST)
	@$(VALGRIND) --leak-check=full ./$(ASSIGNMENT_TEST)
