from typing import List
from collections import deque
import unittest

class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        deq = deque()
        for i, skill in enumerate(skills):
            deq.append((skill, i))
        
        
        count = 0
        index = 1
        
        while count < k:
            x, xi = deq.popleft()
            y, yi = deq.popleft()
            index += 1
            if index > len(skills):
                deq.appendleft((x, xi))
                break
            elif x > y:
                deq.appendleft((x, xi))
                deq.append((y, yi))
                count += 1
            else:
                deq.appendleft((y, yi))
                deq.append((x, xi))
                count = 1

        _, resi = deq.popleft()
        return resi

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_case_1(self):
        skills = [4, 2, 6, 3, 9]
        k = 2
        expected = 2
        self.assertEqual(self.solution.findWinningPlayer(skills, k), expected)

if __name__ == '__main__':
    unittest.main()
