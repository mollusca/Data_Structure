/* BinarySearch / Fibonacci Sequence */

#include <stdio.h>

int BSearch(int *list, int first, int last, int target) {
	// list���� mid�� ���ϰ�, mid�� Ÿ���̸� �ٷ� ���� / �ƴϸ� ���� ��ġ
	int mid;

	if (first > last) return -1;

	mid = (first + last) / 2;

	if (list[mid] == target) return mid;
	else if (list[mid] < target)
		return BSearch(list, mid + 1, last, target);
	else
		return BSearch(list, first, mid - 1, target);
}

int fibo(int n) {
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int menu() {
	int opt;
	printf("1. Binary Search\n2. Fibonacci Sequence\n3. Quit\ninput > ");
	scanf("%d", &opt);

	return opt;
}

int main() {
	int i, opt = 1, target = 0, result;
	int list[] = { 1, 3, 5, 7, 9 };
	
	while (1) {
		if (opt == 3) break;
		switch (opt = menu()) {
		case 1:
			printf("\n** Binary Search **\nList >> ");
			for (i = 0; i < sizeof(list) / sizeof(int); i++)
				printf("%d ", list[i]);
			printf("\nTarget >> ");
			scanf("%d", &target);
			result = BSearch(list, 0, sizeof(list) / sizeof(int) - 1, target);
			if (result == -1)
				printf("Target�� ã�� �� ����\n");
			else
				printf("Result >> %d�� °��ġ\n\n", result + 1);
			break;
		case 2:
			printf("\n** Fibonacci Sequence **\n");
			printf("number >> ");
			scanf("%d", &target);
			printf("Result >> ");
			for (i = 1; i <= target; i++)
				printf("%d ", fibo(i));
			printf("\n\n");
			break;
		case 3:
			printf("����\n");
			break;
		default:
			printf("��Ȯ�Ѱ��� �Է��ϼ���. ������ ������\n");
		}	
	}
	return 0;
}