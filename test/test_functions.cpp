/*
������ test_functions.cpp �������� ����������� �������,
������������ ��� ������������ ��������� "�������".
*/

#include <fstream>
#include <iostream>
#include "../src/functions.h"
#include "test_functions.h"

/**
 * ������� ���������� ��� ������� �� �����.
 * @param frs � snd - ������������ �������.
 */
void compare(std::vector<std::string>* frs, std::vector<std::string>* snd)
{
	if (frs->size() == snd->size())
	{
		// ���� ������� �������� ����������
		for (unsigned int i = 0; i < frs->size(); i++)
		{
			// ������������ �������� �������� � ����� � ��� �� ��������
			if (frs->at(i) != snd->at(i))
			{
				show_test_result(false);
				return;
			}
		}
		show_test_result(true);
	}
	else
	{
		// ���� ������� �������� ������������
		show_test_result(false);
	}
}

/**
 * ������� ������� �� ����� ��������� �����.
 * @param result - ��������, ���������� �� ��������� �����:
 * true, ���� ���� �������, false, ���� ���� ��������.
 */
void show_test_result(bool result)
{
	if (result)
	{
		std::cout << "\tfunction passed test.\n";
	}
	else
	{
		std::cout << "\tfunction failed test.\n";
	}
}

/**
 * ������� ��� ������������ ������� dismember_line().
 * @param test_num - ����� �����;
 * @param test_line - �������� ������ ��� �������� ������ �������
 * dismember_line();
 * @param test_words - ������ �������� ����, � �������� ����� ��������
 * ������ ����, ���������� �������� dismember_line() ��� ������ test_line.
 */
void test_dismember_line(int test_num, std::string* test_line,
	std::vector<std::string>* test_words)
{
	std::cout << "Test #" << test_num <<
		". Function under test is dismember_line():\n";

	std::vector<std::string> words; // ������ ��� ���� �� ������ test_line
	// ��������� ������� dismember_line()
	dismember_line(test_line, &words);
	// ���������� ��������� ������ dismember_line() � ���������� �����������
	compare(&words, test_words);
}

/**
 * ������� ��� ������������ ������� dismember_text().
 * @param test_num - ����� �����;
 * @param test_text - �������� ����� (������ �� �����) ��� �������� ������
 * ������� dismember_text();
 * @param test_words - ������ �������� ����, � �������� ����� ��������
 * ������ ����, ���������� �������� dismember_text() ��� ������ test_text.
 */
void test_dismember_text(int test_num, std::vector<std::string>* test_text,
	std::vector<std::string>* test_words)
{
	std::cout << "Test #" << test_num <<
		". Function under test is dismember_text():\n";

	std::vector<std::string> words; // ������ ��� ���� �� ������ test_text
	// ��������� ������� dismember_text()
	dismember_text(test_text, &words);
	// ���������� ��������� ������ dismember_text() � ���������� �����������
	compare(&words, test_words);
}

/**
 * ������� ��� ������������ ������� read_console().
 * @param test_num - ����� �����;
 * @param test_argc - ���������� ���������� � ��������� ������;
 * @param test_argv - �������� ������ �� �����-���������� ��������� ������;
 * @param test_text - �������� ������ �� �����, ������� ����� �������� �
 * �������� �� �����, ���������� ��� test_argv �������� read_console().
 */
void test_read_console(int test_num, int test_argc, char* test_argv[],
	std::vector<std::string>* test_text)
{
	std::cout << "Test #" << test_num << ". Test under test is read_console():\n";

	std::vector<std::string> text; // ������ ��� ����� �� ��������� ������
	if (test_argc < 2)
	{
		return;
	}
	// ��������� ������� read_console()
	read_console(test_argc, test_argv, &text);
	// ���������� ��������� ������ read_console() � ���������� �����������
	compare(&text, test_text);
}

/**
 * ������� ��� ������������ ������� read_file().
 * @param test_num - ����� �����;
 * @param test_argc - ���������� ���������� � ��������� ������;
 * @param test_argv - �������� ������ �� �����-���������� ��������� ������;
 * @param test_text - �������� ������ �� �����, ������� ����� �������� �
 * �������� �� �����, ���������� ��� test_argv �������� read_file().
 */
void test_read_file(int test_num, int test_argc, char* test_argv[],
	std::vector<std::string>* test_text)
{
	std::cout << "Test #" << test_num << ". Test under test is read_file():\n";

	// ������ ��� ����� �� ��������� ���������� �����
	std::vector<std::string> text;
	if (test_argc < 2)
	{
		return;
	}
	// ��������� ��������� ����
	std::ofstream out(test_argv[2]);
	if (!out.is_open())
	{
		return;
	}
	// ���� ��������� ���� ������, ���������� � ���� text
	for (unsigned int i = 0; i < test_text->size(); i++)
	{
		out << test_text->at(i) << "\n";
	}
	out.close();
	// ��������� ������� read_file()
	read_file(test_argc, test_argv, &text);
	// ���������� ��������� ������ read_file() � ���������� �����������
	compare(&text, test_text);
}

/**
 * ������� ��� ������������ ������� sort().
 * @param test_num - ����� �����;
 * @param test_words - �������� ������ �� ���� ��� �������� ������ �������
 * sort();
 * @param alphabet_words - ������ �� ���� � ���������� �������.
 */
void test_sort(int test_num, std::vector<std::string>* test_words,
	std::vector<std::string>* alphabet_words)
{
	std::cout << "Test #" << test_num << ". Function under test is sort():\n";

	// ��������� ������� sort()
	sort(test_words);
	// ���������� ��������� ������ sort() � ���������� �����������
	compare(test_words, alphabet_words);
}