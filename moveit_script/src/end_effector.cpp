#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"

// Main moveit libraries are included
int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_pub");
  ros::NodeHandle node_handle;
  ros::Publisher pub = node_handle.advertise<std_msgs::Float64MultiArray>("end_effector",1000);    //publish to topic "end_effector"
  ros::AsyncSpinner spinner(0);
  spinner.start(); // For moveit implementation we need AsyncSpinner, we cant use ros::spinOnce()
  static const std::string PLANNING_GROUP = "group1"; /* Now we specify with what group we want work,
  here group1 is the name of my group controller*/
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP); // loading move_group
  const robot_state::JointModelGroup *joint_model_group =
      move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP); //For joint control
  geometry_msgs::PoseStamped current_pose;
 // Pose in ROS is implemented using geometry_msgs::PoseStamped, google what is the type of this msg
  current_pose = move_group.getCurrentPose(); /* Retrieving the information about the
  current position and orientation of the end effector*/
  ros::Rate loop_rate(50); //Frequency
  while (ros::ok()){
	std_msgs::Float64MultiArray coord_msg;
	coord_msg.data.resize(2);    //for x and y coordinates
	current_pose = move_group.getCurrentPose();
	coord_msg.data[0] = current_pose.pose.position.x;    //x-coordinate
	coord_msg.data[1] = current_pose.pose.position.y;    //y-coordinate
	pub.publish(coord_msg);
	ROS_INFO("%f; %f", coord_msg.data[0], coord_msg.data[1]);
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("Done");
  ros::shutdown();
  return 0;
}
