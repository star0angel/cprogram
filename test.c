#define M 10
#define N 8 

        //最多bai10个选手 
        //最多8个评委 
#include <stdio.h> 
struct Xs{
	int no;
	char name[20];
	int sc[M];
	float score;
};
int main() {
	int n, m;
	int i, j;
	struct Xs s[N], t;
	//printf("请输入多少选手(2到%d)和多少评委(3到%d)\n",N,M);
	scanf("%d%d", &n, &m);
	if (n > N  || n<2 || m>M  || m < 3) {
		printf("Data Error!\n");
		return 0;
	}
	for (i = 0; i < n; i++) {
		int sum = 0, max = 0, min = 100, sc;
		scanf("%d%s", &s[i].no, s[i].name);
		for (j = 0; j < m; j++) {
			scanf("%d", &sc);
			s[i].sc[j] = sc;
			sum += sc;
			if (sc > max) max = sc;
			if (sc < min) min = sc;
		}
		s[i].score = 1.0 * (sum - min - max) / (m - 2);
	}
	//排序
	for (i = 0; i < n - 1; i++) for (j = i + 1; j < n; j++)
		if (s[i].score < s[j].score) {
			t = s[i]; s[i] = s[j]; s[j] = t;
		}
	//输出
	printf("名次\t编号\t姓名\t\t\t得分\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%s\t\t\t%.1f\n", i + 1, s[i].no, s[i].name, s[i].score);
}