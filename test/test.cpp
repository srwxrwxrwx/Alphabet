/*
������ test.cpp �������� ����� ��� ���������� "�������".
*/

#include <iostream>
#include "../src/functions.h"
#include "test_functions.h"

int main(int argc, char* argv[])
{
	int test_num = 0; // ����� �����

	// ���� 1. ����������� ������� dismember_line().
	// �������� ������
	std::string line("My name! ,is -Timerke., I\tam from?\"Novocheboksarsk\"");
	// ������ �� ����, ������� ������ ���� ���������� �������� dismember_line()
	std::vector<std::string> words = { "My", "name", "is", "Timerke", "I", "am",
		"from", "Novocheboksarsk" };
	test_dismember_line(++test_num, &line, &words);

	// ���� 2. ����������� ������� dismember_line().
	// �������� ������
	line = ". !\t?";
	// ������ �� ����, ������� ������ ���� ���������� �������� dismember_line()
	words.clear();
	test_dismember_line(++test_num, &line, &words);

	// ���� 3. ����������� ������� dismember_line().
	// �������� ������
	line = "0.783%, 732 ������ � -903 �������.";
	// ������ �� ����, ������� ������ ���� ���������� �������� dismember_line()
	words = { "0", "783%", "732", "������", "�", "903", "�������" };
	test_dismember_line(++test_num, &line, &words);

	// ���� 4. ����������� ������� dismember_text().
	// �������� �����
	std::vector<std::string> text = { "My name! ,is -Timerke., I\tam from?\"Moscow\"",
		". !\t?",
		"0.783%, 732 ������ � -903 �������." };
	// ������ �� ����, ������� ������ ���� ���������� �������� dismember_text()
	words = { "My", "name", "is", "Timerke", "I", "am", "from", "Moscow", "0",
		"783%", "732", "������", "�", "903", "�������" };
	test_dismember_text(++test_num, &text, &words);

	// ���� 5. ����������� ������� read_console().
	// ���������� ����������, ������������ ����� �������� ��������� ������
	int argc_ = 7;
	// �������� ��������� ������
	const char* argv_1[] = { "c:\\main.cpp", "2", "dog,cat", "�������", "728.90",
		"��������������.", "Hot-dog" };
	// ������ �� �����, ������� ������ ���� ���������� �������� read_console()
	words = { "dog,cat", "�������", "728.90", "��������������.", "Hot-dog" };
	test_read_console(++test_num, argc_, (char**)argv_1, &words);

	// ���� 6. ����������� ������� read_file().
	// ���� � �����, � ������� ����� ������� ����� text
	const char* file_path = "test_file.txt";
	text = { "������ ����� ��������", "� ������ ���� �������.",
		"��� ���� �� � ������ �������?", "��� ����� �� � ���� ������?" };
	// ���������� ����������, ������������ ����� �������� ��������� ������
	argc_ = 3;
	// �������� ��������� ������
	const char* argv_2[] = { "c:\\main.cpp", "1", file_path };
	test_read_file(++test_num, argc_, (char**)argv_2, &text);

	// ���� 7. ����������� ������� sort().
	// �������� ������ �� ����
	words = { "yellow", "cat", "���������", "1991", "������","dragon" };
	// ������ �� �������� ���� �� ��������
	std::vector<std::string> alphabet_words = { "1991", "cat", "dragon",
		"yellow", "���������", "������" };
	test_sort(++test_num, &words, &alphabet_words);

	return 0;
}