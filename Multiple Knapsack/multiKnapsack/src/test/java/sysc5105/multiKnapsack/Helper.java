package sysc5105.multiKnapsack;
import java.util.ArrayList;
import java.util.LinkedList;

public class Helper {
    public MultipleKnapsack buildKnapsack(int[] capacity) {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack;
        for (int i = 0; i < capacity.length; i++) {
            knapsack = new Knapsack(capacity[i], "knapsack"+(i+1));            
            knapsacks.addKnapsack(knapsack);
        }
        return knapsacks;
    }
    public LinkedList<KnapsackItem> buildKnapsackItems(int [][] itemValues) {
        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item;
        for (int i = 0; i < itemValues.length; i++) {
            item = new KnapsackItem(itemValues[i][0], itemValues[i][1], "item"+(i+1));
            items.add(item);
        }
        return items;
    }

    public boolean compareExpectedWithActualResults(int value, int [][] expected, MultipleKnapsack actual) {

        if (value != actual.getValue()) {
            return false;
        }
        LinkedList<Knapsack> actualKnapsacks = actual.getKnapsacks();
        LinkedList<KnapsackItem> actualItems;
        ArrayList<String> expectedStrings = new ArrayList<>();
        ArrayList<String> actualStrings = new ArrayList<>();
        for (int i = 1; i < expected.length; i++) {
            for (int j = 0; j < expected[i].length; j++) {
                expectedStrings.add("item" + expected[i][j]);
            }
        }
        for (Knapsack knapsack : actualKnapsacks) {
            actualItems = knapsack.getItems();
            for (KnapsackItem item : actualItems) {
                actualStrings.add(item.getName());
            }
        }
        if (expectedStrings.size() != actualStrings.size()) {
            return false;
        }
        boolean allPresent = true;
        for (String aString : actualStrings) {
            if(!(expectedStrings.contains(aString))) {
                allPresent = false;
                break;
            }
        }
        return allPresent;

        // for (int i = 1; i < expected.length; i++) {
        //     k = null;
        //     for (Knapsack knapsack : actualKnapsacks) {
        //         if(knapsack.getName().equals("knapsack"+i)) {
        //             k = knapsack;
        //         }                
        //     }
        //     if(k==null) {
        //         return false;
        //     }
        //     actualItems = k.getItems();
        //     if (expected[i].length != actualItems.size()) {
        //         return false;
        //     }
        //     for (KnapsackItem item : actualItems) {
        //         String itemName = item.getName();
        //         boolean found = false;
        //         for (int j = 0; j < expected[i].length; j++) {
        //             if (("item"+(expected[i][j])).equals(itemName)) {
        //                 found = true;
        //             }
        //         }
        //         if (!found) {
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
}