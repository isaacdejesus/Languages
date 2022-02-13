alist = [1, 2, 3, 3, 3, 4, 5]
#alist = [2,2]
def removeDuplicates(nums):
    arr_size = len(nums) -1
    for i in range(0, arr_size):
        if(i >= arr_size or arr_size ==0):
            break
        icount = nums.count(nums[i])
        while(icount > 2):
            nums.pop(i + 1)
            arr_size-=1
            icount-=1
            if(i >= arr_size or arr_size ==0):
                break
    return len(nums)


#print(removeDuplicates(alist))
removeDuplicates(alist)
for i in range(len(alist)):
    print(alist[i])

