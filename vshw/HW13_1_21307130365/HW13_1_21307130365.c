#include<stdio.h>
#include<string.h>
#define N sizeof(list)/sizeof(list[0])
//all test samples have passed
struct std {
	char name[11];
	int mid;
	int fin;
	int sco[16];
	float gpa;
};
int ws(int t) {
	int ws = 0;
	while (t) {
		ws++;
		t /= 10;
	}
	if (ws) {
		return ws;
	}
	return 1;
}
int main() {
	struct std list[] = {
		{"Moo", 100, 100, 100, 100, 100, 100, 100, 100}
		, {"Moore", 75, 85, 77, 59, 0, 85, 75, 89}
		, {"Norman", 57, 78, 73, 66, 78, 70, 88, 89}
		, {"Olson", 89, 86, 70, 90, 55, 73, 80, 84}
		, {"Peerson", 47, 70, 82, 73, 50, 87, 73, 71}
		, {"Russel", 72, 87, 88, 54, 55, 82, 69, 87}
		, {"Thomas", 90, 96, 99, 99, 100, 81, 97, 97}
		, {"Vaughn", 81, 97, 99, 67, 40, 90, 70, 96}
		, {"Westerly", 43, 98, 96, 79, 100, 82, 97, 96}
		, {"Baker", 67, 72, 73, 40, 0, 78, 55, 70}
		, {"Davis", 77, 70, 82, 65, 70, 77, 83, 81}
		, {"Edwards", 77, 72, 73, 80, 90, 93, 75, 90}
		, {"Franklin", 47, 70, 82, 73, 50, 87, 73, 71}
		, {"Jones", 77, 82, 83, 50, 10, 88, 65, 80}
		, {"Harris", 97, 90, 92, 95, 100, 87, 93, 91}
		, {"Smith", 87, 92, 93, 60, 0, 98, 75, 90}
		, {"Carpenter", 47, 90, 92, 73, 100, 87, 93, 91}
	};
	struct std *p = list;
	int x[10] = {0};
	for (int i = 0; i < N; i++) {
		int sum = 0;
		int *ps = p[i].sco;
		for (int j = 0; j < 6; j++) {
			sum += (ps[j]);
		}
		(p[i]).gpa = 0.2 * (p[i]).mid + 0.4 * (p[i]).fin + 0.4 * sum / 6;
	}//calcute gpa
	for (int i = 0; i < N; i++) {
		float g = (p[i].gpa);
		int t = (int) g;
		if (ws(t) > x[9]) {
			x[9] = ws(t);
		}
	}//get gpa's lenth
	for (int i = 0; i < N; i++) {
		if (strlen((p[i]).name) > x[0]) {
			x[0] = strlen((p[i]).name);
		};
	}//get name's lenth
	for (int i = 0; i < N; i++) {
		if (ws((p[i]).mid) > x[1]) {
			x[1] = ws((p[i]).mid);
		}
	}//get mid's lenth
	for (int i = 0; i < N; i++) {
		if (ws((p[i]).fin) > x[2]) {
			x[2] = ws((p[i]).fin);
		}
	}//get fin's lenth
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < N; j++) {
			int *ps = (p[j]).sco;
			if (ws(ps[i]) > x[i + 3]) {
				x[i + 3] = ws(ps[i]);
			}
		}
	}//get every sco's lenth
	printf("All students' records:\n");
	for (int i = 0; i < N; i++) {
		printf("%s", (p[i]).name);
		for (int j = 0; j < x[0] - strlen((p[i]).name); j++) {
			printf(" ");
		}
		printf(" %d", (p[i]).mid);
		for (int k = 0; k < x[1] - ws((p[i]).mid); k++) {
			printf(" ");
		}
		printf(" %d", (p[i]).fin);
		for (int k = 0; k < x[2] - ws((p[i]).fin); k++) {
			printf(" ");
		}
		int *ps = p[i].sco;
		for (int j = 0; j < 6; j++) {
			printf(" %d", ps[j]);
			for (int k = 0; k < x[j + 3] - ws(ps[j]); k++) {
				printf(" ");
			}
		}
		printf("\n");
	}//...just printing...
	struct std *pi[N];
	for (int i = 0; i < N; i++) {
		pi[i] = p + i;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (strcmp((pi[j])->name, (pi[j + 1])->name) > 0) {
				struct std *t = pi[j + 1];
				pi[j + 1] = pi[j];
				pi[j] = t;
			}
		}
	}
	printf("\nAll students' final grades (sorted by name):\n");
	for (int i = 0; i < N; i++) {
		printf("%s", (pi[i])->name);
		for (int j = 0; j <= x[0] - strlen((pi[i])->name); j++) {
			printf(" ");
		}
		printf("%.1f", (pi[i])->gpa);
		printf("\n");
	}//it seems that gpa's lenth can be deleted
	//considering the use of printf("\n")
	return 0;
}
