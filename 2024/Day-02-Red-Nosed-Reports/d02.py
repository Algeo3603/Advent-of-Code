import numpy as np
# Part 1
safe = 0
with open("input.txt") as file:
    for report in file.read().splitlines():
        nums = list(map(int, report.split()))
        diff = np.diff(nums)
        if (min(diff) > 0 or max(diff) < 0) and min(abs(diff)) >= 1 and max(abs(diff)) <= 3:
            safe += 1
print(safe)

# Part 2
safe = 0
with open("input.txt") as file:
    for report in file.read().splitlines():
        nums = list(map(int, report.split()))
        for i in range(len(nums)):
            num = np.delete(nums, i)
            diff = np.diff(num)
            if (min(diff) > 0 or max(diff) < 0) and min(abs(diff)) >= 1 and max(abs(diff)) <= 3:
                safe += 1
                break
print(safe)
