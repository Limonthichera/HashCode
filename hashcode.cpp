#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream input;
    string filename;
    cin >> filename;
    string path = "./input/" + filename;
    input.open(path);

    int numberOfPhotos, numberOfTags;
    vector<string> tags;
    string tag;
    string type;

    if (!input) {
        cerr << "Unable to open file";
        exit(1);   // call system to stop
    }

    input >> numberOfPhotos;
    cout << numberOfPhotos << "\n";

    for (int i = 0; i < numberOfPhotos; ++i) {
        input >> type;
        cout << type << " ";
        input >> numberOfTags;
        cout << numberOfTags << " ";
        for (int i = 0; i < numberOfTags; ++i) {
            input >> tag;
            cout << tag << " ";
            tags.push_back(tag);
        }
        cout << "\n";
    }
}