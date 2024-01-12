#include <stdio.h>
#include <time.h>
#include <windows.h>

void file_numbers(int*);
void get_matrix(int, int ar[][50]);
void print_matrix(int, int ar[][50]);
void find_min_print(int, int ar[][50]);
COORD pos;
FILE* fr;

int main() {
    int matrix[50][50], n;
    file_numbers(&n);
    get_matrix(n, matrix);
    print_matrix(n, matrix);
    Sleep(1000);
    find_min_print(n, matrix);
    return 0;
}

void file_numbers(int* p) {
    int a, b, c;
    srand(time(NULL));
    printf("Input N = ");
    scanf_s("%d", p);
    printf("Random Numbers Betweeen: ");
    scanf_s("%d %d", &a, &b);
    if (a > b) {
        c = a;
        a = b;
        b = c;
    }
    fopen_s(&fr, "numbers.txt", "w+");
    for (int i = 0; i < *p * *p; i++)
        if (fr != 0)
            fprintf_s(fr, "%d ", rand() % (b - a + 1) + a);
    _fcloseall();
}

void get_matrix(int n, int ar[][50]) {
    int i, j;
    fopen_s(&fr, "numbers.txt", "r");
    if (fr != 0)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                fscanf_s(fr, "%d", &ar[i][j]);
    _fcloseall();
}



void print_matrix(int n, int ar[][50]) {

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            pos.X = 15 + j * 7;
            pos.Y = 6 + i * 3;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(hConsole, pos);
            printf("%5d", ar[i][j]);
        }
}

void find_min_print(int n, int ar[][50]) {
    int i, j, i_1 = 0, k, min;
    for (k = 0; k < 2 * n - 1; k++) {
        if (k >= n) i_1++;
        i = i_1;
        j = k - i;
        min = ar[i][j];

        while (j >= i_1) {
            if (ar[i][j] < min) min = ar[i][j];
            i++; j--;
        }

        i = i_1; j = k - i_1;
        while (j >= i_1) {
            Sleep(250);
            pos.X = 15 + j * 7;
            pos.Y = 6 + i * 3;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(hConsole, pos);
            ar[i][j] == min ? printf("\x1B[31m%5d\033[0m", ar[i][j]) : printf("%5d", ar[i][j]);
            i++; j--;
        }
    }
}

