class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
    	index1 = 0
    	index2 = 0
    
    	median = (len(nums1) + len(nums2)) / 2
    	current = 0
    	value = [0, 0]
    	while index1 < len(nums1) or index2 < len(nums2):
    		if current == median:
    			break
    		if index1 == len(nums1):
    			value[0] = nums2[index2]
    			index2 += 1
    		elif index2 == len(nums2):
    			value[0] = nums1[index1]
    			index1 += 1
    		else:
    			if nums1[index1] <= nums2[index2]:
    				value[0] = nums1[index1]
    				index1 += 1
    			else:
    				value[0] = nums2[index2]
    				index2 += 1
    
    		current += 1
    
    
    	if (len(nums1) + len(nums2)) % 2 == 1:
    		if index1 == len(nums1):
    			value[0] = nums2[index2]
    			index2 += 1
    		elif index2 == len(nums2):
    			value[0] = nums1[index1]
    			index1 += 1
    		else:
    			if nums1[index1] <= nums2[index2]:
    				value[0] = nums1[index1]
    				index1 += 1
    			else:
    				value[0] = nums2[index2]
    				index2 += 1
    		return value[0]
    
    	else:
    		if index1 == len(nums1):
    			value[1] = nums2[index2]
    			index2 += 1
    		elif index2 == len(nums2):
    			value[1] = nums1[index1]
    			index1 += 1
    		else:
    			if nums1[index1] <= nums2[index2]:
    				value[1] = nums1[index1]
    				index1 += 1
    			else:
    				value[1] = nums2[index2]
    				index2 += 1
    		return (value[0] + value[1]) / 2.0
            