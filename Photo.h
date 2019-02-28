#include <vector>
#include <string>
using namespace std;

class Photo {
    public:
    vector<string> tags;
    char type; // H or V (Horisontal or Vertical)

    Photo(vector<string> tagList, char type);
    Photo();
    vector<string> getIntersection(Photo photo);
    vector<string> getReunion(Photo photo);

};