# pcdloadmap
load PCD map from mapping


# Installation: 

1. Extract zip file into the catkin_ws/src
2. Load the read_pcd folder into catkin_ws/src
3. Do the catkin_make


# How to load the map: 

Put the map at /home/<username>/ with the name "map.pcd"
  
  ```
  roscore
  rosrun read_pcd read_pcd
  rosrun tf static_transform_publisher 0.0 0.0 0.0 0.0 0.0 0.0 map odom 100
  rosrun rviz rviz
  
  ```
  Next select the pointcloud file in the topic name in RVIZ. 
  
  For details, refer here:
  https://programmersought.com/article/29904905319/
  
