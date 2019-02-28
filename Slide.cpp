#include "Slide.h"

Slide::Slide(char photoType, Photo & photo1, Photo & photo2) {
    // This is added regardless of the photo type
    this->photo1 = photo1;

    if (photoType == 'H') {
        this->photoType = 'H';

        tags.reserve(photo1.tags.size());

        // Add photo tags to slide
        for (unsigned int i = 0; i < photo1.tags.size(); i++) {
            tags[i] = photo1.tags.at(i);
        }
    }

    if (photoType == 'V') {
        this->photoType = 'V';
        this->photo2 = photo2;

        // Add all tags in photos without duplicates
        tags = photo1.getReunion(photo2);
    }
}