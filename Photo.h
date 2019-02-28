class Photo {
    public:
    vector<string> tags;
    char type; // H or V (Horisontal or Vertical)

    Photo(vector<string> tagList, char type);
    vector<string> getIntersection(Photo photo);

};