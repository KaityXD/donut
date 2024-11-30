#include <math.h>
#include <stdio.h>
#include <unistd.h>

void clear_screen() {
    printf("\033[H\033[J");
}

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];

    printf("\033[?25l");
    while (1) {
        clear_screen();
        for (k = 0; k < 1760; k++) {
            b[k] = ' ';
            z[k] = 0;
        }

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;

                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        printf("\033[H");
        for (k = 0; k < 1760; k++) {
            putchar(k % 80 ? b[k] : 10);
        }

        A += 0.04;
        B += 0.08;
        usleep(30000);
    }

    printf("\033[?25h");
    return 0;
} // dont ask me why i stole this from chatgpt
