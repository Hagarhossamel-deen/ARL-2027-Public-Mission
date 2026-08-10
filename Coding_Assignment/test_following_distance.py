import unittest
from Question import monitor_following_distance

class TestFollowingDistance(unittest.TestCase):
    def test_safe_driving(self):
        distances = [30.0, 35.0, 30.0]
        speeds = [50.0, 50.0, 50.0]
        self.assertEqual(monitor_following_distance(distances, speeds), (0, 30.0, 0))

    def test_constant_tailgating(self):
        distances = [20.0, 20.0, 20.0]
        speeds = [50.0, 50.0, 50.0]
        self.assertEqual(monitor_following_distance(distances, speeds), (3, 20.0, 1))

    def test_multiple_incidents(self):
        distances = [30.0, 20.0, 30.0, 15.0]
        speeds = [50.0, 50.0, 50.0, 50.0]
        self.assertEqual(monitor_following_distance(distances, speeds), (2, 15.0, 2))
        
    def test_speed_changes(self):
        distances = [20.0, 20.0, 20.0]
        speeds = [30.0, 50.0, 30.0]
        self.assertEqual(monitor_following_distance(distances, speeds), (1, 20.0, 1))

    def test_empty_lists(self):
        self.assertEqual(monitor_following_distance([], []), (0, 0.0, 0))

    def test_exact_safe_distance(self):
        distances = [25.0, 25.0]
        speeds = [50.0, 50.0]
        self.assertEqual(monitor_following_distance(distances, speeds), (0, 25.0, 0))

    def test_zero_speed(self):
        distances = [10.0, 0.0]
        speeds = [0.0, 0.0]
        self.assertEqual(monitor_following_distance(distances, speeds), (0, 0.0, 0))

if __name__ == '__main__':
    unittest.main()
