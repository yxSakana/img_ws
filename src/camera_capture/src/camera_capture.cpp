/**
 * @project_name Project
 * @file camera_capture.cpp
 * @brief
 * @author yx
 * @data 2023-12-05 20:48:41
 */

#include <camera_capture/camera_capture.h>
#include <HikDriver/HikDriver.h>

CameraCapture::CameraCapture()
    : m_image_transport(m_node_handle),
      m_publisher(m_image_transport.advertise("/img_data", 1)),
      m_hik_driver(0) {
    if (m_hik_driver.isConnected()) {
        ROS_INFO("Hik Camera connect!");
        m_hik_driver.setExposureTime(30000);
        m_hik_driver.setGain(10);
        m_hik_driver.showParamInfo();
        m_hik_driver.startReadThread();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } else {
        ROS_ERROR("Failed: to connect hik camera!");
    }
}

void CameraCapture::publishImage() {
    if (m_hik_driver.isConnected()) {
        m_hik_driver.getFrame(m_frame);
        sensor_msgs::ImagePtr img_msg =
                cv_bridge::CvImage(std_msgs::Header(), "bgr8", *m_frame.getRgbFrame()).toImageMsg();
        img_msg->header.stamp = ros::Time::now();
        ROS_INFO("timestamp: %lu", img_msg->header.stamp.toNSec());
        m_publisher.publish(img_msg);
    }
}
