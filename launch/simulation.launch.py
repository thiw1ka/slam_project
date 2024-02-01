import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import DeclareLaunchArgument


from ament_index_python import get_package_share_directory

def generate_launch_description():
    # trutlebot_arg = DeclareLaunchArgument( 'TURTLEBOT3_MODEL', default_value='burger' )
    config = os.path.join(
        get_package_share_directory('slam_sim'),
        'config',
        'params.yaml'
        )

    simulation = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('turtlebot3_gazebo'),'launch'),
            '/turtlebot3_house.launch.py']),launch_arguments={}.items()
        )
    #empty_world.launch.py

    slamsim_node = Node(
            package='slam_sim',
            # namespace='slam_sim',
            executable='slam_sim_node',
            name='lidarscan_modification_node',
            output='screen'
        )
    
    visulizer = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(
            get_package_share_directory('slam_sim'),'rviz')+'/rviz1.rviz']
    )
    # print("rviz path: "+ os.path.join(get_package_share_directory('slam_sim'),'rviz')+'/rviz1.rviz')

    return LaunchDescription([
            SetEnvironmentVariable(name='TURTLEBOT3_MODEL', value='burger'),
            simulation,
            visulizer,
            slamsim_node,
    ])