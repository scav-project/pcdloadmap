// Author : Muhammad Aizzat Bin Zakaria (maizzat@ump.edu.my)
// pcd_conversions old package rename to pcl_conversions
// need to compile together with this: 
//https://github.com/ros-perception/perception_pcl/tree/melodic-devel
//Detail tutorials from here:
//https://programmersought.com/article/29904905319/
// but with slight modifications

#include<ros/ros.h>
#include<pcl/point_cloud.h>
#include<pcl_conversions/pcl_conversions.h>
#include<sensor_msgs/PointCloud2.h>
#include<pcl/io/pcd_io.h>//which contains the required definitions to load and store point clouds to PCD and other file formats.
 
main (int argc, char **argv)
{
  ros::init (argc, argv, "UandBdetect");
  ros::NodeHandle nh;
  ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("pcl_output", 1);
  pcl::PointCloud<pcl::PointXYZ> cloud;
  sensor_msgs::PointCloud2 output;
  pcl::io::loadPCDFile ("/home/aizzat/map.pcd", cloud); //Modify the path of your pcd file
  //Convert the cloud to ROS message
  pcl::toROSMsg(cloud, output);
  output.header.frame_id = "odom";//this has been done in order to be able to visualize our PointCloud2 message on the RViz visualizer    
//! ! ! This step needs attention, it is the fixed_frame of rviz behind!!! Knock the blackboard and draw the key points.
  ros::Rate loop_rate(1);
  while (ros::ok())
  {
    pcl_pub.publish(output);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}