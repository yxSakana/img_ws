/**
 * @project_name Project
 * @file img_pub.h
 * @brief
 * @author yx
 * @data 2023-12-05 20:10:38
 */

#ifndef SRC_IMG_SHOW_H
#define SRC_IMG_SHOW_H

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

class ImageShow {
public:
    ImageShow();
private:
    ros::NodeHandle m_node_handle;
    image_transport::ImageTransport m_image_transport;
    image_transport::Subscriber m_subscriber;
    cv::Mat m_frame;

    void imgShow(const sensor_msgs::ImageConstPtr& img_msg);
};

#endif //SRC_IMG_SHOW_H
