from setuptools import setup

package_name = 'python_learn_ros2'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='subham',
    maintainer_email='subham@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "first_python_node_2 = python_learn_ros2.first_python_file:main",
            "second_py_node = python_learn_ros2.second_python_file_oop:main",
            "robot_news_station = python_learn_ros2.publisher_1_python:main",
            "smartphone = python_learn_ros2.subscriber_1_python:main",
            "add_two_ints_server = python_learn_ros2.service_server_1:main",
            "add_two_ints_no_oop = python_learn_ros2.service_client_no_oop:main",
            "robot_status_publisher = python_learn_ros2.robot_status_publisher:main"
        ],
    },
)
