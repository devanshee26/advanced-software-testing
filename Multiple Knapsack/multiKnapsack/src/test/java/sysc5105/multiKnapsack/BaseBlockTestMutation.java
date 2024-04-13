package sysc5105.multiKnapsack;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.LinkedList;

import org.junit.jupiter.api.Test;

public class BaseBlockTestMutation {
	
	// K3 C2 I5 V3 W4 VW3 IV2 IW2
	@Test
	public void test_baseBlock() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(9, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, 6, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // Item 3 should not be included
        assertEquals(29, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item2, selectedItems.get(0));
        	} else if (k.getName().equals(knapsack2.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item4, selectedItems.get(0));
            } else if (k.getName().equals(knapsack3.getName())) {
        		assertEquals(2, selectedItems.size());
        		assertTrue(selectedItems.contains(item1));
        		assertTrue(selectedItems.contains(item5));
            		
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}
	
	// K1 C2 I5 V3 W4 VW3 IV2 IW2
	@Test
	public void test_noKnapsacks() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(9, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, 6, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // No items selected
        assertEquals(0, result.getValue());
        // No knapsacks in result
        assertEquals(0, result.getKnapsacks().size());
	}
	
	// K2 C2 I5 V3 W4 VW3 IV2 IW2
	@Test
	public void test_singleKnapsack() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(9, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, 6, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // Item 2 should be selected
        assertEquals(8, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item2, selectedItems.get(0));	
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}
	
	// K3 C1 I5 V3 W4 VW3 IV2 IW2
	@Test
	public void test_noCapacity() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(0, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(-10, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(0, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 5, "item3"); 
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(9, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, 6, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // No items selected
        assertEquals(0, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		assertEquals(0, selectedItems.size());
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}
	
	// K3 C2 I1 V3 W4 VW3 IV2 IW2
	@Test
	public void test_noItems() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();

        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        assertEquals(0, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		assertEquals(0, selectedItems.size());
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}
	
	// K3 C2 I2 V3 W4 VW3 IV2 IW2
	@Test
	public void test_singleItem() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        assertEquals(7, result.getValue());
        
        int numberSelectedItems = 0;
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		numberSelectedItems += selectedItems.size();
            } else {
            	fail("Unknown Knapsack");
            }
        }
        assertEquals(1, numberSelectedItems);
	}
	
