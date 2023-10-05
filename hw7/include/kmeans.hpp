#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <limits>
#include <cmath>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/mat.hpp>

using cv::Mat;
using std::cout;
using std::endl;
using std::map;
using std::vector;

namespace ipb
{
    /**
     * @brief
     * Calculate the euclidean distance between a centroid and a descriptor.
     * Using NORM_L2 from OpenCV
     *
     * @param centroid The imput centroid (cv::Mat)
     * @param descriptor The input descriptor (cv::Mat)
     *
     * @return float distance
     */
    float euclideanDistance(const Mat &centroid, const Mat &descriptor);

    /**
     * @brief
     * Initialize $k$ clusters chosen randomly from descriptors.
     *
     * @param descriptors Vector of descriptors
     * @param k Number of clusters
     *
     * @return The chosen clusters grouped in a vector
     */
    void assignDescriptors(vector<Mat> &centroids, vector<Mat> &descriptors);

    void recomputeCentroids(vector<Mat> &centroids, map<int, const vector<Mat>> &idC_descriptors);

    /**
     * @brief
     * 1. Given cluster centroids i initialized in some way,
     * 2. For iteration t=1..T:
     * 1. Compute the distance from each point x to each cluster centroid ,
     * 2. Assign each point to the centroid it is closest to,
     * 3. Recompute each centroid as the mean of all points assigned to it,
     *
     * @param descriptors The input SIFT descriptors to cluster.
     * @param k The size of the dictionary, ie, number of visual words.
     * @param max_iterations Maximum number of iterations before convergence.
     *
     * @return cv::Mat One unique Matrix representing all the $k$-means(stacked).
     */
    Mat kMeans(const vector<Mat> &descriptors, int k, int max_iter);
}
