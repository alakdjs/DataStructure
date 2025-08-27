#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char* fileName;		// ������ ��ϵǾ��ִ� ������ ���ϸ�, (path ����)

	fileName = argv[1];

	char* pattern = argv[2];

	char Text[512];		// ���Ͽ��� ���� ������ ������ �迭

	FILE* fp;

	fp = fopen(fileName, "r");		// ������ �б���� ����

	if (fp == NULL) {
		printf("�����б⿡ �����Ͽ����ϴ�.\n");
		return 0;
	}

	if (argc < 3) {
		printf("Usage: �������ϸ� �������ϸ� ���Ϲ��ڿ�");
		return 0;
	}

	int patterLength = strlen(pattern);		// ���� ���ڿ��� ����
	int line = 1;
	int j = 0;

	while (fgets(Text, 512, fp) != NULL) {
		// �о���� ����ȿ� ã�� ���� ���ڿ��� �ִ��� Ȯ���ϰ�
	    // ������ �ش� ���ι�ȣ�� �÷���ȣ�� ����ϸ�˴ϴ�.

		int length = strlen(Text);		// ���� ���ڿ��� ���̸� ���Ѵ�.

		for (int col = 0; col <= length - patterLength; col++) {
			int match = 1;
			for (int k = 0; k < patterLength; k++) {
				if (Text[col + k] != pattern[k]) {
					match = 0;
					break;
				}
			}
			if (match) {
				printf("[line %d, col %d] %s", line, col + 1, Text);
				break;
			}
		}
		line++;

	}
	
	fclose(fp);

	return 0;
}