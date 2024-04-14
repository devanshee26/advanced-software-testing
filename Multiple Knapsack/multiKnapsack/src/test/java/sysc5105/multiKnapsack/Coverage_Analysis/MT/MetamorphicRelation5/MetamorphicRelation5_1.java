package sysc5105.multiKnapsack.Coverage_Analysis.MT.MetamorphicRelation5;
import sysc5105.multiKnapsack.*;

// import static org.junit.jupiter.api.Assertions.assertThrows;
// import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
// import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class MetamorphicRelation5_1 {
    Helper helper;
        public MetamorphicRelation5_1() {
                helper = new Helper();
        }

        @Test
	public void mutation_r5_test1() {
            int[] capacity = {10,15,20};
    
            MultipleKnapsack knapsacks = helper.buildKnapsack(capacity);
    
            // {weight, value}
            int[][] itemValues = {{25, 100}, {9,7}, {6,8}, {14,5}, {11,8}, {7,6}};
            LinkedList<KnapsackItem> items = helper.buildKnapsackItems(itemValues);
    
    
            knapsacks.greedyMultipleKnapsack(items);
            knapsacks.calculateValue();
            MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        //     result.printResult();
            
            int expected[][] = new int[capacity.length+1][];
            expected[0] = new int[]{};
            expected[1] = new int[] {2};
            expected[2] = new int[] {3};
            expected[3] = new int[] {5};
            assertTrue(helper.compareExpectedWithActualResults(23, expected, result));
	}
}
