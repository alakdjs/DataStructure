#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char* fileName;      // ������ ��ϵǾ��ִ� ������ ���ϸ�, (path ����)

    fileName = argv[1];

    char* pattern = argv[2];

    char Text[512];   // ���Ͽ��� ���� ������ ������ �迭

    FILE* fp;

    fp = fopen(fileName, "r");   // ������ �б���� ����

    if (fp == NULL) {
        printf("�����б⿡ �����Ͽ����ϴ�.\n");
        return 0;
    }

    if (argc < 3) {
        printf("Usage: �������ϸ� �������ϸ� ���Ϲ��ڿ�");
        return 0;
    }

    int patternLength = strlen(pattern);   // ���� ���ڿ��� ����
    int line = 1;
    int j = 0;

    while (fgets(Text, 512, fp) != NULL) {
        // �о���� ����ȿ� ã�� ���� ���ڿ��� �ִ��� Ȯ���ϰ�
        // ������ �ش� ���ι�ȣ�� �÷���ȣ�� ����ϸ�˴ϴ�.

        int length = strlen(Text);   // ���� ���ڿ��� ���̸� ���Ѵ�.

        for (int i = 0; i < length - patternLength + 1; i++) { // i ���� �����ϸ鼭 ������ ���ڿ� ���������� ����
            if (Text[i] == pattern[0]) {   // ������ ���ڿ� ������ ù���ڰ� ������ ��
                for (j = 1; j < patternLength; j++) {
                    /*
                    if (pattern[j] == Text[i + j]) {
                       continue;
                    }
                    else {
                       break;
                    }
                    */


                    if (pattern[j] != Text[i + j]) {
                        break;
                    }
                }

                // ���ϰ� ���� ���ڿ��� �ִ��� �Ǵ�
                if (j >= patternLength) { // ���� for���� j���� pattern�� ���̸�ŭ ���� ������ ���ϰ� ���� ���ڿ��� ����.
                    pritnf("line: %d, column: %d, text: %s\n", line, i, Text);
                }
            }
        }

        line++;
    }

    fclose(fp);

    return 0;
}
