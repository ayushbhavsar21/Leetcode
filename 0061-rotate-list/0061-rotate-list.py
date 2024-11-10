# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 0:
            return head

        
        size = 1
        ptr = head
        while ptr.next:
            ptr = ptr.next
            size += 1

        
        k = k % size
        k2 = size - k

        
        ptr.next = head

        
        while k2 > 0:
            ptr = ptr.next
            k2 -= 1

        
        new_head = ptr.next
        ptr.next = None

        return new_head
