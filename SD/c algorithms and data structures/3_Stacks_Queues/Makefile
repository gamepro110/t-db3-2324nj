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

reverse_files=$(SHARED_FILES) \
			reverseLinkedList/main.c \
			reverseLinkedList/linked_list.c

calc_files=$(SHARED_FILES) \
			polish_calc/calc_main.c

reverse_inc_dirs=$(INC_DIRS) -IreverseLinkedList/

HEADER_FILES=mystacklib/src/*.h

reverse_headers=$(HEADER_FILES) \
			reverseLinkedList/*.h

CC=gcc

SYMBOLS= -g -O0 -std=c99 -Wall -Wextra -Werror
TEST_SYMBOLS=$(SYMBOLS) -DTEST

VALGRIND=valgrind --leak-check=full --leak-check=summary --show-leak-kinds=all -s --track-origins=yes

.PHONY: clean test calc

all: $(ASSIGNMENT) $(ASSIGNMENT_TEST) reverse

$(ASSIGNMENT): Makefile $(ASSIGNMENT_FILES) $(HEADER_FILES)
	@$(CC) $(INC_DIRS) $(SYMBOLS) $(ASSIGNMENT_FILES) -o $(ASSIGNMENT)_exec

$(ASSIGNMENT_TEST): Makefile $(ASSIGNMENT_TEST_FILES) $(HEADER_FILES)
	@$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(ASSIGNMENT_TEST_FILES) -o $(ASSIGNMENT_TEST)

reverse: Makefile $(ASSIGNMENT_FILES) $(reverse_files) $(reverse_headers)
	@$(CC) $(reverse_inc_dirs) $(SYMBOLS) $(reverse_files) -o $@

calc: Makefile $(calc_files) $(HEADER_FILES)
	@$(CC) $(INC_DIRS) $(SYMBOLS) -lm $(calc_files) -o $@

run_calc: calc
	@$(VALGRIND) ./calc < polish_calc/input/example.txt

run: $(ASSIGNMENT)
	@$(VALGRIND) ./$(ASSIGNMENT)

run_reverse: reverse
	@$(VALGRIND) ./reverse

clean:
	@rm -f $(ASSIGNMENT) $(ASSIGNMENT_TEST)

test: $(ASSIGNMENT_TEST)
	@$(VALGRIND) --leak-check=full ./$(ASSIGNMENT_TEST)
