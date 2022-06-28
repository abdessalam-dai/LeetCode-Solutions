def smallerNumbersThanCurrent(nums: list[int]) -> list[int]:
    numsSize = len(nums)
    result = [0 for i in range(numsSize)]
    for i in range(numsSize):
        for j in range(numsSize):
            if i != j and nums[j] < nums[i]:
                result[i] += 1

    return result


print(smallerNumbersThanCurrent([2, 4, 1, 6, 3, 8, 10]))
