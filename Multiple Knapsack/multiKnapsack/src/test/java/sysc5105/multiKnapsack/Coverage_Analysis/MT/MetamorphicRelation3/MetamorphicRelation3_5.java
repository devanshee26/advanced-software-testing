package sysc5105.multiKnapsack.Coverage_Analysis.MT.MetamorphicRelation3;
import sysc5105.multiKnapsack.*;

// import static org.junit.jupiter.api.Assertions.assertThrows;
// import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
// import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class MetamorphicRelation3_5 {
    Helper helper;
        public MetamorphicRelation3_5() {
                helper = new Helper();
        }

	@Test
	public void mutation_r3_test1() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {4};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
	public void mutation_r3_test2() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{6,8}, {9,7}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {4};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
	public void mutation_r3_test3() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{14,5}, {9,7}, {6,8}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {2};
            expected[2] = new int[] {3};
            expected[3] = new int[] {4};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
	public void mutation_r3_test4() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{11,8}, {9,7}, {6,8}, {14,5}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {3};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
	public void mutation_r3_test5() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = { {7,6}, {9,7}, {6,8}, {14,5}, {11,8} };
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
            //result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {3};
            expected[2] = new int[] {2};
            expected[3] = new int[] {5};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}
}
