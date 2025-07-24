#include <stdio.h>
#include <stdbool.h>

int main() {
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int len = sizeof(DataSet) / sizeof(DataSet[0]);

	// 위의 DataSet 배열의 Data를 버블 소팅 로직을 만들고
	// 소팅해서 출력해보세요...

	bool stop;
	int i, j, temp;
	for (i = 0; i < len - 1; i++) {
		stop = false;
		for (j = 0; j < len - 1 - i; j++) {
			if (DataSet[j] > DataSet[j + 1]) {
				temp = DataSet[j];
				DataSet[j] = DataSet[j + 1];
				DataSet[j + 1] = temp;
				stop = true;
			}
		}
		if (!stop) {
			break;
		}
	}

	for (i = 0; i < len; i++) {
		printf("%d ", DataSet[i]);
	}
	printf("\n");

	return 0;
}