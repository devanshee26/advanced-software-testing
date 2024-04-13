package sysc5105.multiKnapsack;

// import static org.junit.jupiter.api.Assertions.assertThrows;
// import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
// import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class CP_BaseBlockWithErrorBlocks {
    Helper helper;
        public CP_BaseBlockWithErrorBlocks() {
                helper = new Helper();
        }

	@Test
	public void baseblock_with_errors_test1() {
            int[] capacity = {10,15,-20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {2};
            expected[2] = new int[] {4};
            expected[3] = new int[] {};
            assertTrue(helper.compareExpectedWithActualResults(16, expected, result));
	}

        @Test
        public void baseblock_with_errors_test2() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {-7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {2};
            expected[2] = new int[] {1};
            expected[3] = new int[] {4};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
        public void baseblock_with_errors_test3() {
            int[] capacity = {10,15,-20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,-7}, {6, -8}, {14, -5}, {11, -8}, {7, -6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {};
            expected[2] = new int[] {};
            expected[3] = new int[] {};
            assertTrue(helper.compareExpectedWithActualResults(0, expected, result));
	}
        
        @Test
        public void baseblock_with_errors_test4() {
            int[] capacity = {10,15,-20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,-8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {4};
            expected[3] = new int[] {};
            assertTrue(helper.compareExpectedWithActualResults(15, expected, result));
	}

        @Test
        public void baseblock_with_errors_test5() {
            int[] capacity = {10,15,-20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6, -8}, {14, -5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {4};
            expected[3] = new int[] {};
            assertTrue(helper.compareExpectedWithActualResults(15, expected, result));
	}
}
