#include<stdio.h>
int romanValues(char s);
int romanToInt(char* s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i += 1) {
        if (romanValues(s[i]) >= romanValues(s[i + 1])) {
            result += romanValues(s[i]);
        }
        else {
            result -= romanValues(s[i]);
        }
    }
    return result;
}
int romanValues(char s) {
    if (s == 'I')
    {
        return 1;
    }
    if (s == 'V')
    {
        return 5;
    }
    if (s == 'X')
    {
        return 10;
    }
    if (s == 'L')
    {
        return 50;
    }
    if (s == 'C')
    {
        return 100;
    }
    if (s == 'D')
    {
        return 500;
    }
    if (s == 'M')
    {
        return 1000;
    }
    return 0;
}
int main() {
    char s[20] = "MCMXCIV";
    printf("%d",romanToInt(s));
}