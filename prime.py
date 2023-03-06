BIG_NUM:int=10000#10,000
nums:list[int] = [i for i in range(2,BIG_NUM)]

n:int = 0 #index of nums
add:bool = True
while n<len(nums):
    for i in range(nums[0],BIG_NUM//2):
        a:int = nums[n]*i

        try:
            index:int = nums.index(a)
            del nums[index]
            add=False
        except ValueError:
            pass
    if add:
        n+=1
    else:
        add=True

print(nums)

#2m29s