import java.util.Stack;
import java.util.ArrayDeque;

public class MinStack {
    ArrayDeque<Integer> s1, s2;
    int min;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        s1 = new ArrayDeque<>();
        s2 = new ArrayDeque<>();
        min = Integer.MAX_VALUE;
    }

    public void push(int x) {
        s1.push(x);
        min = Math.min(min, x);
        s2.push(min);
    }

    public void pop() {
        s1.pop();
        s2.pop();
        if (!s2.isEmpty())
            min = s2.element();
        else
            min = Integer.MAX_VALUE;
    }

    public int top() {
        return s1.element();
    }

    public int getMin() {
        return min;
    }
}