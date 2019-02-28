#include <stdlib.h>
#include <algorithm>

#include "Photo.h"

Photo::Photo() {
    ;
}

Photo::Photo(vector<string> tagList, char type) {
    tags.reserve(tagList.size());
    this->type = type;

    // Saving tags in internal storage
    for (unsigned int i = 0; i < tagList.size(); i++) {
        tags[i] = tagList[i];
    }

    // Sorting tags on insertion for faster searches
    sort(tags.begin(), tags.end());
}

// Get the common tags between this photo and photo received in parameter
vector<string> Photo::getIntersection(Photo photo) {
    vector<string> commonTags;
    commonTags.reserve(1);

    unsigned int thisIdx = 0, otherIdx = 0;

    // Compare in a similar fashion to merge() of Merge Sort

    for (unsigned int i = 0; i < tags.size() + photo.tags.size() - 1; i++) {
        // Common element
        int compareResult = tags.at(thisIdx).compare(photo.tags.at(otherIdx));

        if (!compareResult) {
            // Avoid overflowing the vector
            if (commonTags.size() == commonTags.capacity()) {
                commonTags.resize(commonTags.capacity() * 2);
            }
            commonTags.push_back(tags.at(thisIdx));
            i++;
            thisIdx++;
            otherIdx++;
            continue;
        }

        // Element in this > Element in other
        if (compareResult > 0) {
            // increment tag idx from other photo
            otherIdx++;
            continue;
        }

        // Element in this < Element in other
        // here compareResult surely is < 0
        thisIdx++;
        continue;
    }

    return commonTags;
}

// Get the all tags of this photo and received photo
vector<string> Photo::getReunion(Photo photo) {
    vector<string> reunionTags;
    reunionTags.reserve(1);

    unsigned int thisIdx = 0, otherIdx = 0;

    // Compare in a similar fashion to merge() of Merge Sort

    for (unsigned int i = 0; i < tags.size() + photo.tags.size() - 1; i++) {
        // Common element
        int compareResult = tags.at(thisIdx).compare(photo.tags.at(otherIdx));

        if (!compareResult) {
            // Avoid overflowing the vector
            if (reunionTags.size() == reunionTags.capacity()) {
                reunionTags.resize(reunionTags.capacity() * 2);
            }
            reunionTags.push_back(tags.at(thisIdx));
            i++;
            thisIdx++;
            otherIdx++;
            continue;
        }

        // Element in this > Element in other
        if (compareResult > 0) {
            // add tag in other photo and increment tag idx
            reunionTags.push_back(photo.tags.at(otherIdx));
            otherIdx++;
            continue;
        }

        // Element in this < Element in other
        // here compareResult surely is < 0
        // add tag in this photo and increment tag idx
        reunionTags.push_back(tags.at(thisIdx));
        thisIdx++;
        continue;
    }

    return reunionTags;
}