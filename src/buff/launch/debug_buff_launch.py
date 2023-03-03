import os
import launch
from pathlib import Path
import launch_ros.actions
from launch_ros.utilities import to_parameters_list

from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def load_launch_parameters(context_name, path):
    param_list = to_parameters_list(launch.LaunchContext(), [Path(path)])
    parameters = []  # type: List[rclpy.parameter.Parameter]

    for param in param_list:
        if not param.name.startswith('/' + context_name + '.ros__parameters.'):
            continue
        name = param.name.replace('/' + context_name + '.ros__parameters.', '')
        parameters.append({name: param.value})
    return parameters

def generate_launch_description():
    camera_container = ComposableNodeContainer(
        node_name='camera_container',
        node_namespace='',
        package='rclcpp_components',
        node_executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='camera_file',
                plugin='camera::FileCamera',
                name='camera',
            ),
        ],
        output='screen',
    )
    decsion_container = ComposableNodeContainer(
        node_name='decsion_container',
        node_namespace='',
        package='rclcpp_components',
        node_executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='decsion_maker',
                plugin='decsion::DecsionMaker',
                name='decsion',
            ),
            ComposableNode(
                package='gimbal_controller',
                plugin='gimbal::GimbalController',
                name='gimbal',
            )
        ],
        output='screen',
    )

    return launch.LaunchDescription([
        camera_container,
        decsion_container,
    ])
