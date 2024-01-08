ASSIGNMENT=linkedlist
ASSIGNMENT_TEST=$(ASSIGNMENT)_test

UNITY_FOLDER=./Unity
INC_DIRS=-Iproduct
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES=product/linked_list.c

ASSIGNMENT_FILES=$(SHARED_FILES) \
	      product/main.c \
	      product/my_memory.c \
	      product/terminal_io.c

ASSIGNMENT_TEST_FILES=$(SHARED_FILES) \
	           $(UNITY_FOLDER)/unity.c \
	           product/my_memory.c \
	           test/linkedlist_test.c

HEADER_FILES=product/*.h

CC=gcc

SYMBOLS= -g -O0 -std=c99 -Wall -Wextra -Werror
TEST_SYMBOLS=$(SYMBOLS) -DTEST

TESTDATA_DIR=./testdata
OUTPUT_FILE=$(TESTDATA_DIR)/my_output
INPUT_FILE=$(TESTDATA_DIR)/input
COMPARE_FILE=$(TESTDATA_DIR)/correct

VALGRIND=valgrind --leak-check=full --leak-check=summary --show-leak-kinds=all --track-origins=yes

.PHONY: clean test klocwork klocwork_after_makefile_change

all: $(ASSIGNMENT) $(ASSIGNMENT_TEST)

$(ASSIGNMENT): Makefile $(ASSIGNMENT_FILES)  $(HEADER_FILES)
	@$(CC) $(INC_DIRS) $(SYMBOLS) $(ASSIGNMENT_FILES) -o $(ASSIGNMENT)

$(ASSIGNMENT_TEST): Makefile $(ASSIGNMENT_TEST_FILES)  $(HEADER_FILES)
	@$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(ASSIGNMENT_TEST_FILES) -o $(ASSIGNMENT_TEST)

run_simple: $(ASSIGNMENT)
	@$(VALGRIND) ./$(ASSIGNMENT) < $(INPUT_FILE)_simple.txt > $(OUTPUT_FILE)_simple.txt
	./compareOut.sh $(COMPARE_FILE)_simple.txt $(OUTPUT_FILE)_simple.txt

run_full: $(ASSIGNMENT)
	@$(VALGRIND) ./$(ASSIGNMENT) < $(INPUT_FILE)_full.txt > $(OUTPUT_FILE)_full.txt
	./compareOut.sh $(COMPARE_FILE)_full.txt $(OUTPUT_FILE)_full.txt

run: run_simple run_full

clean:
	@rm -f $(ASSIGNMENT) $(ASSIGNMENT_TEST)
	@rm -rf kwinject.out .kwlp .kwps

test: $(ASSIGNMENT_TEST)
	@valgrind ./$(ASSIGNMENT_TEST)

klocwork:
	@kwcheck run

klocwork_after_makefile_change: clean
	@/opt/klocwork/kwenv.sh
	@kwcheck run
