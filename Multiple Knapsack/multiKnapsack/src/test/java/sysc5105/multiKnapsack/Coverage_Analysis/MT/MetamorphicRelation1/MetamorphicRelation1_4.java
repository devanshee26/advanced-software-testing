package sysc5105.multiKnapsack.Coverage_Analysis.MT.MetamorphicRelation1;
import sysc5105.multiKnapsack.*;

// import static org.junit.jupiter.api.Assertions.assertThrows;
// import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
// import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class MetamorphicRelation1_4 {
    Helper helper;
        public MetamorphicRelation1_4() {
                helper = new Helper();
        }

	@Test
	public void mutation_r1_test1() {
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
	public void mutation_r1_test2() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,14}, {6,16}, {14,10}, {11,16}, {7,12}};
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
            assertTrue(helper.compareExpectedWithActualResults(46, expected, result));
	}

        @Test
	public void mutation_r1_test3() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,21}, {6,24}, {14,15}, {11,24}, {7,18}};
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
            assertTrue(helper.compareExpectedWithActualResults(69, expected, result));
	}

        @Test
	public void mutation_r1_test4() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{9,28}, {6,32}, {14,20}, {11,32}, {7,24}};
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
            assertTrue(helper.compareExpectedWithActualResults(92, expected, result));
	}
}
