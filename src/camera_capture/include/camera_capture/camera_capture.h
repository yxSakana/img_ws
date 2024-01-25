/**
 * @project_name Project
 * @file camera_capture.h
 * @brief
 * @author yx
 * @data 2023-12-05 20:48:22
 */

#ifndef SRC_CAMERA_CAPTURE_H
#define SRC_CAMERA_CAPTURE_H

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <HikDriver/HikDriver.h>

class CameraCapture {
public:
    CameraCapture();
    void publishImage();
    inline bool ok() const { return m_node_handle.ok(); }
private:
    ros::NodeHandle m_node_handle;
    image_transport::ImageTransport m_image_transport;
    image_transport::Publisher m_publisher;
    HikFrame m_frame;
    HikDriver m_hik_driver;
};

#endif //SRC_CAMERA_CAPTURE_H
