#include <iostream> 
#include <cstring>
bool is_right(size_t, size_t, char*&);
bool is_punk_mark(char);
int main() {
	const int32_t MAX_SIZE = 300;
	char* str = new char[MAX_SIZE];
	std::cout << "Enter your string" << std::endl;
	std::cin.getline(str, MAX_SIZE);
	if (str[0] == '\0') {
		std::cout << "String is empty";
		delete[] str;
		return 0;
	}
	char* t = new char[MAX_SIZE];
	t[0] = '\0';
	size_t start = 0;
	size_t end = 0;
	size_t word_size = 0;
	size_t max_length = 0;
	size_t size = strlen(str);
	for (size_t i = 0; i < size;) {
		if (is_punk_mark(str[i]) == 0) {
			start = i;
			while (is_punk_mark(str[i]) == 0) {
				i++;
			}
			end = i;
			word_size = end - start;
			if (is_right(start, end, str) == 1 && word_size > max_length) {
				max_length = word_size;
			}
		}
		else i++;
	}
	if (max_length == 0) {
		std::cout << "No words in string";
		delete[] str;
		delete[] t;
		return 0;
	}
	for (size_t j = 0; j < size;) {
		if (is_punk_mark(str[j]) == 0) {
			start = j;
			while (is_punk_mark(str[j]) == 0) {
				j++;
			}
			end = j;
			word_size = end - start;
			if (word_size == max_length && is_right(start, end, str) == 1) {
				for (size_t temp = start; temp < end; temp++) {
					char temp_char[2];
					temp_char[0] = str[temp];
					temp_char[1] = '\0';
					strcat_s(t, MAX_SIZE, temp_char);
				}
				strcat_s(t, MAX_SIZE, " ");
			}

		}
		else j++;
	}
	size_t size2 = strlen(t);
	for (size_t k = 0; k < size2; k++) {
		std::cout << t[k];
	}
	delete[] t;
	delete[] str;
	return 0;
}

bool is_right(size_t start, size_t end, char*& str) {
	for (size_t i = start; i < end - 1; i++) {
		if (str[i] >= str[i + 1]) {
			return false;
		}
	}
	return true;
}
bool is_punk_mark(char sym) {
	if (sym >= 'a' && sym <= 'z') { return false; }
	if (sym >= 'A' && sym <= 'Z') { return false; }
	if (sym >= '0' && sym <= '9') { return false; }
	else return true;
}