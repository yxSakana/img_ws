#include <ros/ros.h>

#include <img_pub/img_show.h>

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "img_show");
    ImageShow image_show;

    ros::spin();

    return 0;
}
