#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class File {
public:
    vector<string> read(string file) {
        ifstream file_in(file);
        string file_content;
        vector<string> final_contents;

        while (getline(file_in, file_content)) {
            final_contents.push_back(file_content + "\n");
        }

        return final_contents;
    }

    bool write(string file, vector<string> content) {
        ofstream file_out(file);
        for (int i = 0; i < content.size(); i++) {
            file_out << content[i] << "\n";
        }
        file_out << endl;
        return true;
    }

    bool copy(string file_in, string file_out) {
        vector<string> file_A = this->read(file_in);
        this->write(file_out, file_A);
        return true;
    }
};

int main() {
    string file_path = "testing_cpp2.txt";

    File file;
    file.copy("testing_cpp2.txt", "testing_cpp3.txt");

    cout << "Done" << endl;
}
