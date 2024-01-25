/**
 * @project_name Project
 * @file main.cpp
 * @brief
 * @author yx
 * @data 2023-12-05 21:00:42
 */

#include <ros/ros.h>

#include <google_logger/google_logger.h>
#include <camera_capture/camera_capture.h>

int main(int argc, char* argv[]) {
    armor_auto_aim::google_log::initGoogleLogger(argc, argv);
    ros::init(argc, argv, "video_capture");
    CameraCapture camera_capture;

    ros::Rate loop_rate(20);
    while (camera_capture.ok()) {
        camera_capture.publishImage();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
