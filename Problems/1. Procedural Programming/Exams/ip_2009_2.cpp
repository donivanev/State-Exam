#include <iostream>
#include <cstring>
using namespace std;

/*
Да се напише програма, която въвежда от клавиатурата масив от 5 символни низа, всеки с максимална дължина 50 символа. Програмата да извежда
текста "yes" в случай, че от въведените низове има такъв низ s, на който всички останали низове са поднизове и "no" в противен случай.
Забележка: Низът a₀ a₁ … aₖ е подниз на низа b₀ b₁ … bₘ, ако k ≤ m и ∃i ∈ N : 0 ≤ i ≤ m-k и a₀ = bᵢ, a₁ = bᵢ₊₁, …, aₖ = bᵢ₊ₖ.
Например, "abc" е подниз на "0abc1", но не е подниз на "a0b1c". 
*/

const int N = 5;
const int MAX_LEN = 51;

/* bool is_substring(const char* text, const char* sub) {
    int len_t = strlen(text), len_s = strlen(sub);

    if (len_s > len_t)
        return false;

    for (int i = 0; i <= len_t - len_s; ++i) {
        bool match = true;

        for (int j = 0; j < len_s; ++j) {
            if (text[i + j] != sub[j]) {
                match = false;
                break;
            }
        }

        if (match)
            return true;
    }

    return false;
} */

// Въвежда масив от низове от клавиатурата
void input(char strings[][MAX_LEN]) {
    cout << "Въведете " << N << " низа (до 50 символа):\n";

    for (int i = 0; i < N; ++i) {
        cin.getline(strings[i], MAX_LEN);
    }
}

// Проверява дали sub е подниз на text чрез strstr
bool is_substring(const char* text, const char* sub) {
    return strstr(text, sub) != nullptr;
}

// Проверява дали всички останали низове са поднизове на низ с индекс index
bool is_superstring(const char strings[][MAX_LEN], int index) {
    for (int i = 0; i < N; ++i) {
        if (i != index && !is_substring(strings[index], strings[i])) {
            return false;
        }
    }

    return true;
}

// Проверява дали има суперниз и извежда резултата
void has_superstring(const char strings[][MAX_LEN]) {
    for (int i = 0; i < N; ++i) {
        if (is_superstring(strings, i)) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}

int main() {
    char strings[N][MAX_LEN];

    input(strings);
    has_superstring(strings);

    return 0;
}