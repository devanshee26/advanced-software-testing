package sysc5105.multiKnapsack.Coverage_Analysis.MT.MetamorphicRelation4;
import sysc5105.multiKnapsack.*;

// import static org.junit.jupiter.api.Assertions.assertThrows;
// import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
// import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class MetamorphicRelation4_8 {
    Helper helper;
        public MetamorphicRelation4_8() {
                helper = new Helper();
        }

        @Test
	public void mutation_r4_test1() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = { {9,7}, {6,8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {4};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}

        @Test
	public void mutation_r4_test2() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {0, 30}, {6,8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1,2};
            expected[2] = new int[] {3};
            expected[3] = new int[] {5};
            assertTrue(helper.compareExpectedWithActualResults(53, expected, result));
	}

        @Test
	public void mutation_r4_test3() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {0, 25}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2,3};
            expected[3] = new int[] {5};
            assertTrue(helper.compareExpectedWithActualResults(48, expected, result));
	}

        @Test
	public void mutation_r4_test4() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {0, 15}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2,4};
            expected[3] = new int[] {5};
            assertTrue(helper.compareExpectedWithActualResults(38, expected, result));
	}

        @Test
	public void mutation_r4_test5() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {0, 20}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {4,5};
            assertTrue(helper.compareExpectedWithActualResults(43, expected, result));
	}

        @Test
	public void mutation_r4_test6() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {7,6}, {0, 20}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {4,6};
            assertTrue(helper.compareExpectedWithActualResults(43, expected, result));
	}

        @Test
	public void mutation_r4_test7() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {0, 200}, {6,8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1,2};
            expected[2] = new int[] {3};
            expected[3] = new int[] {5};
            assertTrue(helper.compareExpectedWithActualResults(223, expected, result));
	}

        @Test
	public void mutation_r4_test8() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,7}, {6,8}, {14,5}, {11,8}, {7,6}, {0, 90} };
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {1};
            expected[2] = new int[] {2};
            expected[3] = new int[] {4,6};
            assertTrue(helper.compareExpectedWithActualResults(113, expected, result));
	}
}
