#include "kmeans.hpp"

namespace ipb
{
    float euclideanDistance(const Mat &centroid, const Mat &descriptor)
    {
        return cv::norm(centroid, descriptor, cv::NORM_L2);
    }

    vector<Mat> initializeClusters(const vector<Mat> &descriptors, int k)
    {
        vector<Mat> centroids;
        centroids.reserve(k);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, descriptors.size() - 1);

        for (int i = 0; i < k; i++)
        {
            int index = distribution(gen);
            centroids.push_back(descriptors[index].clone());
        }

        return centroids;
    }

    void assignDescriptors(map<int, vector<Mat>> &idC_descriptors, vector<Mat> &centroids,
                           vector<Mat> &descriptors)
    {
        for (const auto &descriptor : descriptors)
        {
            float dist_min = std::numeric_limits<float>::max();
            int id_init = -1;
            for (int id = 0; id < centroids.size(); id++)
            {
                Mat centroid = centroids[id];
                float dist = euclideanDistance(centroid, descriptor);
                if (dist - dist_min < 0.01)
                {
                    dist_min = dist;
                    id_init = id;
                }
            }
            idC_descriptors[id_init].emplace_back(descriptor);
        }
    }

    void recomputeCentroids(vector<Mat> &centroids,
                            const map<int, vector<Mat>> &idC_descriptors)
    {

        for (const auto &element : idC_descriptors)
        {
            Mat desc = element.second[0];
            Mat mean_centroid = Mat::zeros(desc.rows, desc.cols, desc.type());
            for (const auto &descriptor : element.second)
            {
                mean_centroid += descriptor;
            }
            mean_centroid /= static_cast<float>(element.second.size());
            centroids[element.first] = mean_centroid;
        }
    }

    Mat kMeans(const vector<Mat> &descriptors, int k, int max_iter)
    {
        // 1. Given cluster centroids i initialized in some way,
        vector<Mat> descriptors_d;
        descriptors_d.reserve(descriptors.size());
        for (const auto &descriptor : descriptors)
        {
            Mat desc;
            descriptor.convertTo(desc, CV_32FC1);
            descriptors_d.emplace_back(desc);
        }

        vector<Mat> centroids;
        centroids = initializeClusters(descriptors_d, k);
        // 2. For iteration t = 1..T :
        for (size_t i = 0; i < max_iter; i++)
        {
            map<int, vector<Mat>> idC_descriptors;
            assignDescriptors(idC_descriptors, centroids, descriptors_d);
            recomputeCentroids(centroids, idC_descriptors);
        }

        Mat stack_centroids;
        cv::vconcat(centroids, stack_centroids);

        return stack_centroids;
    }
}