const mergeKLists = (lists: Array<ListNode | null>): ListNode | null =>{
    let n = lists.length; 
    if(n === 0)
         return null;
     while(n > 1)
     {
         for(let i = 0; i < Math.floor(n/2); i++)
             lists[i] = merge_two_lists(lists[i], lists[n - i - 1]);
         n = Math.floor((n + 1) / 2);
     }
     return lists[0];
 };
 const merge_two_lists = (list1: ListNode | null, list2: ListNode | null): ListNode | null => {
     const head: ListNode = new ListNode(); 
     let curr = head;
     while(list1 && list2)
     {
         if(list1.val < list2.val)
         {
             curr.next = list1;
             list1 = list1.next;
         }
         else
         {
             curr.next = list2;
             list2 = list2.next;
         }
         curr = curr.next;
     }
     curr.next = list1 || list2;
     
     return head.next;
 };