/**
 * @project_name Project
 * @file img_pub.cpp
 * @brief
 * @author yx
 * @data 2023-12-05 20:10:04
 */

#include <img_pub/img_show.h>

ImageShow::ImageShow()
    : m_image_transport(m_node_handle) {
    m_subscriber = m_image_transport.subscribe("/img_data", 1,  &ImageShow::imgShow, this);
}

void ImageShow::imgShow(const sensor_msgs::ImageConstPtr& img_msg) {
    cv_bridge::CvImagePtr cv_image_ptr;
    cv_image_ptr = cv_bridge::toCvCopy(img_msg, sensor_msgs::image_encodings::BGR8);
    std::vector<int> params { cv::IMWRITE_PNG_COMPRESSION };
    uint64_t timestamp = cv_image_ptr->header.stamp.toNSec();
//    auto timestamp_sec = static_cast<double>(timestamp);
    std::string filename = std::to_string(timestamp) + ".png";
    ROS_INFO("filename: %s", filename.c_str());
    cv::imwrite(filename, cv_image_ptr->image, params);
    cv::imshow("frame-show", cv_image_ptr->image);
    cv::waitKey(1);
}
