#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Photo.h"
using namespace std;

int main(int argc, char* argv[]) {
    ifstream input;
    string filename;
    cin >> filename;
    string path = "./input/" + filename;
    
    input.open(path);
    if (!input) {
        cerr << "Unable to open file";
        exit(1);   // call system to stop
    }

    int numberOfPhotos, numberOfTags;
    vector<string> tags;
    string tag;
    string type;

    input >> numberOfPhotos;

    vector<Photo> photos;

    for (int i = 0; i < numberOfPhotos; ++i) {
        // Read type (H - horizontal or V - vertical)
        input >> type;
        cout << type <<" "; 
        input >> numberOfTags;
        cout << numberOfTags << " ";
        
        // Read tags
        for (int i = 0; i < numberOfTags; ++i) {
            input >> tag;
            cout << tag << " ";
            tags.push_back(tag);
        }
        cout << "\n";
        
        Photo photo(tags, type[0]);
        photos.push_back(photo);
        tags.clear();
    }
    
    for (int i = 0; i < numberOfPhotos; ++i) {
        cout << photos[i].type;
        for (unsigned int j = 0; j < photos[i].tags.size(); ++j) {
            cout << photos[i].tags[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}