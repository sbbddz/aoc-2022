#include <iterator>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>
#include <iostream>
#include <fstream>

void print_map(const std::map<std::string, int>& map) 
{
	for (const auto& value : map)
	{
		std::cout << value.first << "  --  " << value.second << std::endl;
	}
}

// Stackoverflow
std::string join(const std::vector<std::string>& vec, const char* delim)
{
	std::stringstream res;
	copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(res, delim));
	return res.str();
}

int main(void)
{
	std::map<std::string, int> dir_tree;
	std::vector<std::string> curr_directory;

	std::ifstream input_file("input.txt");
	assert(input_file);

	while (input_file)
	{
		std::string file_command;
		std::getline(input_file, file_command);
		std::string command_action = file_command.substr(0, 4);

		if (command_action == "$ cd") {
			if (file_command == "$ cd ..") {
				curr_directory.pop_back();
			} else {
				curr_directory.push_back(file_command.substr(5));
			}
		} else if (command_action == "$ ls" || command_action == "dir ") {
			continue;
		} else {
			auto work_directory = curr_directory;

			if (file_command == "") 
				continue;
			std::stringstream ss(file_command);
			std::istream_iterator<std::string> begin(ss);
			std::istream_iterator<std::string> end;
			std::vector<std::string> splitted_string(begin, end);
			std::string string_to_parse = splitted_string.at(0);
			int size = std::stoi(string_to_parse);

			for (int i = 0; i < curr_directory.size(); ++i)
			{
				std::string dir = join(work_directory, "/");
				dir_tree[dir] += size;
				work_directory.pop_back();
			}
		}

	}

	int total_sum = 0;
	int total_space = 70000000;
	int update_size = 30000000;
	int possible_option = total_space;
	int root_size = dir_tree["//"];
	int avaliable_space = total_space - root_size;
	int required_size = update_size - avaliable_space;
	for (const auto& a : dir_tree) 
	{
		if (a.second <= 100000) {
			total_sum += a.second;
		}

		if (a.second > required_size && a.second < possible_option) {
			possible_option = a.second;
		}
	}
	std::cout << total_sum << std::endl;
	std::cout << required_size << std::endl;
	std::cout << possible_option << std::endl;
}
