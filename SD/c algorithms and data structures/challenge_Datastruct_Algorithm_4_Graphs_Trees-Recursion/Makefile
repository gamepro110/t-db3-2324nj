ASSIGNMENT=graphTree
ASSIGNMENT_TEST=$(ASSIGNMENT)_test

UNITY_FOLDER=./Unity
INC_DIRS=-Iproduct
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES=product/Tree.c

ASSIGNMENT_FILES=$(SHARED_FILES) \
	      product/main.c \

ASSIGNMENT_TEST_FILES=$(SHARED_FILES) \
	           $(UNITY_FOLDER)/unity.c \
	           test/graphTree_test.c

HEADER_FILES=product/*.h

CC=gcc

SYMBOLS= -g -O0 -std=c99 -Wall -Wextra -Werror
TEST_SYMBOLS=$(SYMBOLS) -DTEST

TESTDATA_DIR=./testdata
OUTPUT_FILE=$(TESTDATA_DIR)/my_out
INPUT_FILE=$(TESTDATA_DIR)/in
COMPARE_FILE=$(TESTDATA_DIR)/out

.PHONY: clean test klocwork klocwork_after_makefile_change

all: $(ASSIGNMENT) $(ASSIGNMENT_TEST)

$(ASSIGNMENT): Makefile $(ASSIGNMENT_FILES)  $(HEADER_FILES)
	@$(CC) $(INC_DIRS) $(SYMBOLS) $(ASSIGNMENT_FILES) -o $(ASSIGNMENT)

$(ASSIGNMENT_TEST): Makefile $(ASSIGNMENT_TEST_FILES)  $(HEADER_FILES)
	@$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(ASSIGNMENT_TEST_FILES) -o $(ASSIGNMENT_TEST)

3_1: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 3 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

3_2: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 3 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

3_2db: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 3 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

3_3: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 3 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

4_1: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 4 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

4_2: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 4 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

4_3: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 4 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

4_4: $(ASSIGNMENT)
	@time valgrind --leak-check=full ./$(ASSIGNMENT) 4 < $(INPUT_FILE)$@ > $(OUTPUT_FILE)$@
	./compareOut.sh $(COMPARE_FILE)$@ $(OUTPUT_FILE)$@

3_: 3_1 3_2 3_3

4_: 4_1 4_2 4_3 4_4

run: 3_ 4_

clean:
	@rm -f $(ASSIGNMENT) $(ASSIGNMENT_TEST)

test: $(ASSIGNMENT_TEST)
	@time valgrind --leak-check=full ./$(ASSIGNMENT_TEST)
