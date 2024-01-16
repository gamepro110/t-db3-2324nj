#include "mystack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct calc_t Calculation;
struct calc_t{
    uint8_t numAmount;
    int numbers[10];
    uint8_t numOperands;
    char operands[10];
};

void parseNLines(int* nOut);
void parseSum(int stackHandle);

int main(void) {
    printf("%% == √. ^ == ²\n");
    int stackHandle = MystackCreate(sizeof(Calculation));
    int nLines = 0;
    parseNLines(&nLines);

    while (nLines > -1) {
        parseSum(stackHandle);
        nLines--;
    }

    Calculation calc;
    while (MystackNofElem(stackHandle) > 0 && MystackPop(stackHandle, &calc) != -1 && calc.numAmount > 0 && calc.numOperands > 0) {
        int numIdx = 0;
        int opIdx = 0;
        int num1 = 0;
        int num2 = 0;

        while (opIdx < calc.numOperands) {
            switch (calc.operands[opIdx])
            {
            case '+': {
                num1 = calc.numbers[numIdx];
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 + num2);
                break;
            }
            case '-': {
                num1 = calc.numbers[numIdx];
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 - num2);
                break;
            }
            case '*': {
                num1 = calc.numbers[numIdx];
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 *num2);
                break;
            }
            case '/': {
                num1 = calc.numbers[numIdx];
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 / num2);
                break;
            }
            case '^': {
                num1 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 * num1);
                break;
            }
            case '%': {
                num1 = calc.numbers[numIdx];
                calc.numbers[numIdx] = sqrt(num1);
                break;
            }
            default:
                break;
            }
            opIdx++;
        }

        printf("result: %d\n", calc.numbers[numIdx]);
    }
    

    return MystackDestroy(stackHandle);
}

void parseNLines(int* nOut) {
    scanf("%d", nOut);
}

void parseSum(int stackHandle) {
    const uint8_t bufSize = 30;
    char buff[bufSize];
    uint8_t bufIdx = 0;
    char c = 0;

    while (bufIdx < bufSize && scanf("%c", &c) > 0 && c != '\n' && c != '\000') {
        buff[bufIdx] = c;
        bufIdx++;
        c = 0;
    }
    buff[bufIdx] = '\000';

    Calculation* calc = calloc(1, sizeof(Calculation));
    calc->numAmount = 0;
    calc->numOperands = 0;
    int number = 0;
    int numIdx = 0;

    for (int i = 0; i < bufIdx; i++) {
        c = buff[i];
        char num = c - '0';
        if (c == ' ' && number != 0) { // number ended. adding to calc
            calc->numbers[calc->numAmount] = number;
            calc->numAmount++;
            number = 0;
            numIdx = 0;
        }
        else if (num >= 0 && num < 10) { // number found
            if (numIdx > 0) {
                number *= 10;
            }
            number += c - '0';
            numIdx++;
        }
        else {
            switch (c)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
                calc->operands[calc->numOperands] = c;
                calc->numOperands++;
                break;
            default:
                break;
            }
        }
    }

    MystackPush(stackHandle, calc);
}