	// K3 C2 I3 V3 W4 VW3 IV2 IW2
	@Test
	public void test_fewerItemsThanKnapsacks() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 8, "item2");
        items.add(item2);

        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // All items selected
        assertEquals(15, result.getValue());
        
        int numberSelectedItems = 0;
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		numberSelectedItems += selectedItems.size();
            } else {
            	fail("Unknown Knapsack");
            }
        }
        assertEquals(2, numberSelectedItems);
	}

	// K3 C2 I4 V3 W4 VW3 IV2 IW2
	@Test
	public void test_equalItemsToKnapsacks() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 5, "item3"); 
        items.add(item3);

        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // All items selected
        assertEquals(20, result.getValue());
        
        int numberSelectedItems = 0;
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		numberSelectedItems += selectedItems.size();
            } else {
            	fail("Unknown Knapsack");
            }
        }
        assertEquals(3, numberSelectedItems);
	}

	// K3 C2 I5 V1 W4 VW3 IV2 IW2
	@Test
	public void test_noValues() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 0, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, -5, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 0, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(9, -10, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, -3, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // Not item 4
        assertEquals(-8, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item1, selectedItems.get(0));
        	} else if (k.getName().equals(knapsack2.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item3, selectedItems.get(0));
            } else if (k.getName().equals(knapsack3.getName())) {
        		assertEquals(2, selectedItems.size());
        		assertTrue(selectedItems.contains(item2));
        		assertTrue(selectedItems.contains(item5));
            		
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}

	// K3 C2 I5 V2 W4 VW3 IV2 IW2
	@Test
	public void test_allEqualValues() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(9, 5, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, 5, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(14, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(9, 5, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, 5, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // Not item 3
        assertEquals(20, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item2, selectedItems.get(0));
        	} else if (k.getName().equals(knapsack2.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item5, selectedItems.get(0));
            } else if (k.getName().equals(knapsack3.getName())) {
        		assertEquals(2, selectedItems.size());
        		assertTrue(selectedItems.contains(item1));
        		assertTrue(selectedItems.contains(item4));
            		
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}

	// K3 C2 I5 V3 W1 VW3 IV2 IW2
	@Test
	public void test_noWeights() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(0, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(-5, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(-20, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(-2, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(0, 6, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // All items selected
        assertEquals(34, result.getValue());
        
        int numberSelectedItems = 0;
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		numberSelectedItems += selectedItems.size();
            } else {
            	fail("Unknown Knapsack");
            }
        }
        assertEquals(5, numberSelectedItems);
	}

	// K3 C2 I4 V3 W2 VW3 IV2 IW2
	@Test
	public void test_weightsEachEqualToUniqueCapacity() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(10, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(15, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(20, 5, "item3");
        items.add(item3);

        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // All items selected
        assertEquals(15, result.getValue());
        
        int numberSelectedItems = 0;
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		numberSelectedItems += selectedItems.size();
            } else {
            	fail("Unknown Knapsack");
            }
        }
        assertEquals(2, numberSelectedItems);
	}

	// K3 C2 I5 V3 W3 VW3 IV2 IW2
	@Test
	public void test_itemsTooHeavy() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(21, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(26, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(25, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(23, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(37, 6, "item5");
        items.add(item5);


        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
        MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
        
        // No items selected
        assertEquals(0, result.getValue());
        
        int numberSelectedItems = 0;
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName()) || k.getName().equals(knapsack3.getName())) {
        		numberSelectedItems += selectedItems.size();
            } else {
            	fail("Unknown Knapsack");
            }
        }
        assertEquals(0, numberSelectedItems);
	}

	// K3 C2 I5 V3 W4 VW1 IV2 IW2
	@Test
	public void test_itemValuePropToWeight() {
	    MultipleKnapsack knapsacks = new MultipleKnapsack();
	    Knapsack knapsack1 = new Knapsack(10, "knapsack1");
	    knapsacks.addKnapsack(knapsack1);
	    Knapsack knapsack2 = new Knapsack(15, "knapsack2");
	    knapsacks.addKnapsack(knapsack2);
	    Knapsack knapsack3 = new Knapsack(20, "knapsack3");
	    knapsacks.addKnapsack(knapsack3);
	
	    LinkedList<KnapsackItem> items = new LinkedList<>();
	    KnapsackItem item1 = new KnapsackItem(9, 9, "item1");
	    items.add(item1);
	    KnapsackItem item2 = new KnapsackItem(7, 7, "item2");
	    items.add(item2);
	    KnapsackItem item3 = new KnapsackItem(14, 14, "item3");
	    items.add(item3);
	    KnapsackItem item4 = new KnapsackItem(12, 12, "item4");
	    items.add(item4);
	    KnapsackItem item5 = new KnapsackItem(15, 15, "item5");
	    items.add(item5);
	
	
	    knapsacks.greedyMultipleKnapsack(items);
	    knapsacks.calculateValue();
	    MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
	    
	    // Item 3 should not be included
	    assertEquals(38, result.getValue());
	    
	    for (Knapsack k: result.getKnapsacks()) {
	    	LinkedList<KnapsackItem> selectedItems = k.getItems();
	    	if (k.getName().equals(knapsack1.getName())) {
	    		assertEquals(1, selectedItems.size());
	    		assertEquals(item1, selectedItems.get(0));
	    	} else if (k.getName().equals(knapsack2.getName())) {
	    		assertEquals(1, selectedItems.size());
	    		assertEquals(item3, selectedItems.get(0));
	        } else if (k.getName().equals(knapsack3.getName())) {
	    		assertEquals(1, selectedItems.size());
	    		assertTrue(selectedItems.contains(item5));
	        		
	        } else {
	        	fail("Unknown Knapsack");
	        }
	    }
	}

	// K3 C2 I5 V3 W4 VW2 IV2 IW2
	@Test
	public void test_itemValueInverselyPropToWeight() {
	    MultipleKnapsack knapsacks = new MultipleKnapsack();
	    Knapsack knapsack1 = new Knapsack(10, "knapsack1");
	    knapsacks.addKnapsack(knapsack1);
	    Knapsack knapsack2 = new Knapsack(15, "knapsack2");
	    knapsacks.addKnapsack(knapsack2);
	    Knapsack knapsack3 = new Knapsack(20, "knapsack3");
	    knapsacks.addKnapsack(knapsack3);
	
	    LinkedList<KnapsackItem> items = new LinkedList<>();
	    KnapsackItem item1 = new KnapsackItem(9, 7, "item1");
	    items.add(item1);
	    KnapsackItem item2 = new KnapsackItem(7, 9, "item2");
	    items.add(item2);
	    KnapsackItem item3 = new KnapsackItem(14, 2, "item3");
	    items.add(item3);
	    KnapsackItem item4 = new KnapsackItem(12, 4, "item4");
	    items.add(item4);
	    KnapsackItem item5 = new KnapsackItem(15, 1, "item5");
	    items.add(item5);
		
	    knapsacks.greedyMultipleKnapsack(items);
	    knapsacks.calculateValue();
	    MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);
	    
	    // Item 5 should not be included
	    assertEquals(20, result.getValue());
	    
	    for (Knapsack k: result.getKnapsacks()) {
	    	LinkedList<KnapsackItem> selectedItems = k.getItems();
	    	if (k.getName().equals(knapsack1.getName())) {
	    		assertEquals(1, selectedItems.size());
	    		assertEquals(item2, selectedItems.get(0));
	    	} else if (k.getName().equals(knapsack2.getName())) {
	    		assertEquals(1, selectedItems.size());
	    		assertEquals(item1, selectedItems.get(0));
	        } else if (k.getName().equals(knapsack3.getName())) {
	    		assertEquals(1, selectedItems.size());
	    		assertTrue(selectedItems.contains(item4));
	        		
	        } else {
	        	fail("Unknown Knapsack");
	        }
	    }
	}

	// K3 C2 I5 V3 W4 VW3 IV1 IW2
	@Test
	public void test_cumulativeItemValueMoreThanMaxInt() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(20, "knapsack3");
        knapsacks.addKnapsack(knapsack3);

        int fifth = Integer.MAX_VALUE / 5;
        
        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(5, fifth + 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(7, fifth + 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(2, fifth + 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(4, fifth + 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(7, fifth + 6, "item5");
        items.add(item5);

        knapsacks.greedyMultipleKnapsack(items);
        knapsacks.calculateValue();
	}

	// K3 C2 I5 V3 W4 VW3 IV2 IW1
	@Test
	public void test_cumulativeItemWeightMoreThanMaxInt() {
        MultipleKnapsack knapsacks = new MultipleKnapsack();
        Knapsack knapsack1 = new Knapsack(10, "knapsack1");
        knapsacks.addKnapsack(knapsack1);
        Knapsack knapsack2 = new Knapsack(15, "knapsack2");
        knapsacks.addKnapsack(knapsack2);
        Knapsack knapsack3 = new Knapsack(Integer.MAX_VALUE - 1, "knapsack3");
        knapsacks.addKnapsack(knapsack3);
        
        LinkedList<KnapsackItem> items = new LinkedList<>();
        KnapsackItem item1 = new KnapsackItem(Integer.MAX_VALUE - 5, 7, "item1");
        items.add(item1);
        KnapsackItem item2 = new KnapsackItem(Integer.MAX_VALUE - 7, 8, "item2");
        items.add(item2);
        KnapsackItem item3 = new KnapsackItem(Integer.MAX_VALUE - 2, 5, "item3");
        items.add(item3);
        KnapsackItem item4 = new KnapsackItem(Integer.MAX_VALUE - 4, 8, "item4");
        items.add(item4);
        KnapsackItem item5 = new KnapsackItem(Integer.MAX_VALUE - 7, 15, "item5");
        items.add(item5);
		
	    knapsacks.greedyMultipleKnapsack(items);
	    knapsacks.calculateValue();
	    MultipleKnapsack result = knapsacks.neighborSearch(knapsacks);

        // Only item 5 selected
        assertEquals(15, result.getValue());
        
        for (Knapsack k: result.getKnapsacks()) {
        	LinkedList<KnapsackItem> selectedItems = k.getItems();
        	if (k.getName().equals(knapsack1.getName()) || k.getName().equals(knapsack2.getName())) {
        		assertEquals(0, selectedItems.size());
            } else if (k.getName().equals(knapsack3.getName())) {
        		assertEquals(1, selectedItems.size());
        		assertEquals(item5, selectedItems.get(0));
            } else {
            	fail("Unknown Knapsack");
            }
        }
	}
}
