import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import PoseStamped
from cv_bridge import CvBridge
import cv2
import numpy as np

class AriaVisionNode(Node):
    def __init__(self):
        super().__init__('aria_vision')
        self.subscription = self.create_subscription(Image, '/camera/image_raw', self.image_callback, 10)
        self.publisher = self.create_publisher(PoseStamped, '/detected_object', 10)
        self.bridge = CvBridge()
        self.aruco_dict = cv2.aruco.Dictionary_get(cv2.aruco.DICT_4X4_50)

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        
        corners, ids, _ = cv2.aruco.detectMarkers(frame, self.aruco_dict)
        
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower_red = np.array([0, 120, 70])
        upper_red = np.array([10, 255, 255])
        mask = cv2.inRange(hsv, lower_red, upper_red)
        
        

def main():
    rclpy.init()
    rclpy.spin(AriaVisionNode())
