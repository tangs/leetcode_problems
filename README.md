# LeetCode problems with cpp. 

[![License](https://img.shields.io/badge/license-MIT%2FApache-blue.svg)](https://github.com/tangs/leetcode_problems#license)
[![CI](https://github.com/tangs/leetcode_problems/workflows/macOS/badge.svg)](https://github.com/tangs/leetcode_problems/actions)
[![CI](https://github.com/tangs/leetcode_problems/workflows/Linux/badge.svg)](https://github.com/tangs/leetcode_problems/actions)
[![CI](https://github.com/tangs/leetcode_problems/workflows/Windows/badge.svg)](https://github.com/tangs/leetcode_problems/actions)

## problem 907

### test
ab m xy

m
mx
my

bm
bmx
bmy

abm
abmx
abmy

### left

|  3 |  1 | 2 | 4 | 1 | stack   |
|---:|---:|--:|--:|--:|:--------|
| -1 |    |   |   |   | 0       |
| -1 | -1 |   |   |   | 0, 1    |
| -1 | -1 | 1 |   |   | 0, 1, 2 |
| -1 | -1 | 1 | 2 |   | 1, 2, 3 |
| -1 | -1 | 1 | 2 | 1 | 1, 5    |

### right

| 3 | 1 | 2 | 4 | 1 | stack   |
|--:|--:|--:|--:|--:|:--------|
|   |   |   |   | 5 | 4       |
|   |   |   | 4 | 5 | 4, 3    |
|   |   | 4 | 4 | 5 | 4, 2    |
|   | 4 | 4 | 4 | 5 | 4, 1    |
| 1 | 5 | 4 | 4 | 5 | 4, 1, 0 |


## problem 1670

### head stack

## problem 828
ABA
A   1
AB  2
ABA 2
B   1
BA  2
A   1
