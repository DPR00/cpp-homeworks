#include "BowDictionary.hpp"

namespace ipb {

    int BowDictionary::size() const { return dict_size_; }

    Mat BowDictionary::vocabulary() const { return vocabulary_; }

    bool BowDictionary::empty() const {
        if (vocabulary_.rows == 0) return true;
        return false;
    }
    void BowDictionary::set_size(int size) { dict_size_ = size; }

    void BowDictionary::build(int max_iter,
                              int dict_size,
                              const vector<Mat> &descriptors) {
        set_size(dict_size);
        vocabulary_ = ipb::kMeans(descriptors, dict_size, max_iter);
    }

    void BowDictionary::set_vocabulary(Mat vocabulary) {
        set_size(vocabulary.rows);
        vocabulary_ = vocabulary;
    }

}  // namespace ipb