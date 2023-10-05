#include "BowDictionary.hpp"

namespace ipb
{
    int BowDictionary::max_iterations() const
    {
        return max_iter_;
    }

    int BowDictionary::size() const
    {
        return dict_size_;
    }

    vector<Mat> BowDictionary::descriptors() const
    {
        return in_descriptors_;
    }

    Mat BowDictionary::vocabulary() const
    {
        return codebook_;
    }

    int BowDictionary::total_features() const
    {
        int n_features = 0;
        for (const auto &element : in_descriptors_)
        {
            n_features += element.rows;
        }
        return n_features;
    }

    bool BowDictionary::empty() const
    {
        if (codebook_.rows == 0)
            return true;
        return false;
    }

    void BowDictionary::set_params(int max_iter, int dict_size, vector<Mat> &descriptors)
    {
        set_descriptors(descriptors);
        set_size(dict_size);
        set_max_iterations(max_iter);
        codebook_ = ipb::kMeans(in_descriptors_, dict_size, max_iter);
    }

    void BowDictionary::set_max_iterations(int iters)
    {
        max_iter_ = iters;
    }

    void BowDictionary::set_size(int size)
    {
        dict_size_ = size;
    }

    void BowDictionary::set_descriptors(vector<Mat> &descriptors)
    {
        in_descriptors_ = descriptors;
    }
}