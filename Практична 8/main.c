#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <string.h>
int factorial(int n) {
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}
int count_anagrams(char* word) {
	int len = strlen(word);
	int freq[26] = { 0 };
	int denominator = 1;
	for (int i = 0; i < len; ++i) {
		freq[word[i] - 'A']++;
	}
	for (int i = 0; i < 26; ++i) {
		if (freq[i] > 0) {
			denominator *= factorial(freq[i]);
		}
	}
	int numerator = factorial(len);
	int result = numerator / denominator;
	return result;
}
int main() {
	setlocale(LC_ALL, "Ukr");
	char word[15];
	printf("Введiть слово: ");
	scanf("%s", word);

	int anagram_count = count_anagrams(word);
	printf("Кiлькiсть анаграм для слова \"%s\": %d\n", word, anagram_count);
	return 0;
}