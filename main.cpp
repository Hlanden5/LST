// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <numeric>

using namespace std;

string serialaze(vector<int>& numbers);
string checkNum(string& num_str);
string deserialaze(string serialized);

int main() {
	vector<float> percentages;
	// Простейшие короткие
	vector<int> numbers1{ 1, 2, 3, 4, 5 };
	string ser_str1{ serialaze(numbers1) };
	string desser_str1{ deserialaze(ser_str1) };
	cout << "Serialazed str:" << ser_str1 << "\n" << "Size:" << ser_str1.size() << endl;
	cout << "Deserialazed str:" << desser_str1 << "\n" << "Size:" << desser_str1.size() << endl;
	percentages.push_back(float(ser_str1.size()) / float(desser_str1.size()) * 100);
	cout << float(ser_str1.size()) / float(desser_str1.size()) * 100 << "%" << endl;

	// Случайные - 50 чисел
	vector<int> numbers2(50);
	generate(numbers2.begin(), numbers2.end(), rand);
	string ser_str2{ serialaze(numbers2) };
	string desser_str2{ deserialaze(ser_str2) };
	cout << "Serialazed str:" << ser_str2 << "\n" << "Size:" << ser_str2.size() << endl;
	cout << "Deserialazed str:" << desser_str2 << "\n" << "Size:" << desser_str2.size() << endl;
	cout << float(ser_str2.size()) / float(desser_str2.size()) * 100 << "%" << endl;

	// Случайные - 100 чисел
	vector<int> numbers3(100);
	generate(numbers3.begin(), numbers3.end(), rand);
	string ser_str3{ serialaze(numbers3) };
	string desser_str3{ deserialaze(ser_str3) };
	cout << "Serialazed str:" << ser_str3 << "\n" << "Size:" << ser_str3.size() << endl;
	cout << "Deserialazed str:" << desser_str3 << "\n" << "Size:" << desser_str3.size() << endl;
	cout << float(ser_str3.size()) / float(desser_str3.size()) * 100 << "%" << endl;

	// Случайные - 500 чисел
	vector<int> numbers4(500);
	generate(numbers4.begin(), numbers4.end(), rand);
	string ser_str4{ serialaze(numbers4) };
	string desser_str4{ deserialaze(ser_str4) };
	cout << "Serialazed str:" << ser_str4 << "\n" << "Size:" << ser_str4.size() << endl;
	cout << "Deserialazed str:" << desser_str4 << "\n" << "Size:" << desser_str4.size() << endl;
	cout << float(ser_str4.size()) / float(desser_str4.size()) * 100 << "%" << endl;

	// Случайные - 1000 чисел
	vector<int> numbers5(1000);
	generate(numbers5.begin(), numbers5.end(), rand);
	string ser_str5{ serialaze(numbers5) };
	string desser_str5{ deserialaze(ser_str5) };
	cout << "Serialazed str:" << ser_str5 << "\n" << "Size:" << ser_str5.size() << endl;
	cout << "Deserialazed str:" << desser_str5 << "\n" << "Size:" << desser_str5.size() << endl;
	cout << float(ser_str5.size()) / float(desser_str5.size()) * 100 << "%" << endl;

	// Граничные - все числа 1 знака
	vector<int> numbers6{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string ser_str6{ serialaze(numbers6) };
	string desser_str6{ deserialaze(ser_str6) };
	// cout << "Serialazed str:" << ser_str6 << "\n" << "Size:" << ser_str6.size() << endl;
	cout << "Deserialazed str:" << desser_str6 << "\n" << "Size:" << desser_str6.size() << endl;
	cout << float(ser_str6.size()) / float(desser_str6.size()) * 100 << "%" << endl;

	// Граничные - все числа из 2х знаков
	vector<int> numbers7;
	for (int i = 10; i < 100; ++i) {
		numbers7.push_back(i);
	}
	string ser_str7{ serialaze(numbers7) };
	string desser_str7{ deserialaze(ser_str7) };
	// cout << "Serialazed str:" << ser_str7 << "\n" << "Size:" << ser_str7.size() << endl;
	cout << "Deserialazed str:" << desser_str7 << "\n" << "Size:" << desser_str7.size() << endl;
	cout << float(ser_str7.size()) / float(desser_str7.size()) * 100 << "%" << endl;

	// Граничные - все числа из 3х знаков
	vector<int> numbers8;
	for (int i = 100; i < 1000; ++i) {
		numbers8.push_back(i);
	}
	string ser_str8{ serialaze(numbers8) };
	string desser_str8{ deserialaze(ser_str8) };
	// cout << "Serialazed str:" << ser_str8 << "\n" << "Size:" << ser_str8.size() << endl;
	cout << "Deserialazed str:" << desser_str8 << "\n" << "Size:" << desser_str8.size() << endl;
	cout << float(ser_str8.size()) / float(desser_str8.size()) * 100 << "%" << endl;

	// Каждого числа по 3 - всего чисел 900
	vector<int> numbers9;
	for (int i = 0; i < 300; ++i) {
		numbers9.push_back(i);
		numbers9.push_back(i);
		numbers9.push_back(i);
	}
	string ser_str9{ serialaze(numbers9) };
	string desser_str9{ deserialaze(ser_str9) };
	cout << "Serialazed str:" << ser_str9 << "\n" << "Size:" << ser_str9.size() << endl;
	// cout << "Deserialazed str:" << desser_str9 << "\n" << "Size:" << desser_str9.size() << endl;
	cout << float(ser_str9.size()) / float(desser_str9.size()) * 100 << "%" << endl;

	percentages.push_back(float(ser_str1.size()) / float(desser_str1.size()) * 100);
	percentages.push_back(float(ser_str2.size()) / float(desser_str2.size()) * 100);
	percentages.push_back(float(ser_str3.size()) / float(desser_str3.size()) * 100);
	percentages.push_back(float(ser_str4.size()) / float(desser_str4.size()) * 100);
	percentages.push_back(float(ser_str5.size()) / float(desser_str5.size()) * 100);
	percentages.push_back(float(ser_str6.size()) / float(desser_str6.size()) * 100);
	percentages.push_back(float(ser_str7.size()) / float(desser_str7.size()) * 100);
	percentages.push_back(float(ser_str8.size()) / float(desser_str8.size()) * 100);
	percentages.push_back(float(ser_str9.size()) / float(desser_str9.size()) * 100);

	float sum = accumulate(percentages.begin(), percentages.end(), 0.0);
	float mean = sum / percentages.size();

	cout << "Average: " << mean << "%" << endl;
}

std::string checkNum(std::string& num_str)
{
	std::string result = "";

	for (size_t i = 0; i < num_str.size(); i += 2)
	{
		std::string two_chars = num_str.substr(i, 2);
		char* output;
		std::bitset<16> b(strtol(two_chars.c_str(), &output, 10));
		if (b[15] == 0 and b[14] == 0 and b[13] == 0 and b[12] == 0 and
			b[11] == 0 and b[10] == 0 and b[9] == 0 and b[8] == 0 and
			b[7] == 0 and b[6] == 0 and b[5] == 0 and b[4] == 0 and
			(b[3] + b[2] + b[1] + b[0] < 4)) {
			result += b.to_string().substr(12);
		}
		else {
			for (char c : two_chars)
			{
				std::bitset<8> k(c - '0');
				result += k.to_string().substr(4);
			}
		}

	}
	//cout << num_str << "\t" << result << endl;
	return result;
}

std::string bitStringToAscii(std::string bitString)
{
	std::string asciiString = "";
	for (size_t i = 0; i < bitString.size(); i += 8)
	{
		std::bitset<8> bits(bitString.substr(i, 8));
		asciiString += static_cast<char>(bits.to_ulong());
	}
	return asciiString;
}

string serialaze(vector<int>& numbers) {
	string result;
	for (auto& num : numbers) {
		string num_str{ to_string(num) };
		result += checkNum(num_str) + "1111";
	}
	if (result.size() % 8 != 0) {
		result = "1111" + result;
	}
	return bitStringToAscii(result);
}

string deserialaze(string serialized) {
	string bitString;
	string result_str;
	string result_now;

	for (char c : serialized)
	{
		std::bitset<8> bits(c);
		bitString += bits.to_string();
	}

	if (bitString.substr(0, 4) == "1111") {
		bitString = bitString.substr(4);
	}

	for (size_t i = 0; i < bitString.size() + 1; i += 4) {
		string tmp{ bitString.substr(i, 4) };
		if (tmp == "1111") {
			char* output;
			result_str += result_now + ",";
			result_now.clear();
		}
		else {
			bitset<8> num{ tmp };
			result_now += to_string(num.to_ullong());
		}
	}
	result_str.resize(result_str.size() - 1);
	return result_str;
}
