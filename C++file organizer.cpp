#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;

int count(string path) {
	int i = 0;
	for (const auto& file : fs::directory_iterator(path)) {
		i = i + 1;
	}
	return i;
}

int main() {
	string path;
	string dest;
	cout << "ENTER YOUR FOLDER PATH: \n";
	cin >> path;
	cout << "ENTER YOUR DESTINATION PATH: \n";
	cin >> dest;
	fs::path route = path;
	fs::path goal = dest;
	int num = count(path);
	string* array = new string[num];
	for (int i = 0; i < num;) {
		for (const auto& file : fs::directory_iterator(route))
		{
			if (fs::is_regular_file(file))
			{
				array[i] = file.path().filename().string();
				cout << array[i] << "\n";
				cout << " \n";
				i += 1;
			}

		}
		break;
	}


	for (int i = 0; i < num; i++) {
		fs::path file = route / array[i];
		fs::path folder = goal / fs::path(array[i]).stem();
		fs::create_directory(folder);
		fs::rename(file, folder / file.filename());
	}

}