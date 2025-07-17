#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum
{
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-',
    MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ', OPERAND
} SYMBOL;

int          IsNumber(char Cipher);  // 숫자 판단
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE); // 문자열에서 토큰 분리
int          IsPrior(char Operator1, char Operator2); // 스택에 저장된 연산자와 스택 밖의 연산
void         GetPostfix(char* InfixExpression, char* PostfixExpression); // 중위식 문장을 후위식
double       Calculate(char* PostfixExpression); // 후위식

#endif
