You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y. You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Solution->

Use the greedy approach. Use a priority queue to store all elements in sticks, where the minimum element is polled from the priority queue each time. While the priority queue contains at least 2 elements, poll 2 elements, calculate the sum, add the sum to the cost, and offer the sum to the priority queue. Repeat the process until the priority queue only contains 1 element. Then return the cost.


class Solution {
    public int connectSticks(int[] sticks) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<Integer>();
        for (int stick : sticks)
            priorityQueue.offer(stick);
        int cost = 0;
        while (priorityQueue.size() > 1) {
            int stick1 = priorityQueue.poll();
            int stick2 = priorityQueue.poll();
            int sum = stick1 + stick2;
            cost += sum;
            priorityQueue.offer(sum);
        }
        return cost;
    }
}