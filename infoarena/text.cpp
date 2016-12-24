#include <fstream>

using namespace std;

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
	long length;
	char* buffer;
	ifstream f("text.in");
	long numCuv = 0;
	long long numLit = 0;
	long long current;

	// get file size
	f.seekg(0, f.end);
	length = f.tellg();
	f.seekg(0, f.beg);

	// allocate memory
	buffer = new char[length + 1];

	// read block of data
	f.read(buffer, length);

	// close input stram
	f.close();

	// parse the buffer + count
	current = 0;
	for (long i = 0; i < length; i++) {
		if (isLetter(buffer[i])) {
			current++;
		}
		else if (current > 0) {
			numCuv += 1;
			numLit += current;
			current = 0;
		}
	}
	if (current > 0) {
		numCuv += 1;
		numLit += current;
	}

	// free memory;
	delete[] buffer;

	// output result
	ofstream g("text.out");
	if (numCuv > 0) {
		g << static_cast<long>(numLit / numCuv) << "\n";
	}
	g.close();

	return 0;
}
