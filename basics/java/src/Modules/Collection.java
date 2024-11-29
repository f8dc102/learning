import java.util.ArrayList;
import java.util.Vector;
import java.util.List;
import java.util.Scanner;

public class Collection {
  public Collection(Scanner userInput) {
    Lists lists = new Lists(userInput);
    Lists.ArrayLists arrayList = lists.new ArrayLists();
    Lists.LinkedLists linkedList = lists.new LinkedLists();
    Lists.Vectors vector = lists.new Vectors();

    // Sample ArrayList
    arrayList.ArrayListExample();

    System.out.println("Collection constructor");
  }
}

/**
 * List (Collection)
 *
 * Implementations
 * - ArrayList
 * - LinkedList
 * - Vector
 *
 * Characteristics
 * - Managed by Index
 * - Duplicates are allowed
 *
 * Major Methods
 * Add Elements
 * - boolean add(E e)
 * - void add(int index, E element)
 * - set(int index, E element)
 *
 * Search Elements
 * - boolean contains(Object o)
 * - boolean isEmpty()
 * - int size()
 * - E get(int index)
 *
 * Remove Elements
 * - E remove(int index)
 * - boolean remove(Object o)
 * - void clear()
 */
class Lists {
  /**
   * Constructor
   */
  public Lists(Scanner userInput) {
    System.out.println("List constructor");
  }

  /**
   * ArrayList
   */
  class ArrayLists {
    public ArrayLists() {
      System.out.println("ArrayLists constructor");
    }

    /**
     * Save to ArrayList
     *
     * @return void
     */
    public void ArrayListExample() {
      ArrayList<String> list = new ArrayList<>();

      list.add("Hello");
      list.add("World");

      System.out.println(list);
    }
  }

  /**
   * LinkedList
   */
  class LinkedLists {
    public LinkedLists() {
      System.out.println("LinkedLists constructor");
    }

    public void LinkedListExample() {
      List<String> list = new ArrayList<String>();

      list.add("MILK");
      list.add("BREAD");
      list.add("BUTTER");

      System.out.println(list);
      list.add(0, "APPLE");

      System.out.println(list);
      list.set(2, "GRAPE");

      System.out.println(list);
      list.remove(1);

      System.out.println(list);
    }
  }

  /**
   * Vector
   */
  class Vectors {
    public Vectors() {
      System.out.println("Vectors constructor");
    }

    public void VectorExample() {
      Vector<Integer> v = new Vector<Integer>();

      v.add(5);
      v.add(4);
      v.add(-1);

      v.add(2, 100);

      System.out.println("벡터내의 요소 객체 수 : " + v.size());
      System.out.println("벡터의 현재 용량 : " + v.capacity());

      for (int i = 0; i < v.size(); i++) {
        System.out.print(v.get(i) + " ");
      }

      System.out.println();

      int sum = 0;
      for (int i = 0; i < v.size(); i++) {
        int n = v.elementAt(i);
        sum += n;
      }

      System.out.println("벡터에 있는 정수 합 : " + sum);
    }
  }
}
