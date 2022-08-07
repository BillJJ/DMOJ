#include <stdio.h>
char _i[1 << 22], _o[1 << 22], _d[11], _; int _i0, _o0;
int main() {
    fread(_i, 1, 1 << 22, stdin);
    int N = 0, a, b;
    while ((_ = _i[_i0++]) & 16) N = (N << 3) + (N << 1) + (_ & 15);
    while (N--) {
        a = b = 0;
        if ((_ = _i[_i0++]) & 16)
            do a = (a << 3) + (a << 1) + (_ & 15); while ((_ = _i[_i0++]) & 16);
        else
            while ((_ = _i[_i0++]) & 16) a = (a << 3) + (a << 1) - (_ & 15);
        if ((_ = _i[_i0++]) & 16)
            do b = (b << 3) + (b << 1) + (_ & 15); while ((_ = _i[_i0++]) & 16);
        else
            while ((_ = _i[_i0++]) & 16) b = (b << 3) + (b << 1) - (_ & 15);

        if ((a += b) < 0) _o[_o0++] = '-', a = -a;
        _ = 0;
        do _d[_++] = a % 10; while (a /= 10);
        while (_--) _o[_o0++] = _d[_] | '0';
        _o[_o0++] = '\n';
    }
    fwrite(_o, 1, _o0, stdout);
	return 0;
}