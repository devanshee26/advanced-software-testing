package sysc5105.multiKnapsack.Coverage_Analysis.CP.EachBlockWithoutErrorBlocks;
import sysc5105.multiKnapsack.*;

// import static org.junit.jupiter.api.Assertions.assertThrows;
// import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
// import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class EachBlockWithoutErrorBlocks3 {
    Helper helper;
        public EachBlockWithoutErrorBlocks3() {
                helper = new Helper();
        }

	@Test
	public void eachblock_test1() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {7,0}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {2, 5};
            expected[2] = new int[] {4};
            expected[3] = new int[] {1};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
	public void eachblock_test2() {
            int[] capacity = {1};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{0,7}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            assertTrue(helper.compareExpectedWithActualResults(7, expected, result));
	}
    
        @Test
	public void eachblock_test3() {
            int[] capacity = {10,15,11};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{1,0}, {11,0}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1,2};
            expected[2] = new int[] {};
            expected[3] = new int[] {};
            assertTrue(helper.compareExpectedWithActualResults(0, expected, result));
	}

        
}
