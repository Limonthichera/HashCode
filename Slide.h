using namespace std;

#include <vector>
#include <string>
#include "Photo.h"

class Slide {
    public:
    vector<string> tags; // slide tags
    char photoType; // H or V (Horisontal or Vertical)

    Photo photo1; // This will always have a photo in it
    Photo photo2; // This will only have a photo when photoType = 'V'
    
    // if photoType == 'V', photo2 will be ignored. Reccomandation - send null.
    Slide(char photoType, Photo & photo1, Photo & photo2);
};