#include <bits/stdc++.h>

#define MAXDIGITS 100
#define PLUS 1
#define MINUS -1

using namespace std;

typedef long long ll;

typedef struct {
    char digits[MAXDIGITS];
    int signbit;
    int lastdigit;
} bignum;

void add_bignum(bignum *a, bignum *b, bignum *c);
void subtract_bignum(bignum *a, bignum *b, bignum *c);
void initialize_bignum(bignum *a);

// --- The next section of code until the main function ---
// --- was obtained through the slides from moodle ---

void ll_to_bignum(ll s, bignum *n) {
    int i;
    ll t;

    if (s >= 0) {
        n->signbit = PLUS;
    } else {
        n->signbit = MINUS;
    }

    for (i = 0; i < MAXDIGITS; i++) {
        n->digits[i] = (char) 0;
    }
    n->lastdigit = -1;

    t = (s >= 0) ? s : -s;
    while (t > 0) {
        n->lastdigit++;
        n->digits[n->lastdigit] = (char)(t % 10);
        t /= 10;
    }

    if (s == 0) {
        n->lastdigit = 0;
    }
}

int compare_bignum(bignum *a, bignum *b) {
    if ((a->signbit == MINUS) && (b->signbit == PLUS)) {
        return (PLUS);
    }
    if ((a->signbit == PLUS) && (b->signbit == MINUS)) {
        return (MINUS);
    }

    if (a->lastdigit > b->lastdigit) {
        return (MINUS * a->signbit);
    }
    if (b->lastdigit > a->lastdigit) {
        return (PLUS * a->signbit);
    }

    for (int i = a->lastdigit; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) {
            return (MINUS * a->signbit);
        }
        if (b->digits[i] > a->digits[i]) {
            return (PLUS * a->signbit);
        }
    }

    return 0;
}

void digit_shift(bignum *n, int d) {
    int i;

    if ((n->lastdigit == 0) && (n->digits[0] == 0)) {
        return;
    }

    for (i = n->lastdigit; i >= 0; i--) {
        n->digits[i+d] = n->digits[i];
    }

    for (i = 0; i < d; i++) {
        n->digits[i] = 0;
    }

    n->lastdigit = n->lastdigit + d;
}

