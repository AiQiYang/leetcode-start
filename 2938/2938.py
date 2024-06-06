import unittest

class Solution:
    def minimumSteps(self, s: str) -> int:
        steps = count1 = 0
        for c in s:
            if c == '1':
                count1 += 1
            else:
                steps += count1
        return steps

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_minimumSteps(self):
        self.assertEqual(self.solution.minimumSteps("1111"), 0)
        self.assertEqual(self.solution.minimumSteps("0110"), 2)
        self.assertEqual(self.solution.minimumSteps("0101"), 1)
        self.assertEqual(self.solution.minimumSteps("101"), 1)

if __name__ == '__main__':
    unittest.main()