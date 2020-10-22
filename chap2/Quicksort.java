import java.util.Random;
import java.util.Arrays;

interface Cmp {
    int cmp(Object x, Object y);
}

// Int_cmp: compare integers
class Icmp implements Cmp {
    public int cmp(Object o1, Object o2)
    {
        int i1 = ((Integer) o1).intValue();
        int i2 = ((Integer) o2).intValue();
        if (i1 < i2)
            return -1;
        else if (i1 == i2)
            return 0;
        else 
            return 1;
    }
}

class Strcmp implements Cmp {
    public int cmp(Object o1, Object o2)
    {
        String s1 = (String) o1;
        String s2 = (String) o2;
        return s1.compareTo(s2);
    }
}

public class Quicksort {
    static void sort(Object[] v, int left, int right, Cmp cmp)
    {
        int i, last;
        if (left >= right)  // nothing to do
            return;
        swap(v, left, rand(left, right));  // pivot on random number
        last = left;
        for (i = left+1; i <= right; i++) {
            if (cmp.cmp(v[i], v[left]) < 0)
                swap(v, ++last, i);
    }
    swap(v, left, last);
    sort(v, left, last - 1, cmp);
    sort(v, last + 1, right, cmp);
    }

    static Random rgen = new Random();

    private static int rand(int left, int right) {
        return left + Math.abs(rgen.nextInt()) % (right - left + 1);
    }

    static void swap(Object[] v, int i, int j) {
        Object temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    public static void main(String[] args) {
        Integer[] arr = {3, 1, 5, 8, 2, 4, 0};
        Quicksort.sort(arr, 0, arr.length - 1, new Icmp());
        System.out.println(Arrays.toString(arr));
    }
}
