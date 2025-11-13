// Copyright 2020 Joe. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.
#include <string_view>
#include <filesystem>
#include <fstream>
#include <vector>
#include <set>


void DisplayFile(char* src, int size);
void DisplayCXXFile(char* src, int size);

int main(int argc, char** argv) {
	using path = std::filesystem::path;
	// Var
	path file_path;
	std::fstream file;

	// WINDOW* cwindow;
	// SCREEN* cscreen;
	// Whether or not the file should use C++ syntax highlighting.
	bool cxx_mode = false;

	// Const
	static const std::set<std::string_view> cxx_extension_names {
		".cc",
		".cpp",
		".cxx",
		".c++"
	};
	
	// Begin
	if (argc < 2) {
		fprintf(stderr, "Missing file path argument.\n");
		return 1;
	} // Extra arguments are ignored.

	file_path = path(argv[1]);
	
	const auto& path_str = file_path.u8string();
	const auto& ext_str  = file_path.extension().u8string(); 

	if (std::filesystem::exists(file_path) == false) {
		fprintf(stderr, "File %s does not exist.\n", path_str.c_str());
		return 1;
	}
	
	file.open(file_path);

	fprintf(stderr, "Missing file path argument.\n");
	return 0;
}// end main
