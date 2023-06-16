#include<stdio.h>
#include<string.h>
//all test samples have passed
//the added functions are between line 39 to line 86
struct std {
	char name[13];
	int mid;
	int fin;
	int sco[16];
	float gpa;
};

int ren() {
	FILE* pn, *p;
	int n = 0;
	char c;
	pn = fopen("students.csv", "r");
	while ((int)(c = fgetc(pn)) != -1) {
		if (c == '\n') {
			n++;
		}
	}
	fclose(pn);
	return n;
}

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

struct std * in(int n, struct std *ps) {
	FILE *p;
	p = fopen("students.csv", "r");
	char c1;
	for (int i = 0; i < n; i++) {
		c1 = fgetc(p);
		int j;
		for (j = 0; c1 != ','; j++) {
			ps[i].name[j] = c1;
			c1 = fgetc(p);
		}
		ps[i].name[j] = '\0';
		fscanf(p, "%d,", &ps[i].mid);
		fscanf(p, "%d,", &ps[i].fin);
		char c2 = ',';
		int k = 0;
		while (c2 != '\n') {
			fscanf(p, "%d", &ps[i].sco[k]);
			k++;
			c2 = fgetc(p);
		}
	}
	return ps;
}

void out(int n, struct std *p) {
	FILE *pf = fopen("grades.csv", "w");
	struct std *pi[n];
	for (int i = 0; i < n; i++) {
		pi[i] = p + i;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strcmp((pi[j])->name, (pi[j + 1])->name) > 0) {
				struct std *t = pi[j + 1];
				pi[j + 1] = pi[j];
				pi[j] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		fprintf(pf, "%s,%.1f", pi[i]->name, pi[i]->gpa);
		if (i < n)
			fprintf(pf, "\n");
	}
	fclose(pf);
}

int main() {
	int n = ren();
	int N = n;
	struct std list[n];
	struct std *p = in(n, list);
	int x[10] = {0};
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += (p[i].sco[j]);
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
	out(n, p);
	return 0;
}
