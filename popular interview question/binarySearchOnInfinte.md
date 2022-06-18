Make a seprate case for the 0th index and start from index=1 and each time multiply it by 2 search for the element is you encounter a case where current element - greater than the desired element then you will get a Bounded region in which 2 things are for sure that :

The element at ( i / 2 )th index is smaller than the desired element.
The element at ( i ) is greater than the desired element
In such case break the infinte loop and apply binary search 