void zero_justify(bignum *n) {
    while ((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0)) {
        n->lastdigit--;
    }

    if ((n->lastdigit == 0) && (n->digits[0] == 0)) {
        n->signbit = PLUS; // avoid -0 
    }
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    int i, carry;
    initialize_bignum(c);

    if (a->signbit == b->signbit) {
        c->signbit = a->signbit;
    } else {
        if (a->signbit == MINUS) {
            a->signbit = PLUS;
            subtract_bignum(b, a, c);
            a->signbit = MINUS;
        } else {
            b->signbit = PLUS;
            subtract_bignum(a, b, c);
            b->signbit = MINUS;
        }
        return;
    }

    c->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
    carry = 0;

    for (i = 0; i <= (c->lastdigit); i++) {
        c->digits[i] = (char)(carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    zero_justify(c);
}

void subtract_bignum(bignum *a, bignum *b, bignum *c) {
    int borrow;
    int v;
    int i;

    initialize_bignum(c);

    if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
        b->signbit = -1 * b->signbit;
        add_bignum(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
    }

    if (compare_bignum(a, b) == PLUS) {
        subtract_bignum(b, a, c);
        c->signbit = MINUS;
        return;
    }

    c->lastdigit = max(a->lastdigit, b->lastdigit);
    borrow = 0;

    for (i = 0; i <= (c->lastdigit); i++) {
        v = (a->digits[i] - borrow - b->digits[i]);
        if (a->digits[i] > 0) {
            borrow = 0;
        }
        if (v < 0) {
            v += 10;
            borrow = 1;
        }
        c->digits[i] = (char)v;
    }
    zero_justify(c);
}

void multiply_bignum(bignum *a, bignum *b, bignum *c) {
    bignum row;
    bignum tmp;
    int i, j;

    initialize_bignum(c);

    row = *a;

    for (i = 0; i <= b->lastdigit; i++) {
        for (j = 1; j <= b->digits[i]; j++) {
            add_bignum(c, &row, &tmp);
            *c = tmp;
        }
        digit_shift(&row, 1);
    }

    c->signbit = a->signbit * b->signbit;

    zero_justify(c);
}

void divide_bignum(bignum *a, bignum *b, bignum *c, bignum *rem) {
    bignum row;
    bignum tmp;
    int asign, bsign;
    int i, j;

    initialize_bignum(c);
    initialize_bignum(&row);
    initialize_bignum(&tmp);

    c->lastdigit = a->lastdigit;
    c->signbit = a->signbit * b->signbit;
    asign = a->signbit; 
    a->signbit = PLUS;
    bsign = b->signbit; 
    b->signbit = PLUS;

    for (i = a->lastdigit; i >= 0; i--) {
        digit_shift(&row, 1);
        row.digits[0] = a->digits[i];
        c->digits[i] = 0;
        while (compare_bignum(&row, b) != PLUS) {
            c->digits[i]++;
            subtract_bignum(&row, b, &tmp);
            row = tmp;
        }
    }
    zero_justify(c);
    a->signbit = asign;
    b->signbit = bsign;

    // getting remainder
    rem = &row;
    zero_justify(rem);
    print_bignum(rem);
}

// --- End of code section copied from moodle slides ---

void initialize_bignum(bignum *a) {
    for (int i = 0; i < MAXDIGITS; i++) {
        a->digits[i] = (char)0;
    }
    a->lastdigit = 0;
    a->signbit = PLUS;
}

void print_bignum(bignum *a) {
    for (int i = a->lastdigit; i >= 0; i--) {
        cout << (char) (a->digits[i] + '0');
    }
    cout << endl;
}

void str2bignum(string s, bignum *a) {
    a->signbit = PLUS;
   
    for (int i = 0; i < MAXDIGITS; i++) {
        a->digits[i] = (char) 0;
    }

    int idx = s.size() - 1;
    for (int i = 0; i < s.size(); i++) {
        a->digits[i] = s[idx] - '0';
        idx--;
    }

    a->lastdigit = s.size() - 1;
}

void get_remainder(bignum *a, bignum *mod, bignum *temp, bignum *rem) {
    divide_bignum(a, mod, temp, rem); // temp = a / mod
    multiply_bignum(temp, mod, rem); // rem = result * mod
    subtract_bignum(a, rem, rem);
}


int main (int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a_ll, n, m_ll;
    cin >> a_ll >> n >> m_ll;

    bignum *a = new bignum(), *m = new bignum();
    initialize_bignum(a);
    initialize_bignum(m);
    ll_to_bignum(a_ll, a);
    ll_to_bignum(m_ll, m);

    bignum *last_power = new bignum(), *sum = new bignum(), *new_power = new bignum();
    initialize_bignum(last_power);
    initialize_bignum(sum);
    initialize_bignum(new_power);
    ll one = 1;
    ll_to_bignum(one, sum); // a^0
    ll_to_bignum(one, last_power); // a^0
    ll_to_bignum(one, new_power);

    bignum *temp = new bignum(), *rem = new bignum();
    initialize_bignum(temp);
    initialize_bignum(rem);
    for (ll i = 1; i < n; i++) {
        multiply_bignum(last_power, a, new_power); // new_power = last_power * a

        divide_bignum(new_power, m, temp, rem);
        add_bignum(sum, rem, temp); // temp = sum + rem 
        // sum = temp;
        memcpy(sum, temp, sizeof(bignum)); // sum = temp

        divide_bignum(sum, m, temp, rem);
        // get_remainder(sum, m, temp, rem); // rem = sum % m; temp = sum / m
        // sum = rem;
        memcpy(sum, rem, sizeof(bignum)); // sum = rem;
        // last_power = new_power;
        memcpy(last_power, new_power, sizeof(bignum));
    }
    print_bignum(sum);

    return 0;
}