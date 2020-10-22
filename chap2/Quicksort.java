/**
 * exercise 2-2: our java quicksort does a fair amount of type conversion
 * as some items are cast from their original type (like Integer) to Object
 * and back again. experiment with a version of Quicksort.sort that
 * uses the specific type to be sorted, to estimate what performance
 * penalty is incurred by type conversions.
 */

import java.util.Random;
import java.util.Arrays;


public class Quicksort {
    static int cmp(int a, int b)
    {
        if (a < b)
            return -1;
        else if (a == b)
            return 0;
        else
            return 1;
    }

    static void sort(int[] v, int left, int right)
    {
        int i, last;
        if (left >= right)  // nothing to do
            return;
        swap(v, left, rand(left, right));  // pivot on random number
        last = left;
        for (i = left+1; i <= right; i++) {
            if (cmp(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }
    swap(v, left, last);
    sort(v, left, last - 1);
    sort(v, last + 1, right);
    }

    static Random rgen = new Random();

    private static int rand(int left, int right) {
        return left + Math.abs(rgen.nextInt()) % (right - left + 1);
    }

    static void swap(int[] v, int i, int j) {
        int temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {87, 3, 12, 45, 0, 9, 23, 90};
        Quicksort.sort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }
}