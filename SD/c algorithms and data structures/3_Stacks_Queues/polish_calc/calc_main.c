#include "mystack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

const int MaxSumLength = 40;

typedef struct sumVal_t SumValue;
struct sumVal_t{
    double value;
};

void parseNLines(int* nOut);
void parseSum(int stackHandle);
int GetValues(int stackHandle, double* num1, double* num2, char operand);

int main(void) {
    printf("line limit of %d chars (including white spaces)\n%% == √.\n^ == ²\n", MaxSumLength);
    int stackHandle = MystackCreate(sizeof(SumValue));
    int nLines = 0;
    parseNLines(&nLines);

    while (nLines > 0) {
        parseSum(stackHandle);
        nLines--;
    }

    return MystackDestroy(stackHandle);
}

void parseNLines(int* nOut) {
    scanf("%d\n", nOut);
}

void parseSum(int stackHandle) {
    char buff[MaxSumLength];
    uint8_t bufIdx = 0;
    char c = 0;

    while (bufIdx < MaxSumLength && scanf("%c", &c) > 0 && c != '\n' && c != '\000') {
        buff[bufIdx] = c;
        bufIdx++;
        c = 0;
    }
    buff[bufIdx] = '\000';

    double number = 0;
    int numIdx = 0;

    for (int i = 0; i < bufIdx; i++) {
        c = buff[i];
        char num = c - '0';
        if (c == ' ' && number != 0) { // number ended. adding num to stack
            SumValue* sumVal = calloc(1, sizeof(SumValue));
            sumVal->value = number;
            MystackPush(stackHandle, sumVal);
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
        else if (c != ' ') {
            double num1 = 0;
            double num2 = 0;
            SumValue* data = calloc(1, sizeof(SumValue));

            switch (c)
            {
            case '+': {
                if (GetValues(stackHandle, &num1, &num2, c) == 0) {
                    data->value = num1 + num2;
                    if (MystackPush(stackHandle, data) == -1) {
                        return;
                    }
                    data = NULL;
                }
                break;
            }
            case '-': {
                if (GetValues(stackHandle, &num1, &num2, c) == 0) {
                    data->value = num2 - num1;
                    if (MystackPush(stackHandle, data) == -1) {
                        return;
                    }
                    data = NULL;
                }
                break;
            }
            case '*': {
                if (GetValues(stackHandle, &num1, &num2, c) == 0) {
                    data->value = num1 * num2;
                    if (MystackPush(stackHandle, data) == -1) {
                        return;
                    }
                    data = NULL;
                }
                break;
            }
            case '/': {
                if (GetValues(stackHandle, &num1, &num2, c) == 0) {
                    data->value = num1 / num2;
                    if (MystackPush(stackHandle, data) == -1) {
                        return;
                    }
                    data = NULL;
                }
                break;
            }
            case '^': {
                if (GetValues(stackHandle, &num1, NULL, c) == 0) {
                    data->value = num1 * num1;
                    if (MystackPush(stackHandle, data) == -1) {
                        return;
                    }
                    data = NULL;
                }
                break;
            }
            case '%': {
                if (GetValues(stackHandle, &num1, NULL, c) == 0) {
                    data->value = sqrt(num1);
                    if (MystackPush(stackHandle, data) == -1) {
                        return;
                    }
                    data = NULL;
                }
                break;
            }
            default:
                printf("[ERROR]: INVALID INPUT CHAR (%c | %d)\n", c, c);
                break;
            }

            if (data != NULL) {
                free(data);
            }
        }
    }

    SumValue result;
    result.value = 0;
    int precision = (result.value - (int)result.value == 0.0) ? 0 : 3;
    MystackPop(stackHandle, &result);
    printf("%.*f\n", precision, result.value);
}

int GetValues(int stackHandle, double* num1, double* num2, char operand) {
    if (stackHandle < 1) {
        return -1;
    }

    SumValue val;

    if (num1 != NULL && MystackPop(stackHandle, &val) == 0) {
        (*num1) = val.value;
    }
    else {
        return -1;
    }


    if (operand != '^' && operand != '%') {
        if (num2 != NULL && MystackPop(stackHandle, &val) == 0) {
            (*num2) = val.value;
        }
        else {
            return -1;
        }
    }

    return 0;
}

/* overcomplicating it. will keep it in a comment tho
    // go through operands in reverse
    // go through numbers in reverse
    SumValue calc;
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
                calc.numbers[numIdx] = 0;
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 + num2);
                break;
            }
            case '-': {
                num1 = calc.numbers[numIdx];
                calc.numbers[numIdx] = 0;
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 - num2);
                break;
            }
            case '*': {
                num1 = calc.numbers[numIdx];
                calc.numbers[numIdx] = 0;
                numIdx++;
                num2 = calc.numbers[numIdx];
                calc.numbers[numIdx] = (num1 *num2);
                break;
            }
            case '/': {
                num1 = calc.numbers[numIdx];
                calc.numbers[numIdx] = 0;
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
    }

*/